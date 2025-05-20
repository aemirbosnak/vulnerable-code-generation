//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 10
#define FILENAME "scores.txt"

typedef struct {
    char name[50];
    int score;
} Player;

void save_scores(Player players[], int count) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d\n", players[i].name, players[i].score);
    }
    fclose(file);
}

void load_scores(Player players[], int *count) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No previous scores found.\n");
        return;
    }
    *count = 0;
    while (fscanf(file, "%s %d", players[*count].name, &players[*count].score) != EOF) {
        (*count)++;
    }
    fclose(file);
}

int main() {
    Player players[MAX_PLAYERS];
    int player_count = 0;
    load_scores(players, &player_count);

    char input[50];
    int score, number_to_guess, guessed_number;
    char play_again;

    printf("Welcome to the Multiplayer Number Guessing Game!\n");
    do {
        printf("Enter player name: ");
        scanf("%s", input);
        score = 0;

        srand(time(NULL)); // Seed the random number generator
        number_to_guess = rand() % 100 + 1; // Number between 1 and 100

        printf("Hello %s! Try to guess the number between 1 and 100.\n", input);
        do {
            printf("Enter your guess: ");
            scanf("%d", &guessed_number);
            score++;

            if (guessed_number < number_to_guess) {
                printf("Too low! Try again.\n");
            } else if (guessed_number > number_to_guess) {
                printf("Too high! Try again.\n");
            }
        } while (guessed_number != number_to_guess);

        printf("Congratulations %s! You've guessed the number %d in %d tries.\n",
               input, number_to_guess, score);

        // Save player score
        strcpy(players[player_count].name, input);
        players[player_count].score = score;
        player_count++;

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');

    save_scores(players, player_count);
    printf("Scores have been saved successfully.\n");
    return 0;
}