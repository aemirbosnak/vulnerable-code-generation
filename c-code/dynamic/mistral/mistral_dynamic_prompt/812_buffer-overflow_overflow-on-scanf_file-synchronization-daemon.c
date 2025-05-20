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

#define BUF_SIZE 2048
#define PORT 8888

int main(int argc, char *argv[]) {
    int server_fd, client_fd, c, addr_len;
    struct sockaddr_in address;
    char buffer[BUF_SIZE];

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if ((bind(server_fd, (struct sockaddr *)&address, sizeof(address))) != 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if ((listen(server_fd, 3)) != 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d\n", PORT);

    addr_len = sizeof(address);
    while ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addr_len))) {
        printf("New connection received\n");

        memset(buffer, 0, BUF_SIZE);
        scanf("%s", buffer); // <-- Buffer overflow point

        write(client_fd, buffer, strlen(buffer));
        close(client_fd);
    }

    return 0;
}
