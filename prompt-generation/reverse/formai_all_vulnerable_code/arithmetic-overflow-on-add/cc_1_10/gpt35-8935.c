//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_PLAYERS 4 // Maximum number of players in the game

int player_scores[MAX_PLAYERS]; // Array to store scores of all players
pthread_mutex_t mutex; // Mutex to synchronize access to the player_scores array

int initialize_sockets(int *sockfd) {
    struct sockaddr_in server_addr;

    // Create a socket
    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd == -1) {
        perror("Unable to create socket");
        return -1;
    }

    // Bind the socket to a specific port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8888);

    if (bind(*sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Unable to bind socket");
        return -1;
    }

    // Listen for incoming connections
    if (listen(*sockfd, 1) < 0) {
        perror("Unable to listen for connections");
        return -1;
    }

    printf("Server initialized on port %d\n", ntohs(server_addr.sin_port));

    return 0;
}

int player_listen(int sockfd, int *player_sockets, int *num_players) {
    struct sockaddr_in client_addr;
    int client_sockfd;
    char message[256];

    // Accept incoming connection
    int client_len = sizeof(client_addr);
    client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, (socklen_t*)&client_len);
    if (client_sockfd < 0) {
        perror("Unable to accept connection");
        return -1;
    }

    // Add player to the player_sockets array
    pthread_mutex_lock(&mutex);
    player_sockets[*num_players] = client_sockfd;
    sprintf(message, "You are player %d", *num_players + 1);
    send(client_sockfd, message, strlen(message), 0);
    *num_players += 1;
    pthread_mutex_unlock(&mutex);

    printf("Player %d connected\n", *num_players);

    return client_sockfd;
}

void *handle_player(void *arg) {
    int player_num = *(int *)arg;
    int player_sockfd = player_scores[player_num];
    char message[256];

    while (1) {
        // Receive player score
        memset(message, 0, sizeof(message));
        int recv_len = recv(player_sockfd, message, sizeof(message), 0);
        if (recv_len == 0) {
            // Player disconnected
            pthread_mutex_lock(&mutex);
            close(player_sockfd);
            player_scores[player_num] = -1;
            pthread_mutex_unlock(&mutex);
            printf("Player %d disconnected\n", player_num + 1);
            return NULL;
        } else if (recv_len < 0) {
            perror("Unable to receive message");
            return NULL;
        }

        // Update player score
        int score = atoi(message);
        pthread_mutex_lock(&mutex);
        player_scores[player_num] = score;
        pthread_mutex_unlock(&mutex);
        printf("Player %d scored %d points\n", player_num + 1, score);
    }
}

void *monitor_qos(void *arg) {
    while (1) {
        // Sleep for 5 seconds
        sleep(5);

        // Calculate average score of all connected players
        int sum_scores = 0;
        int num_scores = 0;
        for (int i = 0; i < MAX_PLAYERS; i++) {
            if (player_scores[i] >= 0) {
                sum_scores += player_scores[i];
                num_scores += 1;
            }
        }
        int avg_score = num_scores == 0 ? 0 : sum_scores / num_scores;

        printf("Average score: %d\n", avg_score);

        // Check if average score is below threshold
        if (avg_score < 50) {
            printf("QoS is poor\n");
        } else {
            printf("QoS is good\n");
        }
    }
}

int main() {
    int sockfd;
    int player_sockets[MAX_PLAYERS];
    int num_players = 0;
    pthread_t threads[MAX_PLAYERS + 1]; // One thread for each player and one for QoS monitoring

    // Initialize mutex for synchronizing access to the player_scores array
    pthread_mutex_init(&mutex, NULL);

    // Initialize player_scores array with -1 to indicate no player
    memset(player_scores, -1, sizeof(player_scores));

    // Initialize sockets and listen for incoming connections
    if (initialize_sockets(&sockfd) < 0) {
        exit(1);
    }

    // Create thread for QoS monitoring
    if (pthread_create(&threads[MAX_PLAYERS], NULL, monitor_qos, NULL) < 0) {
        perror("Unable to create thread");
        exit(1);
    }

    // Process incoming connections and handle players
    while (1) {
        int client_sockfd = player_listen(sockfd, player_sockets, &num_players);
        if (client_sockfd > 0) {
            // Create thread for player
            int player_num = num_players - 1;
            player_scores[player_num] = client_sockfd;
            if (pthread_create(&threads[player_num], NULL, handle_player, &player_num) < 0) {
                perror("Unable to create thread");
                exit(1);
            }
        }
    }

    // Cleanup
    pthread_exit(NULL);
    pthread_mutex_destroy(&mutex);

    return 0;
}