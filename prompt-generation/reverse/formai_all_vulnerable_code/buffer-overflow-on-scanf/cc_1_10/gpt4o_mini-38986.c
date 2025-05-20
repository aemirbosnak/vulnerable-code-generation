//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printWelcomeMessage() {
    printf("*************************************\n");
    printf("*       Welcome to Math Quiz!       *\n");
    printf("*************************************\n");
    printf("Prepare to put your math skills to the test!\n\n");
}

int generateRandomNumber(int limit) {
    return rand() % limit + 1; // Generates a number between 1 and limit
}

char getRandomOperation() {
    char operations[] = {'+', '-', '*', '/'};
    return operations[rand() % 4]; // Randomly select one operation
}

int performCalculation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b != 0) ? a / b : 0; // Avoid division by zero
        default: return 0; // Should not reach here
    }
}

void playQuiz(int numberOfQuestions) {
    int score = 0;
    
    for (int i = 1; i <= numberOfQuestions; i++) {
        int num1 = generateRandomNumber(10);
        int num2 = generateRandomNumber(10);
        char operation = getRandomOperation();
        
        // Division special case - ensure clean division
        if (operation == '/') {
            num1 *= num2; // Ensuring num1 is divisible by num2
        }
        
        int correctAnswer = performCalculation(num1, num2, operation);
        int userAnswer;
        
        printf("Question %d: %d %c %d = ? ", i, num1, operation, num2);
        scanf("%d", &userAnswer);
        
        if (userAnswer == correctAnswer) {
            printf("Correct! Well done!\n\n");
            score++;
        } else {
            printf("Oops! The correct answer was: %d\n\n", correctAnswer);
        }
    }
    
    printf("Quiz Over! Your final score: %d out of %d\n", score, numberOfQuestions);
}

int main() {
    srand(time(0)); // Seed for random number generation
    printWelcomeMessage();
    
    int numberOfQuestions;
    printf("How many questions would you like to attempt? ");
    scanf("%d", &numberOfQuestions);
    
    if (numberOfQuestions <= 0) {
        printf("Let's have at least one question! Let's start again.\n");
        return 1; // Exit the program
    }
    
    playQuiz(numberOfQuestions);
    
    printf("Thank you for playing! Keep practicing and you'll be a math master in no time!\n");
    
    return 0;
}