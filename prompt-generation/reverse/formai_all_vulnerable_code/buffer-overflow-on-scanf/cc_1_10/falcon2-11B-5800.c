//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char name[100];
    char* choice;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("What is your name? ");
    scanf("%s", name);

    printf("Hello %s, let's begin the adventure!\n", name);

    choice = "begin";
    while (strcmp(choice, "end")!= 0) {
        printf("You are in the middle of a dark forest. You see two paths ahead of you.\n");
        printf("Which path will you take? (left/right) ");
        scanf("%s", choice);

        if (strcmp(choice, "left") == 0) {
            printf("You have taken the left path and found a mysterious cave.\n");
            printf("Do you enter the cave? (yes/no) ");
            scanf("%s", choice);

            if (strcmp(choice, "yes") == 0) {
                printf("Congratulations, you have found the treasure!\n");
                printf("Game over.\n");
            } else {
                printf("You decide not to enter the cave.\n");
                printf("You continue on your journey...\n");
            }
        } else if (strcmp(choice, "right") == 0) {
            printf("You have taken the right path and encountered a dangerous monster.\n");
            printf("Do you fight the monster? (yes/no) ");
            scanf("%s", choice);

            if (strcmp(choice, "yes") == 0) {
                printf("Congratulations, you have defeated the monster!\n");
                printf("Game over.\n");
            } else {
                printf("You decide not to fight the monster.\n");
                printf("You continue on your journey...\n");
            }
        } else {
            printf("Invalid choice. Please enter either 'left' or 'right'.\n");
        }
    }

    return 0;
}