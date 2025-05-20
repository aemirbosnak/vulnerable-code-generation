//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: genius
#include <stdio.h>

// Function prototypes
void displayMenu();
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);
void calculateAverage(int count, int total);
void handleDivisionByZero(int b);

int main() {
    int choice, a, b;
    int total = 0;
    int count = 0;
    int result;

    do {
        displayMenu();
        printf("Enter your choice (1-5), 0 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two integers to add: ");
                scanf("%d %d", &a, &b);
                result = add(a, b);
                printf("Result of addition: %d + %d = %d\n", a, b, result);
                total += result;
                count++;
                break;

            case 2:
                printf("Enter two integers to subtract: ");
                scanf("%d %d", &a, &b);
                result = subtract(a, b);
                printf("Result of subtraction: %d - %d = %d\n", a, b, result);
                total += result;
                count++;
                break;

            case 3:
                printf("Enter two integers to multiply: ");
                scanf("%d %d", &a, &b);
                result = multiply(a, b);
                printf("Result of multiplication: %d * %d = %d\n", a, b, result);
                total += result;
                count++;
                break;

            case 4:
                printf("Enter two integers to divide: ");
                scanf("%d %d", &a, &b);
                handleDivisionByZero(b);
                result = divide(a, b);
                printf("Result of division: %d / %d = %.2f\n", a, b, result);
                total += result;
                count++;
                break;

            case 5:
                calculateAverage(count, total);
                break;

            case 0:
                printf("Exiting the program. Thank you for using our Arithmetic Calculator!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");

    } while (choice != 0);

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("------- Arithmetic Calculator -------\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Calculate Average of Results\n");
    printf("0. Exit\n");
    printf("-------------------------------------\n");
}

// Function to add two integers
int add(int a, int b) {
    return a + b;
}

// Function to subtract two integers
int subtract(int a, int b) {
    return a - b;
}

// Function to multiply two integers
int multiply(int a, int b) {
    return a * b;
}

// Function to divide two integers
float divide(int a, int b) {
    return (float)a / b;
}

// Function to handle division by zero
void handleDivisionByZero(int b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed!\n");
        return;
    }
}

// Function to calculate and display average
void calculateAverage(int count, int total) {
    if (count > 0) {
        float average = (float)total / count;
        printf("The average of the results is: %.2f\n", average);
    } else {
        printf("No calculations made yet to average.\n");
    }
}