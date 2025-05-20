//Code Llama-13B DATASET v1.0 Category: Terminal Based Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 20
#define MAX_GUESS 5
#define MAX_TRIES 3

char word[MAX_LENGTH];
int guessed_letters[MAX_LENGTH];
int guessed_correctly = 0;
int guessed_incorrectly = 0;

void generate_word() {
    int i;
    for (i = 0; i < MAX_LENGTH; i++) {
        word[i] = 'a' + (rand() % 26);
    }
}

void print_word() {
    int i;
    for (i = 0; i < MAX_LENGTH; i++) {
        if (guessed_letters[i]) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void guess_letter() {
    char letter;
    int i;

    printf("Guess a letter: ");
    scanf("%c", &letter);
    letter = tolower(letter);

    for (i = 0; i < MAX_LENGTH; i++) {
        if (word[i] == letter) {
            guessed_letters[i] = 1;
            guessed_correctly++;
        }
    }

    if (guessed_correctly == MAX_LENGTH) {
        printf("You guessed the word!\n");
        exit(0);
    }
}

void guess_word() {
    char word_guess[MAX_LENGTH];
    int i;

    printf("Guess the word: ");
    scanf("%s", word_guess);

    if (strcmp(word_guess, word) == 0) {
        printf("You guessed the word!\n");
        exit(0);
    } else {
        guessed_incorrectly++;
        if (guessed_incorrectly == MAX_TRIES) {
            printf("You lose!\n");
            exit(0);
        }
    }
}

int main() {
    int i;

    srand(time(NULL));
    generate_word();

    for (i = 0; i < MAX_LENGTH; i++) {
        guessed_letters[i] = 0;
    }

    while (1) {
        print_word();
        guess_letter();
        guess_word();
    }

    return 0;
}