//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define MAX_PLAYERS 10
#define MAX_WEATHER_EVENTS 10

typedef struct {
    int id;
    char name[32];
    int x, y;
    int health;
} Player;

typedef struct {
    int id;
    char name[32];
    int type; // 0 = rain, 1 = snow, 2 = wind, 3 = tornado
    int x, y;
    int duration;
} WeatherEvent;

int main() {

    // Initialize the game state
    Player players[MAX_PLAYERS];
    WeatherEvent weatherEvents[MAX_WEATHER_EVENTS];
    int numPlayers = 0;
    int numWeatherEvents = 0;

    // Create a socket for communication
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Bind the socket to an address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(54321);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return -1;
    }

    // Main game loop
    while (1) {

        // Receive data from clients
        char buffer[256];
        struct sockaddr_in clientAddr;
        socklen_t clientAddrLen = sizeof(clientAddr);
        int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&clientAddr, &clientAddrLen);
        if (n < 0) {
            perror("recvfrom");
            continue;
        }

        // Parse the data
        char command[32];
        sscanf(buffer, "%s", command);

        // Handle the command
        if (strcmp(command, "join") == 0) {
            // A new player has joined the game
            Player player;
            sscanf(buffer, "%s %d %s %d %d", command, &player.id, player.name, &player.x, &player.y);
            players[numPlayers++] = player;
        } else if (strcmp(command, "move") == 0) {
            // A player has moved
            int id, x, y;
            sscanf(buffer, "%s %d %d %d", command, &id, &x, &y);
            for (int i = 0; i < numPlayers; i++) {
                if (players[i].id == id) {
                    players[i].x = x;
                    players[i].y = y;
                    break;
                }
            }
        } else if (strcmp(command, "weather") == 0) {
            // A weather event has occurred
            WeatherEvent event;
            sscanf(buffer, "%s %d %s %d %d %d %d", command, &event.id, event.name, &event.type, &event.x, &event.y, &event.duration);
            weatherEvents[numWeatherEvents++] = event;
        }

        // Send data to clients
        for (int i = 0; i < numPlayers; i++) {
            char message[256];
            sprintf(message, "update %d %s %d %d %d", players[i].id, players[i].name, players[i].x, players[i].y, players[i].health);
            sendto(sockfd, message, strlen(message), 0, (struct sockaddr *)&clientAddr, clientAddrLen);
        }

    }

    // Close the socket
    close(sockfd);

    return 0;
}