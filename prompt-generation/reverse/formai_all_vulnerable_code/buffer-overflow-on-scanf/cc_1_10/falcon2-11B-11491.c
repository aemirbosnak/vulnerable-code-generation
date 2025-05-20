//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: beginner-friendly
#include <stdio.h>

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}

// Function to subtract two numbers
int subtract(int a, int b) {
    return a - b;
}

// Function to multiply two numbers
int multiply(int a, int b) {
    return a * b;
}

// Function to divide two numbers
int divide(int a, int b) {
    if (b == 0) {
        printf("Cannot divide by zero\n");
        return -1;
    }
    return a / b;
}

int main() {
    // Ask the user for two numbers
    printf("Enter the first number: ");
    int num1 = scanf("%d", &num1);
    printf("Enter the second number: ");
    int num2 = scanf("%d", &num2);
    
    // Ask the user what operation they want to perform
    printf("Enter 1 for addition, 2 for subtraction, 3 for multiplication, or 4 for division: ");
    int choice = scanf("%d", &choice);
    
    // Perform the operation based on user input
    switch(choice) {
        case 1:
            printf("The sum of %d and %d is %d\n", num1, num2, add(num1, num2));
            break;
        case 2:
            printf("The difference of %d and %d is %d\n", num1, num2, subtract(num1, num2));
            break;
        case 3:
            printf("The product of %d and %d is %d\n", num1, num2, multiply(num1, num2));
            break;
        case 4:
            if(divide(num1, num2)!= -1) {
                printf("The quotient of %d and %d is %d\n", num1, num2, divide(num1, num2));
            } else {
                printf("Cannot divide by zero\n");
            }
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    
    return 0;
}