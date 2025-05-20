//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>

//Function declarations
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int modulus(int a, int b);
int power(int a, int b);
int factorial(int a);

int main() {
    int choice, num1, num2, result;
    printf("Welcome to the Post-Apocalyptic Scientific Calculator\n");
    do {
        //Menu options
        printf("\n\nWhich operation do you want to perform?\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Modulus\n6. Power\n7. Factorial\n8. Exit\n");
        printf("Enter your choice (1-8): ");
        scanf("%d", &choice);
        
        //User inputs
        switch(choice) {
            case 1:
                printf("\nEnter two numbers to add: ");
                scanf("%d %d", &num1, &num2);
                result = add(num1, num2);
                printf("\nResult: %d", result);
                break;
                
            case 2:
                printf("\nEnter two numbers to subtract: ");
                scanf("%d %d", &num1, &num2);
                result = subtract(num1, num2);
                printf("\nResult: %d", result);
                break;
                
            case 3:
                printf("\nEnter two numbers to multiply: ");
                scanf("%d %d", &num1, &num2);
                result = multiply(num1, num2);
                printf("\nResult: %d", result);
                break;
                
            case 4:
                printf("\nEnter two numbers to divide: ");
                scanf("%d %d", &num1, &num2);
                result = divide(num1, num2);
                printf("\nResult: %d", result);
                break;
                
            case 5:
                printf("\nEnter two numbers to find the modulus: ");
                scanf("%d %d", &num1, &num2);
                result = modulus(num1, num2);
                printf("\nResult: %d", result);
                break;
                
            case 6:
                printf("\nEnter two numbers to perform power operation: ");
                scanf("%d %d", &num1, &num2);
                result = power(num1, num2);
                printf("\nResult: %d", result);
                break;
                
            case 7:
                printf("\nEnter a number to find its factorial: ");
                scanf("%d", &num1);
                result = factorial(num1);
                printf("\nResult: %d", result);
                break;
                
            case 8:
                printf("\nExiting the Post-Apocalyptic Scientific Calculator...");
                exit(0);
                
            default:
                printf("\nInvalid input! Please choose between 1-8.");
                break;
        }
    } while(choice);

    return 0;
}

//Function definitions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if(b == 0) { //Divide by zero error
        printf("\nCannot divide by zero!");
        return -1;
    }
    return (a/b);
}

int modulus(int a, int b) {
    if(b == 0) { //Divide by zero error
        printf("\nCannot divide by zero!");
        return -1;
    }
    return (a%b);
}

int power(int a, int b) {
    int result = 1;
    for(int i=1; i<=b; i++) {
        result *= a;
    }
    return result;
}

int factorial(int a) {
    int result = 1;
    for(int i=1; i<=a; i++) {
        result *= i;
    }
    return result;
}