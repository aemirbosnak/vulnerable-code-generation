//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void welcomeMessage() {
    printf("*****************************************\n");
    printf("*   Welcome to the Magical Math Quest!  *\n");
    printf("*****************************************\n");
    printf("Embark on an adventure where your math skills will help you gather magical resources!\n");
    printf("You can earn gold by solving math puzzles and progressing through the levels.\n");
    printf("*****************************************\n\n");
}

int generateRandomNumber(int max) {
    return rand() % max + 1;
}

int promptForAnswer(int num1, int num2, char operation) {
    int answer;
    
    printf("Solve this math puzzle: %d %c %d = ?\n", num1, operation, num2);
    printf("Your answer: ");
    scanf("%d", &answer);
    
    return answer;
}

int checkAnswer(int correctAnswer, int userAnswer) {
    return correctAnswer == userAnswer;
}

void levelCompletion(int level, int gold) {
    printf("\nCongratulations! You have completed Level %d!\n", level);
    printf("You earned %d gold. Total gold: %d\n", gold, gold * level);
    printf("Prepare for the next level!\n\n");
}

void gameOver(int totalGold) {
    printf("Game Over! You collected a total of %d gold.\n", totalGold);
    printf("Thank you for playing! May your math skills enhance your magical journey.\n");
    exit(0);
}

void playGame() {
    int level = 1;
    int totalGold = 0;
    
    while (level <= 5) {
        int num1 = generateRandomNumber(10 * level);
        int num2 = generateRandomNumber(10 * level);
        char operation = (level % 2 == 0) ? '+' : '-';
        int correctAnswer;

        if (operation == '+') {
            correctAnswer = num1 + num2;
        } else {
            correctAnswer = num1 - num2;
        }
        
        int userAnswer = promptForAnswer(num1, num2, operation);
        
        if (checkAnswer(correctAnswer, userAnswer)) {
            totalGold += 10;
            levelCompletion(level, 10);
            level++;
        } else {
            printf("Wrong answer! You lost some magical energy.\n");
            totalGold -= 2;
            if (totalGold < 0) {
                gameOver(totalGold);
            }
        }
    }
    
    printf("\nYou have completed all levels!\n");
    printf("You collected a total of %d gold.\n", totalGold);
}

int main() {
    srand(time(NULL));
    
    welcomeMessage();
    playGame();

    return 0;
}