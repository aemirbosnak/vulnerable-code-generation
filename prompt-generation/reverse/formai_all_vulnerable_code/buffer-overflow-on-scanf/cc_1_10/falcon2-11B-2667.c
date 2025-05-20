//Falcon2-11B DATASET v1.0 Category: Error handling ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int rock_paper_scissors(char choice, char oppChoice) {
    if (choice == 'R' && oppChoice == 'S') {
        return 1;
    }
    else if (choice == 'P' && oppChoice == 'R') {
        return 2;
    }
    else if (choice == 'S' && oppChoice == 'P') {
        return 3;
    }
    else {
        return 0;
    }
}

int main() {
    char playerChoice;
    char oppChoice;

    printf("Welcome to the Rock-Paper-Scissors game!\n");

    printf("Enter your choice (R for Rock, P for Paper, S for Scissors): ");
    scanf("%c", &playerChoice);

    do {
        if (playerChoice == 'R' || playerChoice == 'P' || playerChoice == 'S') {
            oppChoice = 'R' + rand() % 3;
            printf("Opponent chose: %c\n", oppChoice);
        } else {
            printf("Invalid choice. Please enter R, P, or S.\n");
            playerChoice = 'R' + rand() % 3;
        }
        printf("Enter your choice (R for Rock, P for Paper, S for Scissors): ");
        scanf("%c", &playerChoice);
    } while (playerChoice == 'R' || playerChoice == 'P' || playerChoice == 'S');

    int result = rock_paper_scissors(playerChoice, oppChoice);

    if (result == 1) {
        printf("You win!\n");
    } else if (result == 2) {
        printf("You lose...\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}