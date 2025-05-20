//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

int main(int argc, char **argv) {
    int client_socket, server_socket, read_bytes;
    int yes = 1;
    int is_connected = 0;
    struct sockaddr_in server_address;
    struct hostent *server_host;
    char *url = argv[1];

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Socket error");
        exit(1);
    }

    server_host = gethostbyname(url);
    if (server_host == NULL) {
        fprintf(stderr, "Error: Invalid hostname.\n");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    bcopy((char *)server_host->h_addr, (char *)&server_address.sin_addr.s_addr, server_host->h_length);
    server_address.sin_port = htons(80); // Default port for HTTP

    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Connection error");
        exit(1);
    }

    if (send(client_socket, "GET ", 5, 0) == -1) {
        perror("Send error");
        exit(1);
    }

    if (send(client_socket, url, strlen(url), 0) == -1) {
        perror("Send error");
        exit(1);
    }

    if (send(client_socket, "\r\n", 2, 0) == -1) {
        perror("Send error");
        exit(1);
    }

    while (is_connected!= 1) {
        read_bytes = recv(client_socket, &is_connected, sizeof(is_connected), 0);
        if (read_bytes == -1) {
            perror("Recv error");
            exit(1);
        }

        if (read_bytes == 0) {
            printf("Connection closed by server.\n");
            exit(0);
        }
    }

    while (read_bytes > 0) {
        printf("%s", &is_connected);
        read_bytes = recv(client_socket, &is_connected, sizeof(is_connected), 0);
        if (read_bytes == -1) {
            perror("Recv error");
            exit(1);
        }
    }

    printf("\n");

    close(client_socket);
    return 0;
}