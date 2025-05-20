//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

struct client_info {
    int sockfd;
    char *name;
};

struct client_info *clients[100];
int num_clients = 0;

void *handle_client(void *arg) {
    struct client_info *client = (struct client_info *)arg;
    char buf[1024];
    while (1) {
        memset(buf, 0, sizeof(buf));
        int len = recv(client->sockfd, buf, sizeof(buf), 0);
        if (len <= 0) {
            break;
        }
        printf("%s: %s\n", client->name, buf);
        for (int i = 0; i < num_clients; i++) {
            if (clients[i] != client) {
                send(clients[i]->sockfd, buf, len, 0);
            }
        }
    }
    close(client->sockfd);
    for (int i = 0; i < num_clients; i++) {
        if (clients[i] == client) {
            clients[i] = clients[num_clients - 1];
            num_clients--;
            break;
        }
    }
    free(client->name);
    free(client);
    return NULL;
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        return 1;
    }

    listen(sockfd, 5);

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("Error on accept");
            continue;
        }

        char buf[1024];
        memset(buf, 0, sizeof(buf));
        int len = recv(newsockfd, buf, sizeof(buf), 0);
        if (len <= 0) {
            close(newsockfd);
            continue;
        }

        char *name = malloc(len + 1);
        memset(name, 0, len + 1);
        memcpy(name, buf, len);

        struct client_info *client = malloc(sizeof(struct client_info));
        client->sockfd = newsockfd;
        client->name = name;

        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, (void *)client);

        clients[num_clients] = client;
        num_clients++;
    }

    close(sockfd);
    return 0;
}