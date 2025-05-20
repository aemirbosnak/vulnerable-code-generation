//FormAI DATASET v1.0 Category: Arithmetic ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* Ken Thompson inspired program to perform arithmetic operations in C */

// Function to add two numbers
float add(float a, float b){
    return a + b;
}

// Function to subtract two numbers
float subtract(float a, float b){
    return a - b;
}

// Function to multiply two numbers
float multiply(float a, float b){
    return a * b;
}

// Function to divide two numbers
float divide(float a, float b){
    if(b == 0){
        printf("Error! Cannot divide by zero.");
        exit(0); // exit the program
    }
    else{
        return a / b;
    }
}

// Function to calculate the power of a number
float power(float a, int b){
    float result = a;
    for(int i = 1; i < b; i++){
        result = result * a;
    }
    return result;
}

int main(){
    int choice;
    float num1, num2, result;
    int pow;

    printf("Welcome to the Arithmetic Program by Ken Thompson!\n");
    printf("Please select an operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power Calculation\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("Enter two numbers to add: ");
            scanf("%f %f", &num1, &num2);
            result = add(num1, num2);
            printf("Result: %f", result);
            break;

        case 2:
            printf("Enter two numbers to subtract: ");
            scanf("%f %f", &num1, &num2);
            result = subtract(num1, num2);
            printf("Result: %f", result);
            break;

        case 3:
            printf("Enter two numbers to multiply: ");
            scanf("%f %f", &num1, &num2);
            result = multiply(num1, num2);
            printf("Result: %f", result);
            break;

        case 4:
            printf("Enter two numbers to divide: ");
            scanf("%f %f", &num1, &num2);
            result = divide(num1, num2);
            printf("Result: %f", result);
            break;

        case 5:
            printf("Enter a number: ");
            scanf("%f", &num1);
            printf("Enter the power: ");
            scanf("%d", &pow);
            result = power(num1, pow);
            printf("Result: %f", result);
            break;

        default:
            printf("Invalid choice! Please try again.");
            break;
    }

    return 0;
}