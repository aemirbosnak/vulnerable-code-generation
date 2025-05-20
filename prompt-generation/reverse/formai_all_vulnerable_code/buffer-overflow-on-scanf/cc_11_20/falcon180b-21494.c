//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 0
#define P 1
#define S 2

int main() {
    int choice;
    int score = 0;
    int computer_score = 0;
    char again;

    srand(time(0));

    do {
        printf("Welcome to Rock Paper Scissors!\n");
        printf("Please choose your move:\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n");
        scanf("%d", &choice);

        switch (choice) {
            case R:
                printf("You chose Rock.\n");
                if (rand() % 3 == 0) {
                    printf("Computer chose Rock.\n");
                    computer_score += 1;
                } else if (rand() % 3 == 1) {
                    printf("Computer chose Paper.\n");
                    score += 1;
                } else {
                    printf("Computer chose Scissors.\n");
                }
                break;
            case P:
                printf("You chose Paper.\n");
                if (rand() % 3 == 0) {
                    printf("Computer chose Rock.\n");
                    score += 1;
                } else if (rand() % 3 == 1) {
                    printf("Computer chose Paper.\n");
                    computer_score += 1;
                } else {
                    printf("Computer chose Scissors.\n");
                }
                break;
            case S:
                printf("You chose Scissors.\n");
                if (rand() % 3 == 0) {
                    printf("Computer chose Rock.\n");
                    computer_score += 1;
                } else if (rand() % 3 == 1) {
                    printf("Computer chose Paper.\n");
                    score += 1;
                } else {
                    printf("Computer chose Scissors.\n");
                }
                break;
            default:
                printf("Invalid move. Please try again.\n");
        }

        printf("Score: You - %d, Computer - %d\n", score, computer_score);

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &again);
    } while (again == 'y' || again == 'Y');

    return 0;
}