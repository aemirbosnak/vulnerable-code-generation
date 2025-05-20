//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: energetic
#include <stdio.h>

void displayMenu() {
    printf("\n======================\n");
    printf("  ARITHMETIC MAGIC  \n");
    printf("======================\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Modulus\n");
    printf("6. Exit\n");
    printf("======================\n");
    printf("Choose an option (1-6): ");
}

void performAddition() {
    float a, b;
    printf("Enter two numbers to add (separated by space): ");
    scanf("%f %f", &a, &b);
    printf("The sum of %.2f and %.2f is %.2f\n", a, b, a + b);
}

void performSubtraction() {
    float a, b;
    printf("Enter two numbers to subtract (separated by space): ");
    scanf("%f %f", &a, &b);
    printf("The result of %.2f - %.2f is %.2f\n", a, b, a - b);
}

void performMultiplication() {
    float a, b;
    printf("Enter two numbers to multiply (separated by space): ");
    scanf("%f %f", &a, &b);
    printf("The product of %.2f and %.2f is %.2f\n", a, b, a * b);
}

void performDivision() {
    float a, b;
    printf("Enter two numbers to divide (separated by space): ");
    scanf("%f %f", &a, &b);

    if (b == 0) {
        printf("Whoa there! Division by zero is not allowed! Try again.\n");
    } else {
        printf("The result of %.2f / %.2f is %.2f\n", a, b, a / b);
    }
}

void performModulus() {
    int a, b;
    printf("Enter two integers for modulus (separated by space): ");
    scanf("%d %d", &a, &b);

    if (b == 0) {
        printf("Oops! Modulus by zero is not allowed! Try again.\n");
    } else {
        printf("The result of %d %% %d is %d\n", a, b, a % b);
    }
}

int main() {
    int choice;

    printf("Welcome to the Arithmetic Magic Program!\n");
    printf("Prepare to unleash the power of numbers!\n");

    while (1) {
        displayMenu();
        scanf("%d", &choice);

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
                performModulus();
                break;
            case 6:
                printf("Thank you for playing with arithmetic! Goodbye!\n");
                return 0;
            default:
                printf("That's not a valid choice! Try again!\n");
        }
    }

    return 0;
}