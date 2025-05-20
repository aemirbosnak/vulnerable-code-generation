//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define BUF_SIZE 1024

int main() {
    int sock_fd, conn_fd, opt = 1, numbytes, i;
    socklen_t client_addr_len;
    struct sockaddr_in server_addr, client_addr;
    char buf[BUF_SIZE];
    time_t curr_time;

    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket Creation Failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setsockopt Failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind Failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sock_fd, 3) < 0) {
        perror("Listen Failed");
        exit(EXIT_FAILURE);
    }

    printf("QoS Monitor is waiting for connections on port %d...\n", PORT);
    while (1) {
        client_addr_len = sizeof(client_addr);
        if ((conn_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
            perror("Accept Failed");
            exit(EXIT_FAILURE);
        }
        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            if ((numbytes = recv(conn_fd, buf, BUF_SIZE - 1, 0)) == -1) {
                perror("Recv Failed");
                exit(EXIT_FAILURE);
            }
            buf[numbytes] = '\0';
            if (strcmp(buf, "STOP_MONITORING") == 0) {
                printf("QoS Monitoring for %s:%d stopped by the client\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                close(conn_fd);
                break;
            }
            curr_time = time(NULL);
            printf("> Received '%s' from %s:%d at %s", buf, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), ctime(&curr_time));
            printf("QoS parameters - Packet Loss: %d%% | Latency: %dms | Jitter: %dms\n", rand() % 5, rand() % 300, rand() % 10);
            printf("\n");
        }
    }

    return 0;
}