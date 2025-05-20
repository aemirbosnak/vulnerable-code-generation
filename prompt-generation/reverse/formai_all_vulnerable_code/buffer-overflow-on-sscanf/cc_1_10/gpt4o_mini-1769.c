//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void showInstructions() {
    printf("Welcome to the Math Quiz Game!\n");
    printf("You will be given a set of random math questions.\n");
    printf("Answer them correctly to score points!\n");
    printf("Press 'q' at any time to exit the game.\n");
    printf("Let's see how good you are!\n\n");
}

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

char getRandomOperator() {
    char operators[] = {'+', '-', '*', '/'};
    return operators[getRandomNumber(0, 3)];
}

int calculateAnswer(int num1, int num2, char operator) {
    switch (operator) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num2 != 0 ? num1 / num2 : 0;  // Simple division safeguard
        default: return 0;  // This shouldn't happen
    }
}

void playQuiz() {
    int score = 0;
    char buffer[10];
    int numQuestions = 10; // Total number of questions
    printf("You will answer %d questions.\n", numQuestions);
    printf("Each correct answer is worth 10 points.\n");

    for (int i = 0; i < numQuestions; i++) {
        int num1 = getRandomNumber(1, 20);
        int num2 = getRandomNumber(1, 20);
        char operator = getRandomOperator();
        int correctAnswer = calculateAnswer(num1, num2, operator);

        printf("Question %d: What is %d %c %d?\n", i + 1, num1, operator, num2);
        printf("Your answer (or type 'q' to quit): ");
        
        fgets(buffer, sizeof(buffer), stdin);
        if (buffer[0] == 'q') {
            printf("Thanks for playing! Your final score is: %d\n", score);
            return;
        }

        int userAnswer;
        sscanf(buffer, "%d", &userAnswer);

        if (userAnswer == correctAnswer) {
            printf("Correct!\n");
            score += 10;
        } else {
            printf("Wrong! The correct answer was: %d\n", correctAnswer);
        }
        
        printf("Your current score: %d\n", score);
        printf("------------------------------\n");
    }

    printf("Quiz finished! Your final score is: %d\n", score);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    showInstructions();
    playQuiz();
    return 0;
}