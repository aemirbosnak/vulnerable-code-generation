//Falcon-180B DATASET v1.0 Category: Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerScore = 0;
    int computerScore = 0;
    char choice;

    srand(time(0));
    int computerChoice = rand() % 3;

    printf("Welcome to Rock Paper Scissors!\n");
    printf("You will be playing against the computer.\n");
    printf("Enter your choice: ");
    scanf("%c", &choice);

    switch (choice) {
        case 'r':
        case 'R':
            printf("You chose rock.\n");
            if (computerChoice == 0) {
                printf("Computer chose scissors.\n");
                computerScore++;
            } else if (computerChoice == 1) {
                printf("Computer chose paper.\n");
            } else {
                printf("Computer chose rock.\n");
                playerScore++;
            }
            break;

        case 'p':
        case 'P':
            printf("You chose paper.\n");
            if (computerChoice == 0) {
                printf("Computer chose scissors.\n");
            } else if (computerChoice == 1) {
                printf("Computer chose paper.\n");
                computerScore++;
            } else {
                printf("Computer chose rock.\n");
                playerScore++;
            }
            break;

        case's':
        case 'S':
            printf("You chose scissors.\n");
            if (computerChoice == 0) {
                printf("Computer chose rock.\n");
                computerScore++;
            } else if (computerChoice == 1) {
                printf("Computer chose paper.\n");
            } else {
                printf("Computer chose scissors.\n");
                playerScore++;
            }
            break;

        default:
            printf("Invalid choice.\n");
            return 0;
    }

    printf("\nFinal scores:\n");
    printf("You: %d\n", playerScore);
    printf("Computer: %d\n", computerScore);

    if (playerScore > computerScore) {
        printf("You win!\n");
    } else if (computerScore > playerScore) {
        printf("Computer wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}