//FormAI DATASET v1.0 Category: Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void printIntro();
int generateRandomNumber(int difficulty);
int playGame(int difficulty);

int main() {
    int levelDifficulty = 1;
    int maxDifficulty = 5;
    printIntro();
    while(levelDifficulty <= maxDifficulty) {
        int gameStatus = playGame(levelDifficulty);
        if(gameStatus) {
            levelDifficulty++;
            printf("Congratulations! You have won level %d.\n", levelDifficulty - 1);
        } else {
            printf("Game Over. You lost at level %d.\n", levelDifficulty);
            printf("Try again!\n");
            levelDifficulty = 1; // reset the game
        }
    }
    printf("Congratulations! You have won the game!\n");
    return 0;
}

// print the introduction message
void printIntro() {
    printf("Welcome to the Guess the Number Game!\n");
    printf("You will have to guess a random number between 1 and 100.\n");
    printf("You have five chances to guess.\n");
}

// generate random number based on difficulty level
int generateRandomNumber(int difficulty) {
    srand(time(0));
    int maxNumber = difficulty * 20;
    int randomNumber = rand() % maxNumber + 1;
    return randomNumber;
}

// play the game
int playGame(int difficulty) {
    int randomNumber = generateRandomNumber(difficulty);
    int guessCount = 1;
    int guess;
    printf("Level %d: Guess the secret number\n", difficulty);
    while(guessCount <= 5) {
        printf("Guess #%d: ", guessCount);
        scanf("%d", &guess);
        if(guess == randomNumber) {
            return 1;
        } else if(guess < randomNumber) {
            printf("Too low. Try again!\n");
        } else {
            printf("Too high. Try again!\n");
        }
        guessCount++;
    }
    return 0;
}