//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host_info;
    char *host_name = "localhost";
    int port_number = 8080;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(0);
    }

    host_info = gethostbyname(host_name);
    if (host_info == NULL) {
        printf("Error getting host information\n");
        exit(0);
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy(host_info->h_addr, &server_addr.sin_addr, host_info->h_length);
    server_addr.sin_port = htons(port_number);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(0);
    }

    char message[100];
    while (1) {
        memset(message, 0, sizeof(message));
        printf("Enter message: ");
        fgets(message, sizeof(message), stdin);
        send(sockfd, message, strlen(message), 0);
        bzero(message, sizeof(message));
        recv(sockfd, message, sizeof(message), 0);
        printf("Server response: %s\n", message);
    }

    close(sockfd);
    return 0;
}