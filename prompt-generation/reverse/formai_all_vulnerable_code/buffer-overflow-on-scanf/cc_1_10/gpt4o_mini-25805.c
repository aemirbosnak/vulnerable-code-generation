//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: happy
#include <stdio.h>

void display_welcome_message() {
    printf("🎉 Welcome to the Happy Arithmetic Calculator! 🎉\n");
    printf("Here, we will perform happy arithmetic operations.\n");
    printf("Let's make numbers dance with joy! 💃🕺\n");
    printf("Press Ctrl+C to exit at any time. 🌟\n\n");
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    if (b != 0) {
        return (float)a / b;
    } else {
        printf("🚫 Oops! Division by zero is not allowed. Let's skip this dance!\n");
        return 0;
    }
}

void perform_operations(int num1, int num2) {
    printf("✨ Let's perform some operations with %d and %d! ✨\n", num1, num2);
    
    int sum = add(num1, num2);
    printf("💡 Addition: %d + %d = %d\n", num1, num2, sum);
    
    int difference = subtract(num1, num2);
    printf("💡 Subtraction: %d - %d = %d\n", num1, num2, difference);
    
    int product = multiply(num1, num2);
    printf("💡 Multiplication: %d * %d = %d\n", num1, num2, product);
    
    float quotient = divide(num1, num2);
    if (num2 != 0) {
        printf("💡 Division: %d / %d = %.2f\n", num1, num2, quotient);
    }
    
    printf("🎉 All calculations are done! Let's have a round of applause! 👏👏\n\n");
}

void ask_for_numbers() {
    int num1, num2;

    printf("🌈 Please enter the first number: ");
    scanf("%d", &num1);
    printf("🌈 Please enter the second number: ");
    scanf("%d", &num2);

    perform_operations(num1, num2);
}

int main() {
    display_welcome_message();
    
    while (1) {
        ask_for_numbers();
        char choice;

        printf("💖 Would you like to perform another operation? (y/n): ");
        scanf(" %c", &choice);

        if (choice != 'y' && choice != 'Y') {
            printf("🌟 Thank you for using the Happy Arithmetic Calculator! 🌟\n");
            printf("Wishing you a joyful day ahead! 🌻\n");
            break;
        }
    }

    return 0;
}