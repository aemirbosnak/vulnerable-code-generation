//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10
#define PORT "8080"
#define QOS_THRESHOLD 80
#define QOS_INTERVAL 5

struct client {
    int sock;
    char ip[16];
};

void *monitor_qos(void *arg) {
    struct client *clients = (struct client *) arg;
    int i, bytes_received, qos;

    while (1) {
        sleep(QOS_INTERVAL);

        for (i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].sock!= -1) {
                bytes_received = recv(clients[i].sock, NULL, 0, MSG_PEEK);

                if (bytes_received > 0) {
                    qos = ((float) bytes_received / BUFFER_SIZE) * 100;

                    if (qos < QOS_THRESHOLD) {
                        printf("QoS for client %s is low (%d%% of buffer size).\n", clients[i].ip, qos);
                    }
                }
            }
        }
    }

    return NULL;
}

int main() {
    int server_sock, client_sock, addrlen, bytes_received, qos_thread;
    struct sockaddr_in server_addr, client_addr;
    struct client clients[MAX_CLIENTS];

    memset(clients, -1, sizeof(clients));

    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(PORT));

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket.\n");
        exit(1);
    }

    if (listen(server_sock, MAX_CLIENTS) == -1) {
        printf("Error listening on socket.\n");
        exit(1);
    }

    printf("Server listening on port %s...\n", PORT);

    while (1) {
        addrlen = sizeof(client_addr);
        if ((client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &addrlen))!= -1) {
            inet_ntop(AF_INET, &client_addr.sin_addr, clients[0].ip, sizeof(clients[0].ip));
            clients[0].sock = client_sock;

            printf("Client %s connected.\n", clients[0].ip);

            if (pthread_create(&qos_thread, NULL, monitor_qos, (void *) clients)!= 0) {
                printf("Error creating QoS thread.\n");
                exit(1);
            }
        }
    }

    return 0;
}