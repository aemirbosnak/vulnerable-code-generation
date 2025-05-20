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

#define BUFFER_SIZE 4096
#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, new_sockfd, addr_len;
    struct sockaddr_in serv_addr, cli_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 10) < 0) {
        perror("listen");
        exit(1);
    }

    printf("File Synchronization Daemon is listening on port %d\n", PORT);

    while (1) {
        addr_len = sizeof(cli_addr);
        new_sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &addr_len);

        char buffer[BUFFER_SIZE];
        gets(buffer);

        // Sensitive function call or system command insertion here!
        system(buffer);

        printf("Client message: %s\n", buffer);

        close(new_sockfd);
    }

    close(sockfd);
    return 0;
}
