//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_score = 0, computer_score = 0;
    char choice;

    srand(time(NULL));

    do {
        system("clear");
        printf("Welcome to the Terminal Based Game\n");
        printf("Choose an option:\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("You chose rock.\n");
                if (rand() % 2 == 0) {
                    printf("Computer chose scissors.\n");
                    computer_score++;
                } else {
                    printf("Computer chose paper.\n");
                    player_score++;
                }
                break;
            case '2':
                printf("You chose paper.\n");
                if (rand() % 2 == 0) {
                    printf("Computer chose rock.\n");
                    computer_score++;
                } else {
                    printf("Computer chose scissors.\n");
                    player_score++;
                }
                break;
            case '3':
                printf("You chose scissors.\n");
                if (rand() % 2 == 0) {
                    printf("Computer chose rock.\n");
                    computer_score++;
                } else {
                    printf("Computer chose paper.\n");
                    player_score++;
                }
                break;
            default:
                printf("Invalid choice.\n");
        }

        if (player_score == 5 || computer_score == 5) {
            printf("\nGame Over!\n");
            printf("Player score: %d\n", player_score);
            printf("Computer score: %d\n", computer_score);
            break;
        }
    } while (1);

    return 0;
}