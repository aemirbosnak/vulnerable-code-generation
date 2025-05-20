//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;
    printf("Welcome to the Cryptic Adventure!\n");
    printf("You find yourself in a dark, mysterious forest.\n");
    printf("What will you do?\n");
    printf("1. Explore the forest.\n");
    printf("2. Find a way out.\n");
    scanf("%d", &choice);

    if (choice == 1) {
        int encounter;
        encounter = rand() % 3;
        switch (encounter) {
            case 0:
                printf("As you wander through the forest, you come across a strange, glowing mushroom.\n");
                printf("Do you eat it?\n");
                printf("1. Yes.\n");
                printf("2. No.\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("You feel a strange energy coursing through your veins.\n");
                } else {
                    printf("You decide not to risk eating the mysterious mushroom.\n");
                }
                break;
            case 1:
                printf("Suddenly, a pack of wolves appears, blocking your path.\n");
                printf("Do you fight them or run away?\n");
                printf("1. Fight.\n");
                printf("2. Run.\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("You engage in a fierce battle with the wolves.\n");
                } else {
                    printf("You flee from the wolves, narrowly escaping their jaws.\n");
                }
                break;
            case 2:
                printf("You stumble upon an ancient ruin hidden within the forest.\n");
                printf("Do you explore it?\n");
                printf("1. Yes.\n");
                printf("2. No.\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("As you explore the ruins, you discover a valuable treasure.\n");
                } else {
                    printf("You decide not to risk exploring the ruins.\n");
                }
                break;
        }
    } else if (choice == 2) {
        printf("You search for a way out of the forest.\n");
        int exit;
        exit = rand() % 2;
        if (exit == 0) {
            printf("You find a path that leads out of the forest.\n");
        } else {
            printf("You become lost and cannot find your way out.\n");
        }
    } else {
        printf("Invalid choice.\n");
    }
    return 0;
}