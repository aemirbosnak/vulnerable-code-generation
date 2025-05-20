//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char message[100];

    printf("Enter the IP address of the server: ");
    scanf("%s", argv[1]);
    printf("Enter the port number: ");
    scanf("%d", &server_addr.sin_port);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter message to send: ");
        scanf("%s", message);
        send(sockfd, message, strlen(message), 0);

        memset(message, 0, sizeof(message));
        if (recv(sockfd, message, sizeof(message), 0) <= 0) {
            printf("Disconnected from server\n");
            exit(1);
        }
        printf("Received message: %s\n", message);
    }

    close(sockfd);
    return 0;
}