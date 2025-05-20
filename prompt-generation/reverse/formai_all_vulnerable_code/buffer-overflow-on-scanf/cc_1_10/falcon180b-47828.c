//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definition of the struct for storing the user's input
typedef struct {
    int num1;
    int num2;
    char operation;
} userInput;

// Function to generate a random number within a given range
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to prompt the user for input
void promptUser(userInput *input) {
    printf("Enter the first number: ");
    scanf("%d", &input->num1);

    printf("Enter the second number: ");
    scanf("%d", &input->num2);

    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &input->operation);
}

// Function to perform the selected arithmetic operation
int performOperation(userInput input) {
    int result = 0;

    switch (input.operation) {
        case '+':
            result = input.num1 + input.num2;
            break;
        case '-':
            result = input.num1 - input.num2;
            break;
        case '*':
            result = input.num1 * input.num2;
            break;
        case '/':
            if (input.num2!= 0) {
                result = input.num1 / input.num2;
            } else {
                printf("Error: Division by zero is not allowed.\n");
                exit(1);
            }
            break;
        default:
            printf("Error: Invalid operation selected.\n");
            exit(1);
    }

    return result;
}

// Function to generate a random arithmetic problem
void generateProblem(userInput *input) {
    input->num1 = generateRandomNumber(1, 100);
    input->num2 = generateRandomNumber(1, 100);

    printf("The problem is: %d %c %d\n", input->num1, input->operation, input->num2);
}

// Function to check if the user's answer is correct
int checkAnswer(userInput input, int answer) {
    int result = performOperation(input);

    if (result == answer) {
        printf("Correct!\n");
        return 1;
    } else {
        printf("Incorrect. The correct answer is %d.\n", result);
        return 0;
    }
}

int main() {
    srand(time(NULL));

    userInput input;
    int correctAnswers = 0;
    int numProblems = 10;

    for (int i = 0; i < numProblems; i++) {
        promptUser(&input);
        generateProblem(&input);

        int answer = performOperation(input);
        int correct = checkAnswer(input, answer);

        if (correct) {
            correctAnswers++;
        }
    }

    printf("You got %d out of %d correct.\n", correctAnswers, numProblems);

    return 0;
}