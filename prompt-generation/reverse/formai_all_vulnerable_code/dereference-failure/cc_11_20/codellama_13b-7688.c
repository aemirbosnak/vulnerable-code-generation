//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_MESSAGE_SIZE 1024
#define MAX_SUBSCRIBERS 100

struct mailing_list {
    char *name;
    char *email;
};

struct mailing_list subscribers[MAX_SUBSCRIBERS];

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <port> <message>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    char *message = argv[2];

    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(sock, 3) < 0) {
        perror("listen");
        return 1;
    }

    while (1) {
        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("accept");
            continue;
        }

        char buffer[MAX_MESSAGE_SIZE];
        memset(buffer, 0, MAX_MESSAGE_SIZE);

        if (read(client_sock, buffer, MAX_MESSAGE_SIZE) < 0) {
            perror("read");
            close(client_sock);
            continue;
        }

        char *name = strtok(buffer, " ");
        char *email = strtok(NULL, " ");

        if (name == NULL || email == NULL) {
            printf("Invalid input\n");
            close(client_sock);
            continue;
        }

        int i;
        for (i = 0; i < MAX_SUBSCRIBERS; i++) {
            if (subscribers[i].name == NULL) {
                break;
            }
        }

        if (i == MAX_SUBSCRIBERS) {
            printf("Maximum number of subscribers reached\n");
            close(client_sock);
            continue;
        }

        subscribers[i].name = name;
        subscribers[i].email = email;

        printf("Subscriber %s (%s) added\n", name, email);

        if (write(client_sock, "Subscribed successfully", 23) < 0) {
            perror("write");
        }

        close(client_sock);
    }

    return 0;
}