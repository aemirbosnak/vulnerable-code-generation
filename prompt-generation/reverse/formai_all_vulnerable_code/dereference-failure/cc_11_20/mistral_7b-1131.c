//MISTRAL-7B DATASET v1.0 Category: Chat server ; Style: puzzling
#define PORT 8080
#define MAXLINE 1024
#define WELCOME_MESSAGE "Welcome to the Mysterious Chat Room, stranger!\n"
#define INVALID_COMMAND "Invalid command! Try .help for assistance.\n"
#define USER_JOINED "A new user has joined the chat room!\n"
#define USER_LEFT "A user has left the chat room.\n"
#define USERS_LIST "Current users in the chat room:\n"
#define MESSAGE_FORMAT "%s: %s\n"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

struct user {
    char name[32];
    int sockfd;
};

int main() {
    int sockfd, new_sockfd, listenfd, valread;
    int opt = 1;
    int addrlen;
    char buffer[MAXLINE] = {0};
    char name[32] = {0};
    struct sockaddr_in address;
    int addrport;
    int numusers = 0;
    struct user *users = NULL;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 3);

    puts("Waiting for users to join...");

    while (1) {
        addrlen = sizeof(address);
        new_sockfd = accept(sockfd, (struct sockaddr *)&address, &addrlen);
        if (new_sockfd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        puts("New user connected");

        if (numusers >= 10) {
            send(new_sockfd, INVALID_COMMAND, strlen(INVALID_COMMAND), 0);
            close(new_sockfd);
            continue;
        }

        strcpy(name, recv(new_sockfd, name, 32, 0));

        for (int i = 0; i < numusers; ++i) {
            if (strcmp(users[i].name, name) == 0) {
                send(new_sockfd, INVALID_COMMAND, strlen(INVALID_COMMAND), 0);
                close(new_sockfd);
                continue;
            }
        }

        users = realloc(users, sizeof(struct user) * ++numusers);
        users[numusers - 1].sockfd = new_sockfd;
        strcpy(users[numusers - 1].name, name);

        puts(USER_JOINED);

        send(new_sockfd, WELCOME_MESSAGE, strlen(WELCOME_MESSAGE), 0);
        send(new_sockfd, USERS_LIST, strlen(USERS_LIST), 0);

        while (1) {
            valread = recv(new_sockfd, buffer, MAXLINE, 0);
            if (valread == 0) {
                puts("A user left");
                for (int i = 0; i < numusers; ++i) {
                    if (users[i].sockfd == new_sockfd) {
                        send(users[i].sockfd, USER_LEFT, strlen(USER_LEFT), 0);
                        --numusers;
                        close(users[i].sockfd);
                        users = realloc(users, sizeof(struct user) * --numusers);
                        break;
                    }
                }
                continue;
            }

            for (int i = 0; i < numusers; ++i) {
                if (users[i].sockfd != new_sockfd) {
                    sprintf(buffer, MESSAGE_FORMAT, users[i].name, buffer);
                    send(users[i].sockfd, buffer, strlen(buffer), 0);
                }
            }
        }
    }

    return 0;
}