//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// Function to clear the Terminal screen
void clearScreen() {
    printf("\033[2J\033[1;1H");
}

// Function to generate a random number between the range min to max
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random operator (+, -, *)
char getRandomOperator() {
    char operators[] = {'+', '-', '*'};
    int randomIndex = rand() % 3;
    return operators[randomIndex];
}

// Function to evaluate the expression and return the result
int evaluateExpression(int operand1, char operator, int operand2) {
    switch(operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
    }
}

int main() {
    clearScreen();
    srand(time(NULL));

    printf("Welcome to Mind Bender!\nYou have 60 seconds to answer as many expressions as you can.\n");

    int score = 0;
    time_t startTime = time(NULL);
    time_t currentTime = startTime;

    // Loop for 60 seconds
    while(currentTime - startTime < 60) {
        int operand1 = getRandomNumber(1, 10);
        int operand2 = getRandomNumber(1, 10);
        char operator = getRandomOperator();

        printf("\n%u %c %u = ?", operand1, operator, operand2);

        // Read the user input
        char userInput[3];
        scanf("%s", userInput);
        int answer = atoi(userInput);

        int result = evaluateExpression(operand1, operator, operand2);

        if(answer == result) {
            printf("Correct!\n");
            score++;
        }
        else {
            printf("Incorrect!\n");
        }

        currentTime = time(NULL);
    }

    clearScreen();
    printf("Game over! Your score is: %u\n", score);

    return 0;
}