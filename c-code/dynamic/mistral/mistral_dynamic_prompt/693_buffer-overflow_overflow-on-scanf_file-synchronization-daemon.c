#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd, new_sockfd, numBytes;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    char host[32];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    printf("Listening on port %d...\n", PORT);

    while (1) {
        new_sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, NULL);
        numBytes = recv(new_sockfd, buffer, BUFFER_SIZE - 1, 0);
        if (numBytes < 0) {
            perror("ERROR reading from socket");
            close(new_sockfd);
            continue;
        }
        buffer[numBytes] = '\0';

        // Vulnerable section, buffer overflow on scanf
        sscanf(buffer, "%s", host);
        printf("Host: %s\n", host);

        // Rest of the code...
        close(new_sockfd);
    }

    return 0;
}
