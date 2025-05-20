//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 20
#define MAX_WORD_LENGTH 10

char words[MAX_WORDS][MAX_WORD_LENGTH];
int numWords;

void initWords() {
    numWords = 0;
    FILE *file = fopen("words.txt", "r");
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[numWords], word);
        numWords++;
    }
    fclose(file);
}

void playGame() {
    srand(time(NULL));
    int wordIndex = rand() % numWords;
    char *word = words[wordIndex];
    char *guess = malloc(MAX_WORD_LENGTH * sizeof(char));
    int maxGuesses = MAX_WORD_LENGTH + 1;
    int numGuesses = 0;
    int correctGuesses = 0;
    int incorrectGuesses = 0;
    int lastGuessWasCorrect = 0;
    while (numGuesses < maxGuesses) {
        printf("Current word: %s\n", guess);
        printf("Number of letters: %d\n", strlen(word));
        printf("Number of correct guesses: %d\n", correctGuesses);
        printf("Number of incorrect guesses: %d\n", incorrectGuesses);
        printf("Last guess was correct: %s\n", lastGuessWasCorrect? "Yes" : "No");
        printf("Enter your guess: ");
        scanf("%s", guess);
        if (strcmp(guess, word) == 0) {
            printf("Congratulations, you win!\n");
            break;
        } else if (strcmp(guess, word) < 0) {
            printf("Too short.\n");
        } else {
            for (int i = 0; i < strlen(word); i++) {
                if (word[i] == guess[i]) {
                    correctGuesses++;
                } else {
                    incorrectGuesses++;
                }
            }
            lastGuessWasCorrect = correctGuesses > 0;
        }
        numGuesses++;
    }
    free(guess);
}

int main() {
    initWords();
    playGame();
    return 0;
}