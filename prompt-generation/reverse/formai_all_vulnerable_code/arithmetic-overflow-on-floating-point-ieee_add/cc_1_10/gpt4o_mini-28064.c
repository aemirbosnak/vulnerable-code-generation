//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: Ken Thompson
#include <stdio.h>

#define MAX_SIZE 100

void print_menu() {
    printf("\n--- Arithmetic Operations Menu ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("-----------------------------------\n");
}

void addition() {
    float a, b;
    printf("Enter two numbers for addition: ");
    scanf("%f %f", &a, &b);
    printf("Result: %.2f\n", a + b);
}

void subtraction() {
    float a, b;
    printf("Enter two numbers for subtraction: ");
    scanf("%f %f", &a, &b);
    printf("Result: %.2f\n", a - b);
}

void multiplication() {
    float a, b;
    printf("Enter two numbers for multiplication: ");
    scanf("%f %f", &a, &b);
    printf("Result: %.2f\n", a * b);
}

void division() {
    float a, b;
    printf("Enter two numbers for division: ");
    scanf("%f %f", &a, &b);
    if (b != 0) {
        printf("Result: %.2f\n", a / b);
    } else {
        printf("Error: Division by zero is not allowed.\n");
    }
}

int main() {
    int choice;
    while (1) {
        print_menu();
        printf("Choose an operation (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addition();
                break;
            case 2:
                subtraction();
                break;
            case 3:
                multiplication();
                break;
            case 4:
                division();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please select again.\n");
        }
    }
    
    return 0;
}