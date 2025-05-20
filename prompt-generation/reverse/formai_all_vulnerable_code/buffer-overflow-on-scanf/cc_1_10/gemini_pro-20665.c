//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 5555
#define SERVER_IP "127.0.0.1"

int main() {
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT);
    servaddr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    char buffer[1024];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        printf("Enter a message to send to the server: ");
        scanf("%s", buffer);

        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            perror("Send failed");
            exit(1);
        }

        memset(buffer, 0, sizeof(buffer));
        if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
            perror("Receive failed");
            exit(1);
        }

        printf("Message received from server: %s\n", buffer);
    }

    close(sockfd);

    return 0;
}