//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You find yourself in a dark, eerie forest.\n");
    printf("Do you want to go north, south, east, or west?\n");

    int direction = -1;
    while (direction == -1) {
        char input[20];
        scanf("%s", input);

        if (strcmp(input, "north") == 0) {
            direction = 0;
        } else if (strcmp(input, "south") == 0) {
            direction = 1;
        } else if (strcmp(input, "east") == 0) {
            direction = 2;
        } else if (strcmp(input, "west") == 0) {
            direction = 3;
        } else {
            printf("Invalid direction. Try again.\n");
        }
    }

    int rand_num = rand() % 10;
    if (rand_num < 5) {
        printf("You encounter a vicious wild animal!\n");
        printf("Do you want to fight or run?\n");

        char choice[10];
        scanf("%s", choice);

        if (strcmp(choice, "fight") == 0) {
            printf("You bravely fought the animal, but it proved too strong. You die.\n");
        } else if (strcmp(choice, "run") == 0) {
            printf("You managed to outrun the animal and survive for now.\n");
        } else {
            printf("Invalid choice. You freeze in fear as the animal attacks and kills you.\n");
        }
    } else {
        printf("You stumble upon a hidden treasure trove!\n");
        printf("Do you want to take some of the treasure or leave it untouched?\n");

        char choice[10];
        scanf("%s", choice);

        if (strcmp(choice, "take") == 0) {
            int treasure = rand() % 100 + 1;
            printf("You take %d gold coins from the treasure trove and continue your journey.\n", treasure);
        } else if (strcmp(choice, "leave") == 0) {
            printf("You decide it's best not to risk angering any potential guardians of the treasure. You continue your journey.\n");
        } else {
            printf("Invalid choice. You end up taking some of the treasure, but it was cursed and brings misfortune upon you for the rest of your life.\n");
        }
    }

    printf("You walk for a while until you reach the edge of the forest.\n");
    printf("Do you want to continue on your journey or return to the forest?\n");

    char choice[10];
    scanf("%s", choice);

    if (strcmp(choice, "continue") == 0) {
        printf("You continue your journey, full of hopeful anticipation for what lies ahead.\n");
    } else if (strcmp(choice, "return") == 0) {
        printf("You turn back and venture deeper into the forest once again.\n");
    } else {
        printf("Invalid choice. You are struck by a sudden bolt of lightning and perish.\n");
    }

    printf("Thank you for playing! Goodbye!\n");

    return 0;
}