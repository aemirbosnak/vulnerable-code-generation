//FormAI DATASET v1.0 Category: Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[20];
    int score;
} Player;

int main(void) {
    srand(time(NULL));
    Player players[5];
    char guess[20];
    char wordList[10][20] = {
        "apple",
        "banana",
        "cherry",
        "grape",
        "kiwi",
        "lemon",
        "orange",
        "peach",
        "pineapple",
        "strawberry"
    };
    int index = rand() % 10;
    int wordLength = strlen(wordList[index]);
    int numGuesses = 0;
    int numCorrect = 0;

    printf("Welcome to the word guessing game!\n");

    printf("Enter your name: ");
    scanf("%s", players[0].name);
    players[0].score = 0;

    printf("Guess the word (hint: it's a fruit and has %d letters):\n", wordLength);

    while(numGuesses < 5 && numCorrect < wordLength) {
        printf("Guess #%d: ", numGuesses+1);
        scanf("%s", guess);

        if(strlen(guess) != wordLength) {
            printf("Wrong word length, try again.\n");
            continue;
        }

        numCorrect = 0;
        for(int i=0; i<wordLength; i++) {
            if(guess[i] == wordList[index][i]) {
                numCorrect++;
            }
        }

        if(numCorrect == wordLength) {
            printf("Congratulations %s, you win! The word was %s.\n", players[0].name, wordList[index]);
            players[0].score += 10 - numGuesses;
        } else {
            printf("Number of correct letters: %d\n", numCorrect);
        }

        numGuesses++;
    }

    if(numGuesses == 5 && numCorrect < wordLength) {
        printf("Sorry, you lose! The word was %s.\n", wordList[index]);
    }

    printf("Your score: %d\n", players[0].score);

    return 0;
}