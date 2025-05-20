//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void set_nonblocking(int sockfd) {
    int flags = fcntl(sockfd, F_GETFL, 0);
    fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
}

void smtp_send(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
}

void smtp_receive(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes;

    while ((bytes = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes] = '\0';
        printf("%s", buffer);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <SMTP Server> <Sender Email> <Recipient Email> <Message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *smtp_server = argv[1];
    const char *sender_email = argv[2];
    const char *recipient_email = argv[3];
    const char *message = argv[4];

    struct sockaddr_in server_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    struct hostent *host = gethostbyname(smtp_server);
    if (host == NULL) {
        fprintf(stderr, "Could not resolve host\n");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Could not connect to server");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    set_nonblocking(sockfd);
    smtp_receive(sockfd); // Receive server greeting

    smtp_send(sockfd, "HELO example.com\r\n");
    smtp_receive(sockfd); // Receive response

    char helo_command[BUFFER_SIZE];
    snprintf(helo_command, sizeof(helo_command), "MAIL FROM:<%s>\r\n", sender_email);
    smtp_send(sockfd, helo_command);
    smtp_receive(sockfd); // Receive response

    char rcpt_command[BUFFER_SIZE];
    snprintf(rcpt_command, sizeof(rcpt_command), "RCPT TO:<%s>\r\n", recipient_email);
    smtp_send(sockfd, rcpt_command);
    smtp_receive(sockfd); // Receive response

    smtp_send(sockfd, "DATA\r\n");
    smtp_receive(sockfd); // Receive response

    // Send the email message
    smtp_send(sockfd, message);
    smtp_send(sockfd, "\r\n.\r\n"); // End of data
    smtp_receive(sockfd); // Receive response

    smtp_send(sockfd, "QUIT\r\n");
    smtp_receive(sockfd); // Final response

    close(sockfd);
    return 0;
}