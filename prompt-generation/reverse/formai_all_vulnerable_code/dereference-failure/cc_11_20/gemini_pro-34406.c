//GEMINI-pro DATASET v1.0 Category: Password management ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

typedef struct {
    char username[128];
    char password[128];
} user;

typedef struct {
    int fd;
    user u;
} client;

int server_fd;
int num_clients;
client *clients;

void *handle_client(void *arg)
{
    client *c = (client *)arg;
    char buf[1024];
    int n;
    while ((n = read(c->fd, buf, sizeof(buf))) > 0) {
        buf[n] = '\0';
        if (strcmp(buf, "LOGIN") == 0) {
            char username[128], password[128];
            if (read(c->fd, username, sizeof(username)) <= 0) {
                break;
            }
            if (read(c->fd, password, sizeof(password)) <= 0) {
                break;
            }
            int found = 0;
            for (int i = 0; i < num_clients; i++) {
                if (strcmp(clients[i].u.username, username) == 0 &&
                    strcmp(clients[i].u.password, password) == 0) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                write(c->fd, "SUCCESS\n", 8);
            } else {
                write(c->fd, "FAIL\n", 5);
            }
        } else if (strcmp(buf, "ADD") == 0) {
            char username[128], password[128];
            if (read(c->fd, username, sizeof(username)) <= 0) {
                break;
            }
            if (read(c->fd, password, sizeof(password)) <= 0) {
                break;
            }
            int found = 0;
            for (int i = 0; i < num_clients; i++) {
                if (strcmp(clients[i].u.username, username) == 0) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                write(c->fd, "FAIL\n", 5);
            } else {
                user u;
                strcpy(u.username, username);
                strcpy(u.password, password);
                clients = realloc(clients, sizeof(client) * (num_clients + 1));
                clients[num_clients].fd = c->fd;
                clients[num_clients].u = u;
                num_clients++;
                write(c->fd, "SUCCESS\n", 8);
            }
        } else if (strcmp(buf, "DELETE") == 0) {
            char username[128];
            if (read(c->fd, username, sizeof(username)) <= 0) {
                break;
            }
            int found = 0;
            int index = -1;
            for (int i = 0; i < num_clients; i++) {
                if (strcmp(clients[i].u.username, username) == 0) {
                    found = 1;
                    index = i;
                    break;
                }
            }
            if (found) {
                for (int i = index; i < num_clients - 1; i++) {
                    clients[i] = clients[i + 1];
                }
                num_clients--;
                write(c->fd, "SUCCESS\n", 8);
            } else {
                write(c->fd, "FAIL\n", 5);
            }
        } else if (strcmp(buf, "LIST") == 0) {
            char buf[1024];
            int n = 0;
            for (int i = 0; i < num_clients; i++) {
                n += snprintf(buf + n, sizeof(buf) - n, "%s\n", clients[i].u.username);
            }
            write(c->fd, buf, n);
        }
    }
    close(c->fd);
    free(c);
    return NULL;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_fd, 10) == -1) {
        perror("listen");
        exit(1);
    }

    clients = malloc(sizeof(client) * 10);
    num_clients = 0;

    while (1) {
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd == -1) {
            perror("accept");
            continue;
        }
        client *c = malloc(sizeof(client));
        c->fd = client_fd;
        pthread_t t;
        if (pthread_create(&t, NULL, handle_client, c) != 0) {
            perror("pthread_create");
            close(client_fd);
            free(c);
            continue;
        }
        pthread_detach(t);
    }

    close(server_fd);
    free(clients);

    return 0;
}