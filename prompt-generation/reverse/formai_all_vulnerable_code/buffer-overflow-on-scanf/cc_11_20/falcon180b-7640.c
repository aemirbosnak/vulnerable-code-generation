//Falcon-180B DATASET v1.0 Category: Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int players;
    int i;
    int choice;
    int guess;
    int secret_number;
    int wins = 0;
    int losses = 0;
    int ties = 0;
    int total_games = 0;
    int player_score = 0;
    int computer_score = 0;
    int high_score = 0;
    char name[20];

    srand(time(NULL));
    secret_number = rand() % 100 + 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("Can you guess what it is?\n");

    do {
        printf("How many players will be playing? ");
        scanf("%d", &players);
    } while (players < 1 || players > 10);

    for (i = 0; i < players; i++) {
        printf("Player %d, enter your name: ", i + 1);
        scanf("%s", name);
        printf("Welcome, %s!\n", name);
    }

    do {
        printf("Press enter to begin the game.\n");
        getchar();
        system("clear");
        printf("Round %d\n", ++total_games);
        printf("The number is between %d and %d.\n", 1, 100);
    } while (1);

    while (total_games < 10) {
        for (i = 0; i < players; i++) {
            printf("It's %s's turn.\n", name);
            printf("Guess a number: ");
            scanf("%d", &guess);

            if (guess == secret_number) {
                printf("%s wins!\n", name);
                wins++;
                player_score += 10;
            } else if (guess < secret_number) {
                printf("Too low.\n");
            } else {
                printf("Too high.\n");
            }

            if (total_games == 9) {
                high_score = player_score;
            }
        }

        if (wins == players) {
            printf("All players win!\n");
            break;
        } else if (losses == players) {
            printf("All players lose.\n");
            break;
        }

        printf("Computer's turn.\n");
        computer_score += rand() % 100 + 1;

        if (computer_score == high_score) {
            printf("Tie game.\n");
            ties++;
        } else if (computer_score > high_score) {
            printf("Computer wins!\n");
            losses++;
        }

        total_games++;
    }

    if (wins == players) {
        printf("Congratulations, you all win!\n");
    } else if (losses == players) {
        printf("Sorry, you all lose.\n");
    } else {
        printf("Tie game.\n");
    }

    return 0;
}