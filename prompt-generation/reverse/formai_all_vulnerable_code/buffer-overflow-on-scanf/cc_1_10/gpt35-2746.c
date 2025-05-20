//FormAI DATASET v1.0 Category: Smart home light control ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of rooms and lights
#define MAX_ROOMS 10
#define MAX_LIGHTS 5

// Function to turn on/off a light
void toggleLight(int room, int light, int status[MAX_ROOMS][MAX_LIGHTS]) {
    if (status[room][light] == 0) {
        status[room][light] = 1;
        printf("Room %d Light %d turned ON\n", room, light);
    } else {
        status[room][light] = 0;
        printf("Room %d Light %d turned OFF\n", room, light);
    }
}

// Function to print the status of all lights
void printStatus(int status[MAX_ROOMS][MAX_LIGHTS]) {
    printf("Current Status:\n");
    int i, j;
    for (i = 0; i < MAX_ROOMS; i++) {
        printf("Room %d: [", i+1);
        for (j = 0; j < MAX_LIGHTS; j++) {
            printf("%d ", status[i][j]);
        }
        printf("]\n");
    }
}

int main() {
    // Initialize the status array with all lights off
    int status[MAX_ROOMS][MAX_LIGHTS] = {{0}};

    // Menu for the user to interact with the program
    int option = 0;
    while (option != 4) {
        printf("\nEnter your choice:\n");
        printf("1. Turn on/off a light\n");
        printf("2. Print status of all lights\n");
        printf("3. Reset all lights\n");
        printf("4. Exit\n");

        scanf("%d", &option);

        if (option == 1) {
            int room, light;
            printf("Enter room number (1-%d): ", MAX_ROOMS);
            scanf("%d", &room);
            printf("Enter light number (1-%d): ", MAX_LIGHTS);
            scanf("%d", &light);
            toggleLight(room-1, light-1, status);
        } else if (option == 2) {
            printStatus(status);
        } else if (option == 3) {
            int i, j;
            for (i = 0; i < MAX_ROOMS; i++) {
                for (j = 0; j < MAX_LIGHTS; j++) {
                    status[i][j] = 0;
                }
            }
            printf("All lights reset to OFF\n");
        } else if (option != 4) {
            printf("Invalid option! Try again.\n");
        }
    }

    printf("Exiting program...\n");
    return 0;
}