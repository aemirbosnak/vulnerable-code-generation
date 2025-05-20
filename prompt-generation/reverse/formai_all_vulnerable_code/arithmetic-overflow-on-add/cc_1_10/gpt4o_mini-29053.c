//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void welcome() {
    printf("🌟 Welcome to the Cheerful Arithmetic Program! 🌟\n");
    printf("Let's do some calculations with a smile!\n\n");
}

void showMenu() {
    printf("Please choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("Your choice: ");
}

int getIntegerInput() {
    int num;
    char term;
    while (1) {
        if (scanf("%d%c", &num, &term) != 2 || term != '\n') {
            printf("😅 Oops! That's not a valid integer. Try again: ");
            while (getchar() != '\n'); // Clear the input buffer
        } else {
            break;
        }
    }
    return num;
}

void performAddition() {
    printf("Let's add some numbers! 😊\n");
    printf("Enter the first number: ");
    int a = getIntegerInput();
    printf("Enter the second number: ");
    int b = getIntegerInput();
    printf("The result of %d + %d is %d! 🎉\n", a, b, a + b);
}

void performSubtraction() {
    printf("Let's subtract some numbers! 😊\n");
    printf("Enter the first number: ");
    int a = getIntegerInput();
    printf("Enter the second number: ");
    int b = getIntegerInput();
    printf("The result of %d - %d is %d! 🎉\n", a, b, a - b);
}

void performMultiplication() {
    printf("Let's multiply some numbers! 😊\n");
    printf("Enter the first number: ");
    int a = getIntegerInput();
    printf("Enter the second number: ");
    int b = getIntegerInput();
    printf("The result of %d * %d is %d! 🎉\n", a, b, a * b);
}

void performDivision() {
    printf("Let's divide some numbers! 😊\n");
    printf("Enter the numerator: ");
    int a = getIntegerInput();
    printf("Enter the denominator: ");
    int b;
    while (1) {
        b = getIntegerInput();
        if (b == 0) {
            printf("😳 Oops! We cannot divide by zero. Please enter a different denominator: ");
        } else {
            break;
        }
    }
    printf("The result of %d / %d is %.2f! 🎉\n", a, b, (float)a / b);
}

int main() {
    welcome();
    
    int choice;
    while (1) {
        showMenu();
        choice = getIntegerInput();
        
        switch (choice) {
            case 1:
                performAddition();
                break;
            case 2:
                performSubtraction();
                break;
            case 3:
                performMultiplication();
                break;
            case 4:
                performDivision();
                break;
            case 5:
                printf("🎉 Thank you for using the Cheerful Arithmetic Program! Goodbye! 👋\n");
                return 0;
            default:
                printf("😅 Hmm, that's not a valid choice. Please select 1-5.\n");
        }
        printf("\n");
    }
    
    return 0; // Never reached but keeps the compiler happy!
}