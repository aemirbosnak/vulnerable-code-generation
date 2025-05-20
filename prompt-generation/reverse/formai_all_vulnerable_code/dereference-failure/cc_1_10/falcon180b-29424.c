//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);
    server_addr.sin_port = htons(port_number);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received == -1) {
            printf("Error receiving data: %s\n", strerror(errno));
            close(sockfd);
            return 1;
        }

        if (bytes_received == 0) {
            printf("Server disconnected.\n");
            close(sockfd);
            return 0;
        }

        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    return 0;
}