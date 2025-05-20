//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // For sleep function

#define MAX_PLAYERS 4
#define MAX_GUESSES 10

void display_instructions() {
    printf("Welcome to the 'Guess the Number' Game!\n");
    printf("Each player will have %d turns to guess a number between 1 and 100.\n", MAX_GUESSES);
    printf("The game ends once a player guesses the correct number.\n");
    printf("Good luck!\n");
}

void get_player_names(char players[MAX_PLAYERS][50], int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("Enter the name of player %d: ", i + 1);
        fgets(players[i], 50, stdin);
        players[i][strcspn(players[i], "\n")] = 0; // Remove newline character
    }
}

int main() {
    char players[MAX_PLAYERS][50];
    int num_players;

    printf("Enter number of players (1 to %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    getchar(); // consume the newline character after number input

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting game.\n");
        return 1;
    }

    get_player_names(players, num_players);
    display_instructions();

    srand(time(0));
    int secret_number = rand() % 100 + 1;
    int guesses[MAX_PLAYERS] = {0};
    int found = 0;
    
    printf("\nA number between 1 and 100 has been chosen. Let's start guessing!\n");

    for (int round = 1; round <= MAX_GUESSES && !found; round++) {
        for (int i = 0; i < num_players && !found; i++) {
            int guess;
            printf("\n%s's turn (Round %d): ", players[i], round);
            printf("Enter your guess: ");
            scanf("%d", &guess);

            if (guess < 1 || guess > 100) {
                printf("Guess out of bounds! Please guess a number between 1 and 100.\n");
                i--; // Let the player try again in the same round
                continue;
            }

            guesses[i]++;

            if (guess == secret_number) {
                printf("Congratulations %s! You've guessed the correct number %d in %d attempts!\n",
                        players[i], secret_number, guesses[i]);
                found = 1; // Mark as found
            } else if (guess < secret_number) {
                printf("Too low! Try again.\n");
            } else {
                printf("Too high! Try again.\n");
            }
            sleep(1); // Adding a little pause for better gameplay experience
        }
    }

    if (!found) {
        printf("\nAll players have used their guesses! The secret number was %d.\n", secret_number);
    }

    printf("\nGame Over! Thank you for playing!\n");
    return 0;
}