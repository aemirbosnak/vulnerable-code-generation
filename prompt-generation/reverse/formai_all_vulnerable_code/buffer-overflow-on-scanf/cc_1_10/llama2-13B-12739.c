//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define SORRY 0
#define NOT_SORRY 1

int main() {
    int choice;
    char name[50];
    int age;

    // Ask the user for their name and age
    printf("Hello! What's your name? ");
    scanf("%s", name);
    printf("And how old are you? ");
    scanf("%d", &age);

    // Generate a random number between 1 and 10
    int random_number = rand() % 10 + 1;

    // Determine whether the user should say "Sorry" or "Not Sorry"
    choice = (random_number % 2) ? NOT_SORRY : SORRY;

    // Print the user's name, age, and choice
    printf("Hello %s! You are %d years old and you should say %s.\n", name, age, choice == SORRY ? "Sorry" : "Not Sorry");

    // Play a game of "Rock, Paper, Scissors"
    int rock = 0, paper = 0, scissors = 0;
    char player_choice[3];
    char computer_choice[3];

    do {
        // Ask the user for their choice
        printf("Choose your weapon (Rock, Paper, Scissors): ");
        scanf("%2s", player_choice);

        // Generate a random computer choice
        computer_choice[0] = 'R' + (rand() % 3);
        computer_choice[1] = 'P' + (rand() % 3);
        computer_choice[2] = 'S' + (rand() % 3);

        // Determine the winner
        if (strcmp(player_choice, computer_choice) == 0) {
            printf("Tie! Both of you chose %s.\n", player_choice);
        } else if (strcmp(player_choice, "Rock") && strcmp(computer_choice, "Scissors") == 0) {
            printf("You win! Computer chose %s, but you chose %s.\n", computer_choice, player_choice);
        } else if (strcmp(player_choice, "Paper") && strcmp(computer_choice, "Rock") == 0) {
            printf("You win! Computer chose %s, but you chose %s.\n", computer_choice, player_choice);
        } else {
            printf("Computer wins! You chose %s, but computer chose %s.\n", player_choice, computer_choice);
        }

        // Keep playing until the user wants to quit
        choice = getchar() == 'q' ? NOT_SORRY : SORRY;
    } while (choice == NOT_SORRY);

    return 0;
}