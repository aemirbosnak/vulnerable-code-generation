//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int ghosts = 0;
    int demons = 0;
    int bats = 0;
    srand(time(NULL));

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are walking through the front door...\n\n");

    while (1) {
        printf("You see three doors in front of you.\n");
        printf("Which do you choose? (1, 2, or 3)\n");

        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1: {
                printf("You open the first door and...\n\n");
                int outcome = rand() % 3;
                switch (outcome) {
                    case 0:
                        printf("There's a ghost in here!\n");
                        ghosts++;
                        break;
                    case 1:
                        printf("A bat flies out and startles you.\n");
                        bats++;
                        break;
                    case 2:
                        printf("This room is safe...\n");
                        break;
                }
                break;
            }
            case 2: {
                printf("You open the second door and...\n\n");
                int outcome = rand() % 3;
                switch (outcome) {
                    case 0:
                        printf("A demon with glowing red eyes appears!\n");
                        demons++;
                        break;
                    case 1:
                        printf("There's a ghost in here!\n");
                        ghosts++;
                        break;
                    case 2:
                        printf("This room is safe...\n");
                        break;
                }
                break;
            }
            case 3: {
                printf("You open the third door and...\n\n");
                int outcome = rand() % 2;
                switch (outcome) {
                    case 0:
                        printf("You find a secret room! There's nothing here, though...\n");
                        break;
                    case 1:
                        printf("A bat flies out and startles you.\n");
                        bats++;
                        break;
                }
                break;
            }
            default: {
                printf("Invalid input. Try again.\n\n");
                continue;
            }
        }

        if (ghosts >= 3) {
            printf("You have encountered too many ghosts and have been possessed.\n");
            break;
        }

        if (demons >= 2) {
            printf("You have encountered too many demons and have been dragged to hell.\n");
            break;
        }

        printf("You continue walking through the house...\n\n");
    }

    printf("Game over.\n");

    return 0;
}