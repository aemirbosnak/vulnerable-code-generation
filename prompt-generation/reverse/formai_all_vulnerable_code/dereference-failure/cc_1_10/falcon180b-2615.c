//Falcon-180B DATASET v1.0 Category: Chat server ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <poll.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <pthread.h>

#define MAX_EVENTS 100
#define BUFFER_SIZE 1024

struct client {
    int sock;
    char ip[16];
    char name[32];
};

void *thread(void *arg) {
    struct client *client = (struct client *) arg;
    char buffer[BUFFER_SIZE];
    int bytes;

    while ((bytes = recv(client->sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes] = '\0';
        printf("%s: %s\n", client->name, buffer);
        send(client->sock, buffer, bytes, 0);
    }

    close(client->sock);
    free(client);
}

int main() {
    int listen_sock, epoll_fd;
    struct sockaddr_in server_addr;
    struct epoll_event events[MAX_EVENTS];

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);

    bind(listen_sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(listen_sock, 10);

    epoll_fd = epoll_create(10);
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listen_sock, &(struct epoll_event) {
       .events = EPOLLIN
    });

    while (1) {
        int n_events = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);

        for (int i = 0; i < n_events; i++) {
            if (events[i].data.fd == listen_sock) {
                struct sockaddr_in client_addr;
                socklen_t addr_len = sizeof(client_addr);

                int client_sock = accept(listen_sock, (struct sockaddr *) &client_addr, &addr_len);

                char host[16];
                char service[16];
                inet_ntop(AF_INET, &client_addr.sin_addr, host, sizeof(host));
                inet_ntop(AF_INET, &client_addr.sin_port, service, sizeof(service));

                printf("Connection from %s:%s\n", host, service);

                struct client *client = (struct client *) malloc(sizeof(struct client));
                client->sock = client_sock;
                strcpy(client->ip, host);

                pthread_t thread_id;
                pthread_create(&thread_id, NULL, thread, client);
            } else {
                char buffer[BUFFER_SIZE];
                int bytes;

                while ((bytes = recv(events[i].data.fd, buffer, BUFFER_SIZE, 0)) > 0) {
                    buffer[bytes] = '\0';
                    printf("%s: %s\n", events[i].data.ptr, buffer);
                }

                close(events[i].data.fd);
            }
        }
    }

    return 0;
}