#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void error_handler(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int client_socket, addr_len;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    if((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        error_handler("socket");

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    if(connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        error_handler("connect");

    while(1) {
        printf("Enter a message (input ending with '\0' to quit): ");
        fgets(buffer, sizeof(buffer), stdin);

        if(send(client_socket, buffer, strlen(buffer), 0) == -1)
            error_handler("send");
    }

    close(client_socket);
    return 0;
}
