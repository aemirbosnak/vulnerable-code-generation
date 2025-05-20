//GPT-4o-mini DATASET v1.0 Category: Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRIES 5
#define WORDS_COUNT 10
#define MAX_WORD_LENGTH 15

const char *WORDS[WORDS_COUNT] = {
    "turing",
    "computer",
    "algorithm",
    "programming",
    "artificial",
    "intelligence",
    "repository",
    "syntax",
    "compile",
    "execute"
};

void display_hangman(int tries) {
    switch(tries) {
        case 0: 
            printf("   -------- \n");
            printf("   |      | \n");
            printf("   |      O \n");
            printf("   |     /|\\ \n");
            printf("   |     / \\ \n");
            printf("   | \n");
            printf("  ===\n");
            break;
        case 1: 
            printf("   -------- \n");
            printf("   |      | \n");
            printf("   |      O \n");
            printf("   |     /|\\ \n");
            printf("   |     / \n");
            printf("   | \n");
            printf("  ===\n");
            break;
        case 2: 
            printf("   -------- \n");
            printf("   |      | \n");
            printf("   |      O \n");
            printf("   |     /|\\ \n");
            printf("   | \n");
            printf("   | \n");
            printf("  ===\n");
            break;
        case 3: 
            printf("   -------- \n");
            printf("   |      | \n");
            printf("   |      O \n");
            printf("   |     /| \n");
            printf("   | \n");
            printf("   | \n");
            printf("  ===\n");
            break;
        case 4: 
            printf("   -------- \n");
            printf("   |      | \n");
            printf("   |      O \n");
            printf("   |      | \n");
            printf("   | \n");
            printf("   | \n");
            printf("  ===\n");
            break;
        case 5: 
            printf("   -------- \n");
            printf("   |      | \n");
            printf("   | \n");
            printf("   | \n");
            printf("   | \n");
            printf("   | \n");
            printf("  ===\n");
            break;
    }
}

void choose_word(char *chosen_word) {
    int index = rand() % WORDS_COUNT;
    strcpy(chosen_word, WORDS[index]);
}

void initialize_guesses(char *guesses, int length) {
    for (int i = 0; i < length; i++) {
        guesses[i] = '_';
    }
    guesses[length] = '\0'; // Null terminate the string
}

int main() {
    srand(time(NULL));
    
    char chosen_word[MAX_WORD_LENGTH];
    choose_word(chosen_word);
    
    int length = strlen(chosen_word);
    char guesses[length + 1];
    initialize_guesses(guesses, length);
    
    int tries = MAX_TRIES;
    char guessed_letter;
    int correct_guess;

    printf("Welcome to Hangman!\n");
    printf("You have %d tries to guess the word.\n", MAX_TRIES);
    
    while (tries > 0 && strcmp(guesses, chosen_word) != 0) {
        printf("\nCurrent word: %s\n", guesses);
        printf("You have %d tries left.\n", tries);
        display_hangman(tries);
        printf("Enter a letter: ");
        scanf(" %c", &guessed_letter);

        correct_guess = 0;
        for (int i = 0; i < length; i++) {
            if (chosen_word[i] == guessed_letter) {
                guesses[i] = guessed_letter;
                correct_guess = 1;
            }
        }

        if (!correct_guess) {
            tries--;
            printf("Incorrect guess!\n");
        } else {
            printf("Good job! You guessed a letter!\n");
        }
    }

    if (strcmp(guesses, chosen_word) == 0) {
        printf("\nCongratulations! You guessed the word: %s\n", chosen_word);
    } else {
        printf("\nGame over! The word was: %s\n", chosen_word);
        display_hangman(tries);
    }

    return 0;
}