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
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    bind(sock, (struct sockaddr *)&address, sizeof(address));
    listen(sock, 3);

    while (1) {
        int client_sock = accept(sock, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        char request[BUFFER_SIZE];
        recv(client_sock, request, BUFFER_SIZE, 0);

        int file_size = atoi(&request[7]);
        char *file_name = &request[11];
        char *file_content = malloc(file_size);

        recv(client_sock, file_content, file_size, 0);

        FILE *fp = fopen(file_name, "w");
        fwrite(file_content, file_size, 1, fp);
        fclose(fp);

        printf("File received: %s\n", file_name);

        free(file_content);
        close(client_sock);
    }

    return 0;
}
