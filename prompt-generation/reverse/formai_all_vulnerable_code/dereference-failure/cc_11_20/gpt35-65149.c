//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF 1024

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <server_address> <server_port> <to_address> [<cc_address> ...]\n", argv[0]);
        return 1;
    }

    char *server_address = argv[1];
    int server_port = atoi(argv[2]);
    char *to_address = argv[3];
    char cc_addresses[MAX_BUF] = "";

    for (int i = 4; i < argc; i++) {
        strcat(cc_addresses, argv[i]);
        strcat(cc_addresses, ", ");
    }

    printf("Enter the subject: ");
    char subject[MAX_BUF];
    char subject_line[MAX_BUF];
    fgets(subject, MAX_BUF, stdin);
    subject[strcspn(subject, "\n")] = '\0';
    sprintf(subject_line, "Subject: %s\r\n", subject);

    printf("Enter the message: ");
    char message[MAX_BUF];
    fgets(message, MAX_BUF, stdin);
    message[strcspn(message, "\n")] = '\0';

    char from_address[MAX_BUF];
    printf("Enter your email address: ");
    fgets(from_address, MAX_BUF, stdin);
    from_address[strcspn(from_address, "\n")] = '\0';

    struct hostent *he;
    struct sockaddr_in server_addr;

    if ((he = gethostbyname(server_address)) == NULL) {
        perror("Error resolving hostname");
        return 2;
    }

    if ((server_addr.sin_addr.s_addr = inet_addr(he->h_name)) == (unsigned long) INADDR_NONE) {
        perror("Error resolving IP address");
        return 3;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        return 4;
    }

    char user_information[MAX_BUF];
    sprintf(user_information, "MAIL FROM: <%s>\r\n", from_address);
    write(sockfd, user_information, strlen(user_information));
    char buf[MAX_BUF];
    read(sockfd, buf, MAX_BUF);

    if (strncmp(buf, "250", 3) != 0) {
        printf("Error while sending from address\n");
        return 5;
    }

    char rcpt_information[MAX_BUF];
    sprintf(rcpt_information, "RCPT TO: <%s>\r\n", to_address);
    write(sockfd, rcpt_information, strlen(rcpt_information));
    read(sockfd, buf, MAX_BUF);

    if (strncmp(buf, "250", 3) != 0) {
        printf("Error while sending to address\n");
        return 6;
    }

    char cc_information[MAX_BUF];

    if (strcmp(cc_addresses, "") != 0) {
        sprintf(cc_information, "CC: <%s>\r\n", cc_addresses);
        write(sockfd, cc_information, strlen(cc_information));
        read(sockfd, buf, MAX_BUF);
    }

    char data_command[] = "DATA\r\n";
    write(sockfd, data_command, strlen(data_command));
    read(sockfd, buf, MAX_BUF);

    if (strncmp(buf, "354", 3) != 0) {
        printf("Error while sending data command\n");
        return 7;
    }

    char from_information[MAX_BUF];
    sprintf(from_information, "From: <%s>\r\n", from_address);
    char to_information[MAX_BUF];
    sprintf(to_information, "To: <%s>\r\n", to_address);

    char message_body[MAX_BUF];
    sprintf(message_body, "%s\r\n%s", subject_line, message);

    char end_of_message[] = "\r\n.\r\n";
    char quit_command[] = "QUIT\r\n";

    write(sockfd, from_information, strlen(from_information));
    read(sockfd, buf, MAX_BUF);

    write(sockfd, to_information, strlen(to_information));
    read(sockfd, buf, MAX_BUF);

    if (strcmp(cc_addresses, "") != 0) {
        write(sockfd, cc_information, strlen(cc_information));
        read(sockfd, buf, MAX_BUF);
    }

    write(sockfd, message_body, strlen(message_body));
    read(sockfd, buf, MAX_BUF);

    write(sockfd, end_of_message, strlen(end_of_message));
    read(sockfd, buf, MAX_BUF);

    write(sockfd, quit_command, strlen(quit_command));
    read(sockfd, buf, MAX_BUF);

    close(sockfd);
    return 0;
}