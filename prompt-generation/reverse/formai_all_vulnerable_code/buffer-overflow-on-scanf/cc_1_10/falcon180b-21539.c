//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 25 // SMTP port
#define MAX_LINE 1024 // maximum length of a line

int main() {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_line[MAX_LINE];
    char recv_line[MAX_LINE];
    char *host;

    printf("Enter the SMTP server hostname: ");
    scanf("%s", host);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: socket() failed\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, host, &serv_addr.sin_addr); // convert hostname to IP address

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: connect() failed\n");
        exit(1);
    }

    printf("Connected to SMTP server\n");

    while (1) {
        printf("Enter command (quit to exit): ");
        fgets(send_line, MAX_LINE, stdin);
        if (strcmp(send_line, "quit\n") == 0) {
            break;
        }

        n = send(sockfd, send_line, strlen(send_line), 0);
        if (n < 0) {
            printf("Error: send() failed\n");
            exit(1);
        }

        n = recv(sockfd, recv_line, MAX_LINE, 0);
        if (n < 0) {
            printf("Error: recv() failed\n");
            exit(1);
        }

        printf("Server response: %s", recv_line);
    }

    close(sockfd);
    return 0;
}