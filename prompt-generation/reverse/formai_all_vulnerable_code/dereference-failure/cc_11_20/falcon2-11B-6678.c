//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int server_fd, new_socket, port_num, chars_read, addr_size;
    struct sockaddr_in server_address, client_address;
    pid_t child_pid;
    char buffer[1024];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    port_num = atoi(argv[1]);

    if (port_num <= 0 || port_num > 65535) {
        fprintf(stderr, "Invalid port number.\n");
        return 1;
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0) {
        perror("socket");
        return 1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port_num);

    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind");
        return 1;
    }

    listen(server_fd, 5);

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&client_address, &addr_size);

        if (new_socket < 0) {
            perror("accept");
            continue;
        }

        printf("New client connected: %s\n", inet_ntoa(client_address.sin_addr));

        while (1) {
            chars_read = recv(new_socket, buffer, sizeof(buffer), 0);

            if (chars_read < 0) {
                perror("recv");
                close(new_socket);
                break;
            }

            if (chars_read == 0) {
                break;
            }

            printf("%s\n", buffer);

            send(new_socket, buffer, chars_read, 0);
        }

        close(new_socket);
    }

    close(server_fd);

    return 0;
}