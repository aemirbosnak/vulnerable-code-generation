//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080

typedef struct player {
    int id;
    int score;
    float latency;
} Player;

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    Player players[4];
    int player_count = 0;

    // Create listening socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Wait for players to connect
    while (player_count < 4) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Add new player
        Player p = {player_count, 0, 0};
        players[player_count] = p;
        player_count++;

        // Send player ID
        send(new_socket, &p.id, sizeof(p.id), 0);

        printf("Player %d connected from %s:%d\n", p.id, inet_ntoa(address.sin_addr), ntohs(address.sin_port));
    }

    // Game loop
    while (1) {
        // Update latency for each player
        for (int i = 0; i < player_count; i++) {
            clock_t start = clock();

            // Ping player
            if (send(new_socket, "PING", strlen("PING"), 0) == -1) {
                printf("Player %d disconnected\n", players[i].id);
                exit(EXIT_FAILURE);
            }

            // Receive pong
            if (recv(new_socket, buffer, 1024, 0) == -1) {
                printf("Player %d disconnected\n", players[i].id);
                exit(EXIT_FAILURE);
            }

            clock_t end = clock();
            float time_taken = ((float) (end - start)) / CLOCKS_PER_SEC;
            players[i].latency = time_taken;
        }

        // Print player stats
        printf("Player\tScore\tLatency\n");
        for (int i = 0; i < player_count; i++) {
            printf("%d\t%d\t%f\n", players[i].id, players[i].score, players[i].latency);
        }
        printf("\n");

        // Sleep for 5 seconds
        sleep(5);
    }

    return 0;
}