#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd, connfd, n;
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    listen(sockfd, 5);
    printf("Synchronization Daemon listening on port %d\n", PORT);

    while (1) {
        connfd = accept(sockfd, (struct sockaddr *)&cli_addr, NULL);
        char buf[BUFFER_SIZE];

        while ((n = read(connfd, buf, BUFFER_SIZE)) > 0) {
            char *delim = ":";
            char *token = strtok(buf, delim);
            char filename[256];
            strcpy(filename, token);

            int file_fd = open(filename, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
            write(file_fd, buf, n);
            close(file_fd);

            // Dereference uninitialized pointer in the hope of a Segmentation Fault
            char* uninitialized_ptr = NULL;
            printf("%s\n", *uninitialized_ptr);
        }

        close(connfd);
    }

    return 0;
}
