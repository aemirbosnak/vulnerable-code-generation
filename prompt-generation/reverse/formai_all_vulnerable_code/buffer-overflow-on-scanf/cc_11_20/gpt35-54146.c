//FormAI DATASET v1.0 Category: Game ; Style: brave
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    srand((unsigned)time(NULL)); // Initialize random seed
 
    char alphabet[27] = "abcdefghijklmnopqrstuvwxyz"; // Alphabet array
 
    printf("Welcome to the Brave Hangman Game!\n");
    printf("In this game you must guess a random word letter by letter before the hangman is fully formed.\n");
    printf("Good Luck!\n\n");
 
    // Select a random word
    char *words[] = {"brave", "adventure", "courage", "fearless", "heroic", "fierce", "bold", "daring", "valiant", "intrepid", "warrior"};
    int size = sizeof(words) / sizeof(words[0]);
    int index = rand() % size;
    char *word = words[index];
 
    int length = strlen(word);
    char guessed[length];
    for (int i = 0; i < length; i++) {
        guessed[i] = '_';
    }
 
    char guess;
    int tries = 0;
    int maxTries = 7;
    int correctGuesses = 0;
 
    while (tries < maxTries && correctGuesses < length) {
        printf("Word: ");
        for (int i = 0; i < length; i++) {
            printf("%c ", guessed[i]);
        }
        printf("\n\n");
 
        printf("Tries left: %d\n", maxTries - tries);
 
        int validGuess = 0;
        do {
            printf("Guess a letter: ");
            scanf(" %c", &guess);
            if (strchr(alphabet, guess)) {
                validGuess = 1;
            } else {
                printf("Invalid character, please guess a letter from a to z.\n\n");
            }
        } while (!validGuess);
 
        int goodGuess = 0;
        for (int i = 0; i < length; i++) {
            if (word[i] == guess) {
                guessed[i] = guess;
                correctGuesses++;
                goodGuess = 1;
            }
        }
 
        if (!goodGuess) {
            printf("Sorry, the letter %c is not in the word.\n\n", guess);
            tries++;
        }
    }
 
    if (correctGuesses == length) {
        printf("Congratulations, you have won the game!\n");
    } else {
        printf("Sorry, you have lost the game. The word was %s.\n", word);
    }
 
    return 0;
}