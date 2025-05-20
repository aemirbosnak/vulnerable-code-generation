//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to get a random number between min and max
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to perform arithmetic operation
int performArithmeticOperation(int num1, int num2, char operation) {
    switch(operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if(num2 == 0) {
                printf("Error: Division by zero\n");
                exit(1);
            }
            return num1 / num2;
        default:
            printf("Error: Invalid operation\n");
            exit(1);
    }
}

// Function to generate a math problem
void generateMathProblem(int difficulty) {
    int num1, num2, operation;
    char op;

    // Get random numbers and operation
    num1 = getRandomNumber(1, 100);
    num2 = getRandomNumber(1, 100);
    switch(difficulty) {
        case 1:
            op = '+';
            break;
        case 2:
            op = '-';
            break;
        case 3:
            op = '*';
            break;
        case 4:
            op = '/';
            break;
        default:
            op = '+';
            break;
    }

    // Print the math problem
    printf("Solve the following problem:\n");
    printf("%d %c %d = ", num1, op, num2);

    // Get user input and check if it's correct
    int answer = performArithmeticOperation(num1, num2, op);
    int userAnswer;
    scanf("%d", &userAnswer);

    if(userAnswer == answer) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is %d.\n", answer);
    }
}

int main() {
    srand(time(NULL));

    // Loop until the user wants to quit
    while(1) {
        printf("Enter difficulty level (1-4): ");
        int difficulty;
        scanf("%d", &difficulty);

        // Generate a math problem
        generateMathProblem(difficulty);

        // Ask the user if they want to continue
        printf("Do you want to continue? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        // Quit if the user chooses to
        if(choice == 'n') {
            break;
        }
    }

    return 0;
}