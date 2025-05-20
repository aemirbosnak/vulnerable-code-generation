//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char** argv) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_BUFFER_SIZE];
    char user[50], pass[50];
    char command[100];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("POP3 Connected successfully.\n");

    /* Authenticate the user */
    printf("Username: ");
    scanf("%s", user);

    printf("Password: ");
    scanf("%s", pass);

    sprintf(command, "USER %s\r\n", user);

    n = write(sockfd, command, strlen(command));
    n = read(sockfd, buffer, MAX_BUFFER_SIZE);

    if (buffer[0] == '-') {
        printf("Authentication error: %s", buffer);
        exit(1);
    }

    sprintf(command, "PASS %s\r\n", pass);
    n = write(sockfd, command, strlen(command));
    n = read(sockfd, buffer, MAX_BUFFER_SIZE);

    if (buffer[0] == '-') {
        printf("Authentication error: %s", buffer);
        exit(1);
    }

    printf("Authentication successful.\n");

    /* List the emails */
    sprintf(command, "LIST\r\n");
    n = write(sockfd, command, strlen(command));
    printf("List of emails:\n");
    while (1) {
        n = read(sockfd, buffer, MAX_BUFFER_SIZE);
        if (buffer[0] == '.') break;
        printf("%s", buffer);
    }

    /* Read an email */
    int email_number;
    printf("Enter email number to read: ");
    scanf("%d", &email_number);

    sprintf(command, "RETR %d\r\n", email_number);
    n = write(sockfd, command, strlen(command));

    while (1) {
        n = read(sockfd, buffer, MAX_BUFFER_SIZE);
        if (buffer[0] == '-') {
            printf("Error: %s", buffer);
            exit(1);
        }
        if (buffer[0] == '.') break;
        printf("%s", buffer);
    }

    /* Quit session */
    sprintf(command, "QUIT\r\n");
    n = write(sockfd, command, strlen(command));

    printf("POP3 Session ended.\n");

    close(sockfd);

    return 0;
}