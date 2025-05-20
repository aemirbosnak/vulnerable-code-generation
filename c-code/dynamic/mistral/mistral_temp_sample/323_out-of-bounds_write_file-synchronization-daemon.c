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
    int client_fd, addr_len, n;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if ((bind(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr))) == -1) {
        perror("bind failed");
        exit(1);
    }

    if ((listen(client_fd, 3)) == -1) {
        perror("listen failed");
        exit(1);
    }

    printf("Listening on port %d...\n", PORT);

    addr_len = sizeof(client_addr);
    while ((client_fd = accept(client_fd, (struct sockaddr *)&client_addr, &addr_len)) != -1) {
        printf("New connection received.\n");

        while ((n = read(client_fd, buffer, BUFFER_SIZE)) > 0) {
            buffer[n] = '\0';
            printf("Received data: %s\n", buffer);

            // Out of bounds write
            write(1, buffer + strlen(buffer), n);

            bzero(buffer, BUFFER_SIZE);
        }

        close(client_fd);
    }

    return 0;
}
