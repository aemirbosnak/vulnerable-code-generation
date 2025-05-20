#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd, new_sockfd, addrlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        perror("ERROR on listening");
        exit(1);
    }

    addrlen = sizeof(cli_addr);
    new_sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &addrlen);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        read(new_sockfd, buffer, BUFFER_SIZE);
        write(0, buffer, strlen(buffer)); // Write to stdout for debugging purposes
        write(1, buffer, strlen(buffer) + 1); // Write to serial port (assuming fd 1 is serial port)
    }

    close(new_sockfd);
    close(sockfd);

    return 0;
}
