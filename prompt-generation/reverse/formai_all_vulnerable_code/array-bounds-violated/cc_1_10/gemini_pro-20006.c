//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LEN 32
#define MAX_MSG_LEN 512

#define PORT 8080

typedef struct
{
    int sockfd;
    char name[MAX_NAME_LEN];
} Player;

Player players[MAX_PLAYERS];
int num_players = 0;

pthread_mutex_t players_lock;

void broadcast_message(const char *message, int sender)
{
    pthread_mutex_lock(&players_lock);
    for (int i = 0; i < num_players; i++)
    {
        if (players[i].sockfd != sender)
        {
            send(players[i].sockfd, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&players_lock);
}

void *handle_player(void *arg)
{
    int sockfd = *(int *)arg;
    free(arg);

    char buffer[MAX_MSG_LEN];
    while (1)
    {
        int recv_len = recv(sockfd, buffer, MAX_MSG_LEN, 0);
        if (recv_len <= 0)
        {
            printf("Player disconnected: %s\n", players[sockfd].name);
            pthread_mutex_lock(&players_lock);
            players[sockfd].sockfd = -1;
            num_players--;
            pthread_mutex_unlock(&players_lock);
            break;
        }

        buffer[recv_len] = '\0';

        broadcast_message(buffer, sockfd);
    }

    close(sockfd);

    return NULL;
}

int main()
{
    int sockfd, new_sockfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error opening socket");
        return EXIT_FAILURE;
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error on binding");
        return EXIT_FAILURE;
    }

    listen(sockfd, 5);

    pthread_mutex_init(&players_lock, NULL);

    while (1)
    {
        clilen = sizeof(cli_addr);
        new_sockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (new_sockfd < 0)
        {
            perror("Error on accept");
            continue;
        }

        char name[MAX_NAME_LEN];
        recv(new_sockfd, name, MAX_NAME_LEN, 0);

        pthread_mutex_lock(&players_lock);
        if (num_players >= MAX_PLAYERS)
        {
            send(new_sockfd, "Server full", 11, 0);
            close(new_sockfd);
            pthread_mutex_unlock(&players_lock);
            continue;
        }

        players[new_sockfd].sockfd = new_sockfd;
        strcpy(players[new_sockfd].name, name);
        num_players++;
        pthread_mutex_unlock(&players_lock);

        printf("Player connected: %s\n", name);

        pthread_t thread;
        int *sockfd_copy = malloc(sizeof(int));
        *sockfd_copy = new_sockfd;
        pthread_create(&thread, NULL, handle_player, sockfd_copy);
    }

    close(sockfd);

    return EXIT_SUCCESS;
}