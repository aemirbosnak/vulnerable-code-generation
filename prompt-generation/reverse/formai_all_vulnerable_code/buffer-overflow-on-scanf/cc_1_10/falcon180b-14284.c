//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function prototypes
void *gameLoop(void *arg);
void *userInput(void *arg);

// Global variables
int gameRunning = 1;
char userInputBuffer[256];
pthread_t gameThread;
pthread_t userInputThread;

// Game loop function
void *gameLoop(void *arg) {
    while (gameRunning) {
        printf("You are in a dark room. There is a door to your left and a door to your right. Which door do you choose?\n");
        scanf("%s", userInputBuffer);

        if (strcmp(userInputBuffer, "left") == 0) {
            printf("You open the door to your left and find a staircase leading up. Do you climb the staircase?\n");
        } else if (strcmp(userInputBuffer, "right") == 0) {
            printf("You open the door to your right and find a hallway. Do you walk down the hallway?\n");
        }

        fflush(stdout);
        pthread_join(userInputThread, NULL);
        userInputThread = pthread_create(&userInputThread, NULL, userInput, NULL);
    }

    return NULL;
}

// User input function
void *userInput(void *arg) {
    char input[256];

    while (gameRunning) {
        scanf("%s", input);

        if (strcmp(input, "yes") == 0) {
            printf("You continue your adventure...\n");
        } else if (strcmp(input, "no") == 0) {
            printf("You turn back and the adventure ends.\n");
            gameRunning = 0;
        } else {
            printf("Invalid input. Please try again.\n");
        }

        fflush(stdout);
    }

    return NULL;
}

int main() {
    pthread_create(&gameThread, NULL, gameLoop, NULL);
    pthread_create(&userInputThread, NULL, userInput, NULL);

    pthread_join(gameThread, NULL);
    pthread_join(userInputThread, NULL);

    return 0;
}