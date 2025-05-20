//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    char user_input[100];
    int choice;
    int x, y;
    bool done = false;
    bool win = false;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer who has just entered a mysterious cave.\n");
    printf("There are four paths you can take:\n");
    printf("1. To the left\n");
    printf("2. To the right\n");
    printf("3. Forward\n");
    printf("4. Backwards\n");

    while (!done) {
        printf("Which path will you take? (1, 2, 3, or 4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You take the left path and find a treasure chest!\n");
                printf("You open the chest and find a shiny gold coin!\n");
                printf("Congratulations! You have won the game!\n");
                win = true;
                break;
            case 2:
                printf("You take the right path and encounter a fierce dragon!\n");
                printf("You try to fight the dragon, but it burns you to a crisp!\n");
                printf("Game over!\n");
                done = true;
                break;
            case 3:
                printf("You take the forward path and find yourself in a pit of quicksand!\n");
                printf("You try to escape, but you're stuck!\n");
                printf("Game over!\n");
                done = true;
                break;
            case 4:
                printf("You take the backwards path and find yourself back at the entrance of the cave!\n");
                printf("You decide to try another path and continue the adventure!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    if (win) {
        printf("Congratulations! You have won the game!\n");
    } else {
        printf("Game over!\n");
    }

    return 0;
}