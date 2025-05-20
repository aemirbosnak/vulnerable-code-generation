//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PLAYERS 4
#define MAX_LENGTH 100

void to_lowercase(char *str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void display_progress(const char *secret_word, const char *guessed_word) {
    for(int i = 0; i < strlen(secret_word); i++) {
        if(guessed_word[i] != '\0') {
            printf("%c ", guessed_word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int check_guess(const char *secret_word, char guess_char, char *guessed_word) {
    int correct_guess = 0;
    for(int i = 0; secret_word[i]; i++) {
        if(secret_word[i] == guess_char) {
            guessed_word[i] = guess_char;
            correct_guess = 1;
        }
    }
    return correct_guess;
}

void play_game(const char *secret_word) {
    char guessed_word[MAX_LENGTH] = {0};
    int attempts = 6;
    char guess;

    while(attempts > 0 && strcmp(secret_word, guessed_word) != 0) {
        printf("Current progress: ");
        display_progress(secret_word, guessed_word);
        
        printf("Attempts left: %d\n", attempts);
        printf("Enter your guess (single character): ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        if(!isalpha(guess)) {
            printf("Please enter a valid alphabet character.\n");
            continue;
        }

        if(!check_guess(secret_word, guess, guessed_word)) {
            attempts--;
            printf("Wrong guess!\n");
        } else {
            printf("Good guess!\n");
        }
    }

    if(strcmp(secret_word, guessed_word) == 0) {
        printf("Congratulations! You've guessed the word: %s\n", secret_word);
    } else {
        printf("Game over! The secret word was: %s\n", secret_word);
    }
}

int main() {
    char *players[MAX_PLAYERS];
    char secret_word[MAX_LENGTH];
    int number_of_players;

    printf("Welcome to the Multiplayer Guessing Game!\n");
    
    do {
        printf("Enter number of players (2 to %d): ", MAX_PLAYERS);
        scanf("%d", &number_of_players);
    } while(number_of_players < 2 || number_of_players > MAX_PLAYERS);

    for(int i = 0; i < number_of_players; i++) {
        players[i] = (char *)malloc(MAX_LENGTH * sizeof(char));
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i]);
    }

    printf("Enter the secret word (only for the first player): ");
    scanf("%s", secret_word);
    to_lowercase(secret_word);

    printf("The game is starting!\n");
    for(int i = 0; i < number_of_players; i++) {
        printf("%s's turn:\n", players[i]);
        play_game(secret_word);
    }

    for(int i = 0; i < number_of_players; i++) {
        free(players[i]);
    }

    return 0;
}