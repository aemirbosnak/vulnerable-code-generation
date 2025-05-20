//Falcon-180B DATASET v1.0 Category: Table Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int playerScore = 0;
    int computerScore = 0;
    int choice;

    printf("Welcome to the Cheerful Table Game!\n");
    printf("You will be playing against the computer.\n");
    printf("Choose an option:\n");
    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You chose Rock.\n");
            computerScore = rand() % 3;
            if(computerScore == 0) {
                printf("Computer chose Rock.\n");
                printf("It's a tie!\n");
            } else if(computerScore == 1) {
                printf("Computer chose Paper.\n");
                printf("Computer wins!\n");
                computerScore++;
            } else {
                printf("Computer chose Scissors.\n");
                printf("You win!\n");
                playerScore++;
            }
            break;
        case 2:
            printf("You chose Paper.\n");
            computerScore = rand() % 3;
            if(computerScore == 0) {
                printf("Computer chose Rock.\n");
                printf("You win!\n");
                playerScore++;
            } else if(computerScore == 1) {
                printf("Computer chose Paper.\n");
                printf("It's a tie!\n");
            } else {
                printf("Computer chose Scissors.\n");
                printf("Computer wins!\n");
                computerScore++;
            }
            break;
        case 3:
            printf("You chose Scissors.\n");
            computerScore = rand() % 3;
            if(computerScore == 0) {
                printf("Computer chose Rock.\n");
                printf("Computer wins!\n");
                computerScore++;
            } else if(computerScore == 1) {
                printf("Computer chose Paper.\n");
                printf("You win!\n");
                playerScore++;
            } else {
                printf("Computer chose Scissors.\n");
                printf("It's a tie!\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }

    printf("Player score: %d\n", playerScore);
    printf("Computer score: %d\n", computerScore);

    return 0;
}