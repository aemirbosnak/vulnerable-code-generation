//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int server_socket = 0;
    struct sockaddr_in server_addr;
    struct hostent *server_name;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    server_name = gethostbyname("localhost");
    if (server_name == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    bcopy((char *)server_name->h_addr, (char *)&server_addr.sin_addr.s_addr, server_name->h_length);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(server_socket, 5) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("accept");
            exit(1);
        }

        char buffer[1024];
        int num_bytes_read = 0;

        while ((num_bytes_read = recv(client_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
            buffer[num_bytes_read] = '\0';
            printf("Received: %s\n", buffer);

            num_bytes_read = send(client_socket, buffer, strlen(buffer), 0);
            if (num_bytes_read < 0) {
                perror("send");
                exit(1);
            }
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}