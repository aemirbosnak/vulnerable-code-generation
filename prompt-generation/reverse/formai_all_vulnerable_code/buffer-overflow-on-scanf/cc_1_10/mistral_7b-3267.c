//MISTRAL-7B DATASET v1.0 Category: Terminal Based Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 50
#define NUM_WORDS 10

void print_word(char word[MAX_LENGTH]) {
    int i;
    for (i = 0; i < strlen(word); i++) {
        printf("%c", word[i] == '_' ? '?' : word[i]);
    }
    printf("\n");
}

char* get_random_word() {
    static char words[NUM_WORDS][MAX_LENGTH] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "kiwi", "lemon", "mango"};
    return words[rand() % NUM_WORDS];
}

int main() {
    int guesses_left = 7;
    char secret_word[MAX_LENGTH];
    strcpy(secret_word, get_random_word());
    int word_length = strlen(secret_word);

    int i;
    for (i = 0; i < word_length; i++) {
        if (secret_word[i] != '_') {
            secret_word[i] = secret_word[i] == ' ' ? ' ' : '_';
        }
    }

    printf("Welcome to the Hangman Game!\n");
    printf("I have chosen a word for you. Guess a letter to reveal it, or you will be hanged!\n");
    printf("%s\n", secret_word);

    while (guesses_left > 0 && strcmp(secret_word, "_") != 0) {
        char guess;
        scanf("%c", &guess);

        int i;
        for (i = 0; i < word_length; i++) {
            if (secret_word[i] == guess) {
                secret_word[i] = guess;
            }
        }

        int found = 0;
        for (i = 0; i < word_length; i++) {
            if (secret_word[i] == '_') {
                found = 1;
                break;
            }
        }

        if (!found) {
            guesses_left--;
            printf("Incorrect guess! You have %d guesses left.\n", guesses_left);
        } else {
            printf("Correct guess! You have %d guesses left.\n", guesses_left);
        }

        printf("%s\n", secret_word);
    }

    if (strcmp(secret_word, "_") == 0) {
        printf("Congratulations, you have won the game!\n");
    } else {
        printf("Sorry, you have lost the game. The word was %s.\n", secret_word);
    }

    return 0;
}