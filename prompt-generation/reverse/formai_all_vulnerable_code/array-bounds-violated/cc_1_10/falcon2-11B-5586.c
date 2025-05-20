//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 5000

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <ip>\n", argv[0]);
        return 1;
    }

    int sockfd, portno;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        return 1;
    }

    portno = atoi(argv[1]);
    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        return 1;
    }

    listen(sockfd, 5);
    printf("Server is listening on port %d\n", portno);

    while (1) {
        int client_fd, numbytes;
        char buffer[BUFFER_SIZE];

        client_fd = accept(sockfd, (struct sockaddr *)NULL, NULL);
        if (client_fd < 0) {
            perror("accept failed");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

        while ((numbytes = recv(client_fd, buffer, BUFFER_SIZE, 0)) > 0) {
            buffer[numbytes] = '\0';
            printf("Received: %s\n", buffer);
        }

        printf("Connection closed\n");
        close(client_fd);
    }

    return 0;
}