//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerScore = 0, computerScore = 0;
    char choice;

    srand(time(NULL));

    printf("Welcome to Rock, Paper, Scissors!\n\n");

    while(1) {
        printf("\nYour score: %d\nComputer score: %d\n", playerScore, computerScore);
        printf("Enter your choice (r/p/s): ");
        scanf("%c", &choice);

        int computerChoice = rand() % 3;

        if(computerChoice == 0) {
            printf("Computer chose rock.\n");
        } else if(computerChoice == 1) {
            printf("Computer chose paper.\n");
        } else {
            printf("Computer chose scissors.\n");
        }

        if(choice == 'r' && computerChoice == 2) {
            printf("You win!\n");
            playerScore++;
        } else if(choice == 'p' && computerChoice == 0) {
            printf("You win!\n");
            playerScore++;
        } else if(choice =='s' && computerChoice == 1) {
            printf("You win!\n");
            playerScore++;
        } else if(choice == 'r' && computerChoice == 0) {
            printf("You lose.\n");
            computerScore++;
        } else if(choice == 'p' && computerChoice == 1) {
            printf("You lose.\n");
            computerScore++;
        } else if(choice =='s' && computerChoice == 2) {
            printf("You lose.\n");
            computerScore++;
        } else {
            printf("It's a tie!\n");
        }

        if(playerScore == 5) {
            printf("\nYou win the game!\n");
            break;
        } else if(computerScore == 5) {
            printf("\nYou lose the game.\n");
            break;
        }
    }

    return 0;
}