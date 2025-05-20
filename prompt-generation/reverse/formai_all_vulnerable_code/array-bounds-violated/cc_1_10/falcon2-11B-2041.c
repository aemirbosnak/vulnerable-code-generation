//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROUNDS 100
#define MAX_GUESSES 10

int main(int argc, char *argv[]) {
    char word[20];
    int guesses[MAX_ROUNDS];
    int index;
    int round, guess;
    int length;
    char letter;

    srand(time(NULL));

    printf("Welcome to the Guessing Game!\n");
    printf("I'm thinking of a word between 3 and 10 letters long.\n");

    length = (rand() % (MAX_ROUNDS - 3)) + 3;
    index = 0;
    while (length--) {
        letter = (char) (rand() % 26 + 'a');
        word[index++] = letter;
    }
    word[index] = '\0';

    printf("The word has %d letters.\n", index);

    printf("Guess a letter:\n");

    for (round = 1; round <= MAX_ROUNDS; round++) {
        printf("Round %d/%d\n", round, MAX_ROUNDS);

        for (guess = 0; guess < MAX_GUESSES; guess++) {
            scanf("%c", &guess);
            if (guess!= '\n') {
                guesses[index - 1] = guess;
            } else {
                break;
            }
        }

        if (guess == '\n') {
            printf("You took too long to guess! The word was %s.\n", word);
            return 0;
        }

        if (guess!= '\n') {
            if (guess == word[index - 1]) {
                printf("Correct!\n");
                index--;
            } else {
                printf("Incorrect.\n");
                guesses[index - 1] = 0;
            }
        }
    }

    printf("Congratulations! You guessed the word %s in %d rounds.\n", word, round - 1);
    return 0;
}