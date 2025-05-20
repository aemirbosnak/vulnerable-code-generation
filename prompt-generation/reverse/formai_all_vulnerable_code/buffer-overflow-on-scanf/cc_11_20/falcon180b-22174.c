//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    srand(time(NULL));
    int player_score = 0;
    int computer_score = 0;
    char choice;
    int random_number;
    int num_of_rounds = 10;
    int i;

    printf("Welcome to the Rock-Paper-Scissors game!\n");
    printf("You will play against the computer.\n");
    printf("The game consists of %d rounds.\n", num_of_rounds);
    printf("Enter your choice (R for Rock, P for Paper, S for Scissors): ");
    scanf("%c", &choice);
    tolower(choice);

    for (i = 0; i < num_of_rounds; i++) {
        random_number = rand() % 3;
        if (random_number == 0) {
            printf("The computer chose Rock.\n");
        } else if (random_number == 1) {
            printf("The computer chose Paper.\n");
        } else {
            printf("The computer chose Scissors.\n");
        }
        if (tolower(choice) == 'r') {
            if (random_number == 0) {
                printf("It's a tie!\n");
            } else if (random_number == 1) {
                printf("You lose this round.\n");
                computer_score++;
            } else {
                printf("You win this round!\n");
                player_score++;
            }
        } else if (tolower(choice) == 'p') {
            if (random_number == 0) {
                printf("You win this round!\n");
                player_score++;
            } else if (random_number == 1) {
                printf("You lose this round.\n");
                computer_score++;
            } else {
                printf("It's a tie!\n");
            }
        } else if (tolower(choice) =='s') {
            if (random_number == 0) {
                printf("You lose this round.\n");
                computer_score++;
            } else if (random_number == 1) {
                printf("You win this round!\n");
                player_score++;
            } else {
                printf("It's a tie!\n");
            }
        } else {
            printf("Invalid choice. Please try again.\n");
            i--;
        }
    }

    if (player_score > computer_score) {
        printf("Congratulations! You won the game with a score of %d to %d!\n", player_score, computer_score);
    } else if (computer_score > player_score) {
        printf("Sorry, you lost the game with a score of %d to %d.\n", player_score, computer_score);
    } else {
        printf("It's a tie! The final score is %d to %d.\n", player_score, computer_score);
    }

    return 0;
}