//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char choice;
    const int GHOST = 1;
    const int ZOMBIE = 2;
    const int VAMPIRE = 3;
    const int WEREWOLF = 4;
    do {
        printf("Welcome to the Haunted House Simulator\n");
        printf("What do you want to do? (E)xplore or (L)eave\n");
        scanf(" %c", &choice);
        if (choice == 'E') {
            srand(time(NULL));
            int monster = rand() % 4 + 1;
            switch (monster) {
                case 1:
                    printf("OH NO! You have encountered a GHOST!\n");
                    break;
                case 2:
                    printf("OH NO! You have encountered a ZOMBIE!\n");
                    break;
                case 3:
                    printf("OH NO! You have encountered a VAMPIRE!\n");
                    break;
                case 4:
                    printf("OH NO! You have encountered a WEREWOLF!\n");
                    break;
            }
            printf("What do you want to do?\n");
            printf("(R)un\n(A)ttack\n(H)ide\n");
            scanf(" %c", &choice);
            if (choice == 'R') {
                printf("You try to run away and...\n");
                int escape = rand() % 2;
                if (escape == 0) {
                    printf("The monster catches you!\n");
                } else {
                    printf("You manage to escape!\n");
                }
            } else if (choice == 'A') {
                printf("You attack the monster and...\n");
                int attack = rand() % 2;
                if (attack == 0) {
                    printf("The monster overpowers you and kills you!\n");
                } else {
                    printf("You defeat the monster!\n");
                }
            } else if (choice == 'H') {
                printf("You hide and...\n");
                int hide = rand() % 2;
                if (hide == 0) {
                    printf("The monster finds you and kills you!\n");
                } else {
                    printf("The monster gives up and leaves you alone...\n");
                }
            }
        } else if (choice == 'L') {
            printf("Goodbye!\n");
            return 0;
        } else {
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 'L');
    return 0;
}