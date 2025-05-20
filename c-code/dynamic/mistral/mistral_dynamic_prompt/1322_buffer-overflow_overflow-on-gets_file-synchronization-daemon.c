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
    int sockfd, new_sockfd, client_sockfd, c, recv_len;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(sockfd, 10);
    printf("Listening on port %d...\n", PORT);

    while(1) {
        client_sockfd = accept(sockfd, (struct sockaddr*)&cli_addr, (socklen_t*)&recv_len);
        bzero(buffer, BUFFER_SIZE);

        recv_len = read(client_sockfd, buffer, BUFFER_SIZE);
        write(client_sockfd, buffer, recv_len);

        // Buffer overflow vulnerability here
        gets(buffer);
        printf("Received data from client: %s\n", buffer);

        close(client_sockfd);
    }

    return 0;
}
