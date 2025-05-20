//FormAI DATASET v1.0 Category: Networking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    int sock = 0, valread, new_socket, client_socket[30];
    struct sockaddr_in serv_addr;
    fd_set readfds;

    char *message = "Hello from server!";
    char buffer[1024] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sock, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {

        FD_ZERO(&readfds);

        FD_SET(sock, &readfds);

        int max_sd = sock;

        for (int i = 0; i < 30; i++) {

            int sd = client_socket[i];

            if (sd > 0)
                FD_SET(sd, &readfds);

            if (sd > max_sd)
                max_sd = sd;
        }

        if (select(max_sd + 1, &readfds, NULL, NULL, NULL) < 0) {
            perror("Select failed");
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(sock, &readfds)) {

            if ((new_socket = accept(sock, (struct sockaddr *)&serv_addr, (socklen_t*)&serv_addr)) < 0) {
                perror("Accept failed");
                exit(EXIT_FAILURE);
            }

            printf("New connection, socket fd is %d, IP is : %s, Port : %d\n", new_socket, inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

            for (int i = 0; i < 30; i++) {

                if (client_socket[i] == 0) {
                    client_socket[i] = new_socket;
                    break;
                }
            }
        }

        for (int i = 0; i < 30; i++) {

            int sd = client_socket[i];

            if (FD_ISSET(sd, &readfds)) {

                if ((valread = read(sd, buffer, 1024)) == 0) {

                    getpeername(sd, (struct sockaddr*)&serv_addr, (socklen_t*)&serv_addr);
                    printf("Host disconnected, socket fd is %d, IP is : %s, Port : %d\n", sd, inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

                    client_socket[i] = 0;

                } else {

                    buffer[valread] = '\0';
                    printf("Received message \"%s\" from client\n", buffer);
                    send(sd, message, strlen(message), 0);
                }
            }
        }
    }

    return 0;
}