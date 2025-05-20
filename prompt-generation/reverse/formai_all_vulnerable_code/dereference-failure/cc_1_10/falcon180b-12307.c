//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 12345

int main(int argc, char *argv[]) {
    if (argc!= 3 && argc!= 4) {
        printf("Usage: %s <IP address> <port number> [<command>]\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);
    char *command = (argc == 4)? argv[3] : "";

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);
    server_addr.sin_addr.s_addr = inet_addr(ip_address);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    snprintf(buffer, BUFFER_SIZE, "%s", command);
    send(sockfd, buffer, strlen(buffer), 0);

    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);
    int bytes_received = recv(sockfd, response, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        printf("Error receiving response\n");
        close(sockfd);
        return 1;
    }

    printf("Response: %s\n", response);
    close(sockfd);
    return 0;
}