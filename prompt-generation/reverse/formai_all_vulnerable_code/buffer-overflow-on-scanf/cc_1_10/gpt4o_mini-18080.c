//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define MAX_PLAYERS 4
#define SPACE_SIZE 10
#define COMMAND_SIZE 50

typedef struct {
    int id;
    int x;
    int y;
    char name[20];
} Player;

Player players[MAX_PLAYERS];
int currentPlayerCount = 0;
pthread_mutex_t lock;

void initializeGame() {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].x = rand() % SPACE_SIZE;
        players[i].y = rand() % SPACE_SIZE;
    }
}

void *playerActions(void *arg) {
    int playerId = *(int *)arg;

    char command[COMMAND_SIZE];
    while (1) {
        printf("Player %s, enter your command (move <x> <y> or exit): ", players[playerId].name);
        fgets(command, COMMAND_SIZE, stdin);
        
        if (strncmp(command, "exit", 4) == 0) {
            printf("Player %s has exited the game.\n", players[playerId].name);
            break;
        }
        
        int newX, newY;
        if (sscanf(command, "move %d %d", &newX, &newY) == 2) {
            pthread_mutex_lock(&lock);
            if (newX >= 0 && newX < SPACE_SIZE && newY >= 0 && newY < SPACE_SIZE) {
                players[playerId].x = newX;
                players[playerId].y = newY;
                printf("Player %s moved to position (%d, %d).\n", players[playerId].name, newX, newY);
            } else {
                printf("Invalid move! Stay within the bounds of 0 to %d.\n", SPACE_SIZE - 1);
            }
            pthread_mutex_unlock(&lock);
        } else {
            printf("Invalid command! Use 'move <x> <y>' or 'exit'.\n");
        }
    }
    return NULL;
}

void displayPositions() {
    printf("\nCurrent positions of players:\n");
    for (int i = 0; i < currentPlayerCount; i++) {
        printf("Player %s is at position (%d, %d).\n", players[i].name, players[i].x, players[i].y);
    }
    printf("\n");
}

int main() {
    pthread_t threads[MAX_PLAYERS];
    int playerIDs[MAX_PLAYERS];
    srand(time(NULL));
    
    printf("Welcome to the Space Adventure Game!\n");

    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &currentPlayerCount);
    getchar(); // consume newline

    if (currentPlayerCount < 1 || currentPlayerCount > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    for (int i = 0; i < currentPlayerCount; i++) {
        printf("Enter name for Player %d: ", i + 1);
        fgets(players[i].name, sizeof(players[i].name), stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0; // remove newline

        playerIDs[i] = i;
    }

    initializeGame();
    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < currentPlayerCount; i++) {
        pthread_create(&threads[i], NULL, playerActions, &playerIDs[i]);
    }

    // Main Game Loop
    while (1) {
        displayPositions();
        sleep(3); // Refresh every 3 seconds
    }

    // Cleanup
    for (int i = 0; i < currentPlayerCount; i++) {
        pthread_join(threads[i], NULL);
    }
    
    pthread_mutex_destroy(&lock);
    return 0;
}