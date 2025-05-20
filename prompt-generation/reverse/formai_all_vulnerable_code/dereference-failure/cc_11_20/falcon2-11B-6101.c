//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_CONNECTIONS 10
#define BUF_SIZE 256

int main(int argc, char *argv[]) {
    int server_fd, conn_fd, len, n;
    int client_socket[MAX_CONNECTIONS], i, j;
    socklen_t addrlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE], send_buffer[BUF_SIZE], recv_buffer[BUF_SIZE];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        return 1;
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(server_fd, MAX_CONNECTIONS) == -1) {
        perror("listen");
        return 1;
    }

    while (1) {
        conn_fd = accept(server_fd, (struct sockaddr *) &cli_addr, &addrlen);
        if (conn_fd == -1) {
            perror("accept");
            continue;
        }

        printf("New connection from %s\n", inet_ntoa(cli_addr.sin_addr));

        for (i = 0; i < MAX_CONNECTIONS; i++) {
            if (client_socket[i] == -1) {
                client_socket[i] = conn_fd;
                break;
            }
        }

        if (i == MAX_CONNECTIONS) {
            printf("Too many connections\n");
            continue;
        }

        send_buffer[0] = 'A';
        send_buffer[1] = 'B';
        send_buffer[2] = 'C';
        send_buffer[3] = 'D';
        send_buffer[4] = 'E';
        send_buffer[5] = 'F';
        send_buffer[6] = 'G';
        send_buffer[7] = 'H';
        send_buffer[8] = 'I';
        send_buffer[9] = 'J';
        send_buffer[10] = 'K';
        send_buffer[11] = 'L';
        send_buffer[12] = 'M';
        send_buffer[13] = 'N';
        send_buffer[14] = 'O';
        send_buffer[15] = 'P';
        send_buffer[16] = 'Q';
        send_buffer[17] = 'R';
        send_buffer[18] = 'S';
        send_buffer[19] = 'T';
        send_buffer[20] = 'U';
        send_buffer[21] = 'V';
        send_buffer[22] = 'W';
        send_buffer[23] = 'X';
        send_buffer[24] = 'Y';
        send_buffer[25] = 'Z';
        send_buffer[26] = '\n';
        send_buffer[27] = '\0';

        len = send(conn_fd, send_buffer, sizeof(send_buffer), 0);
        if (len < 0) {
            perror("send");
            close(conn_fd);
            continue;
        }

        printf("Sent: %s\n", send_buffer);

        while (1) {
            n = read(conn_fd, buffer, sizeof(buffer));
            if (n <= 0) {
                if (n == 0) {
                    printf("Client disconnected\n");
                    close(conn_fd);
                    break;
                } else {
                    perror("read");
                    close(conn_fd);
                    continue;
                }
            }

            printf("Received: %s\n", buffer);

            if (strcmp(buffer, "quit") == 0) {
                break;
            }

            printf("Sending back\n");
            send(conn_fd, buffer, strlen(buffer), 0);
        }

        printf("Closing connection to %s\n", inet_ntoa(cli_addr.sin_addr));
        close(conn_fd);
    }

    close(server_fd);

    return 0;
}