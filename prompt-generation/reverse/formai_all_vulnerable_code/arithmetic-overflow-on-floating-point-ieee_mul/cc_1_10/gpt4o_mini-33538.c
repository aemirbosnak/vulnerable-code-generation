//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

struct Calculator {
    double firstNumber;
    double secondNumber;
    char operation;
};

void printInstructions() {
    printf("Welcome to the Invasive Calculator!\n");
    printf("Choose an operation to perform:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Modulus (%%)\n");
    printf("6. Exit\n");
}

void getInput(struct Calculator *calc) {
    printf("Enter the first number: ");
    scanf("%lf", &calc->firstNumber);
    printf("Enter the operation: ");
    scanf(" %c", &calc->operation);
    printf("Enter the second number: ");
    scanf("%lf", &calc->secondNumber);
}

double performOperation(struct Calculator *calc) {
    switch (calc->operation) {
        case '+':
            return calc->firstNumber + calc->secondNumber;
        case '-':
            return calc->firstNumber - calc->secondNumber;
        case '*':
            return calc->firstNumber * calc->secondNumber;
        case '/':
            if (calc->secondNumber != 0) {
                return calc->firstNumber / calc->secondNumber;
            } else {
                printf("Error: Division by zero is not allowed.\n");
                exit(EXIT_FAILURE);
            }
        case '%':
            if ((int)calc->secondNumber != 0) {
                return (int)calc->firstNumber % (int)calc->secondNumber;
            } else {
                printf("Error: Modulus by zero is not allowed.\n");
                exit(EXIT_FAILURE);
            }
        default:
            printf("Invalid operation!\n");
            exit(EXIT_FAILURE);
    }
}

void calculationLoop() {
    struct Calculator calc;
    char continueCalc;
    
    do {
        getInput(&calc);
        
        double result = performOperation(&calc);
        printf("Result: %.2lf\n", result);
        
        printf("Do you want to perform another operation? (y/n): ");
        scanf(" %c", &continueCalc);
        
    } while (continueCalc == 'y' || continueCalc == 'Y');
    
    printf("Thank you for using the Invasive Calculator. Goodbye!\n");
}

int main() {
    printInstructions();
    calculationLoop();
    
    return 0;
}