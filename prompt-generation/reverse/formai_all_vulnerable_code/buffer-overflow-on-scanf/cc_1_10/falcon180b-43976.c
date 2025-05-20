//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define WORD_LENGTH_MIN 4
#define WORD_LENGTH_MAX 12
#define MAX_ATTEMPTS 3

// Function to check if a character is a letter
int isLetter(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    } else if (c >= 'A' && c <= 'Z') {
        return 1;
    } else {
        return 0;
    }
}

// Function to generate a random word
char *generateRandomWord(int length) {
    char *word = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        char c = rand() % 26 + 'a';
        if (isLetter(c)) {
            word[i] = c;
        } else {
            i--;
        }
    }
    word[length] = '\0';
    return word;
}

// Function to print a word with underscores for incorrect guesses
void printWord(char *word, int length, int attempts) {
    for (int i = 0; i < length; i++) {
        if (word[i] == '\0') {
            printf("_ ");
        } else {
            printf("%c ", word[i]);
        }
    }
    printf("\n");
}

// Function to check if a guess is correct
int checkGuess(char *word, char guess) {
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == guess) {
            return 1;
        }
    }
    return 0;
}

// Function to start the game
void startGame(int difficulty) {
    srand(time(NULL));
    char *word;
    int attempts = 0;
    int length = WORD_LENGTH_MIN + (difficulty - 1) * 2;
    while (attempts < MAX_ATTEMPTS) {
        word = generateRandomWord(length);
        printf("Guess the word:\n");
        printWord(word, length, attempts);
        char guess;
        scanf(" %c", &guess);
        if (isalpha(guess)) {
            guess = tolower(guess);
            if (checkGuess(word, guess)) {
                printf("Correct!\n");
            } else {
                printf("Incorrect.\n");
            }
        } else {
            printf("Invalid input.\n");
        }
        attempts++;
    }
    printf("Game over. The word was: %s\n", word);
}

int main() {
    int difficulty;
    printf("Welcome to the Medieval Typing Speed Test!\n");
    printf("Choose your difficulty:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    scanf("%d", &difficulty);
    startGame(difficulty);
    return 0;
}