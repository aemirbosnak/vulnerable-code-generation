//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define MAX_PLAYERS 10
#define MAX_TASKS 5
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    int duration; // in milliseconds
} Task;

typedef struct {
    int playerId;
    Task tasks[MAX_TASKS];
    int taskCount;
} Player;

void* runTasks(void* arg) {
    Player* player = (Player*)arg;

    printf("Player %d has started optimizations...\n", player->playerId);
    
    for (int i = 0; i < player->taskCount; i++) {
        printf("Player %d is executing task: %s\n", player->playerId, player->tasks[i].name);
        usleep(player->tasks[i].duration * 1000); // simulate task duration
        printf("Player %d completed task: %s\n", player->playerId, player->tasks[i].name);
    }
    
    printf("Player %d has finished all tasks\n", player->playerId);
    return NULL;
}

void initializeTasks(Player* player, int playerId) {
    player->playerId = playerId;
    player->taskCount = rand() % MAX_TASKS + 1; // Random number of tasks

    for (int i = 0; i < player->taskCount; i++) {
        snprintf(player->tasks[i].name, TASK_NAME_LENGTH, "Task%d", i + 1);
        player->tasks[i].duration = (rand() % 500) + 100; // Random duration between 100ms and 600ms
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    int playerCount;
    printf("Enter number of players (1 to %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);

    if (playerCount < 1 || playerCount > MAX_PLAYERS) {
        fprintf(stderr, "Invalid number of players. Please enter a number between 1 and %d.\n", MAX_PLAYERS);
        return EXIT_FAILURE;
    }

    pthread_t threads[MAX_PLAYERS];
    Player players[MAX_PLAYERS];

    // Initialize and create player threads
    for (int i = 0; i < playerCount; i++) {
        initializeTasks(&players[i], i + 1);
        if (pthread_create(&threads[i], NULL, runTasks, (void*)&players[i]) != 0) {
            fprintf(stderr, "Error creating thread for player %d\n", i + 1);
            return EXIT_FAILURE;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < playerCount; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All players have completed their tasks successfully!\n");
    return EXIT_SUCCESS;
}