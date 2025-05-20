//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random seed

    printf("Welcome to the Haunted House Simulator!\n");

    int choice;
    int scare_chance = 0;
    int scream_count = 0;
    int ghost_location = rand() % 5 + 1;

    printf("You have entered the haunted house. Choose wisely...\n");
    printf("1. Go left\n");
    printf("2. Go right\n");
    printf("3. Go straight\n");
    printf("4. Check inventory\n");

    scanf("%d", &choice);

    while (choice != 4) {
        if (choice < 1 || choice > 3) {
            printf("Invalid choice. Choose again.\n");
            scanf("%d", &choice);
            continue;
        }

        scare_chance = rand() % 101;

        if (scare_chance < 30) {
            printf("You feel a cold presence behind you... Boo!!\n");
            scream_count++;
        }

        if (scream_count >= 3) {
            printf("You have screamed too much and attracted the ghost. It's game over.\n");
            return 0;
        }

        if (choice == ghost_location) {
            printf("You have encountered the ghost. It's game over.\n");
            return 0;
        }

        printf("You continue on...\n");
        printf("1. Go left\n");
        printf("2. Go right\n");
        printf("3. Go straight\n");
        printf("4. Check inventory\n");

        scanf("%d", &choice);
    }

    printf("You check your inventory and find a flashlight. Do you want to use it?\n");

    char use_flashlight;
    scanf(" %c", &use_flashlight);

    if (use_flashlight == 'y') {
        printf("You shine the flashlight and find a key. You can use it to escape the haunted house!\n");
        return 0;
    }

    printf("You choose not to use the flashlight... and are stuck in the haunted house forever.\n");
    return 0;
}