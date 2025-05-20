//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 100

void displayMenu() {
    printf("\n========= C Arithmetic Operations =========\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exit\n");
    printf("===========================================\n");
    printf("Select an option (1-6): ");
}

void performAddition() {
    int count;
    printf("How many numbers would you like to add? ");
    scanf("%d", &count);
    
    if (count < 1 || count > MAX_NUMBERS) {
        printf("Invalid count! Please choose between 1 and %d.\n", MAX_NUMBERS);
        return;
    }
    
    double numbers[MAX_NUMBERS];
    printf("Enter %d numbers:\n", count);
    
    double sum = 0;
    for (int i = 0; i < count; i++) {
        printf("Number %d: ", i + 1);
        scanf("%lf", &numbers[i]);
        sum += numbers[i];
    }
    
    printf("The sum is: %.2lf\n", sum);
}

void performSubtraction() {
    double a, b;
    
    printf("Enter two numbers for subtraction:\n");
    printf("First number: ");
    scanf("%lf", &a);
    printf("Second number: ");
    scanf("%lf", &b);
    
    double result = a - b;
    printf("The result of %.2lf - %.2lf is: %.2lf\n", a, b, result);
}

void performMultiplication() {
    int count;
    printf("How many numbers would you like to multiply? ");
    scanf("%d", &count);
    
    if (count < 1 || count > MAX_NUMBERS) {
        printf("Invalid count! Please choose between 1 and %d.\n", MAX_NUMBERS);
        return;
    }
    
    double numbers[MAX_NUMBERS];
    printf("Enter %d numbers:\n", count);
    
    double product = 1;
    for (int i = 0; i < count; i++) {
        printf("Number %d: ", i + 1);
        scanf("%lf", &numbers[i]);
        product *= numbers[i];
    }
    
    printf("The product is: %.2lf\n", product);
}

void performDivision() {
    double a, b;
    
    printf("Enter two numbers for division:\n");
    printf("Numerator: ");
    scanf("%lf", &a);
    printf("Denominator: ");
    scanf("%lf", &b);
    
    if (b == 0) {
        printf("Error: Division by zero is undefined!\n");
        return;
    }
    
    double result = a / b;
    printf("The result of %.2lf / %.2lf is: %.2lf\n", a, b, result);
}

void performModulus() {
    int a, b;
    
    printf("Enter two integer numbers for modulus:\n");
    printf("First number: ");
    scanf("%d", &a);
    printf("Second number: ");
    scanf("%d", &b);
    
    if (b == 0) {
        printf("Error: Modulus by zero is undefined!\n");
        return;
    }
    
    int result = a % b;
    printf("The result of %d %% %d is: %d\n", a, b, result);
}

int main() {
    int choice;
    
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
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please select a number between 1 and 6.\n");
        }
    }
    
    return 0;
}