//FormAI DATASET v1.0 Category: Arithmetic ; Style: brave
#include <stdio.h>

// Function to add two numbers 
int add(int x, int y) 
{ 
    return x + y; 
}

// Function to subtract two numbers 
int subtract(int x, int y) 
{ 
    return x - y; 
} 

// Function to multiply two numbers 
int multiply(int x, int y) 
{ 
    return x * y; 
} 

// Function to divide two numbers 
float divide(float x, float y) 
{ 
    if (y == 0) 
    { 
        printf("Error: Divide by zero is not allowed.\n"); 
        return -1; 
    } 
    else
    { 
        return x / y; 
    } 
} 

// Function to calculate the square of a number 
int square(int x) 
{ 
    return x * x; 
} 

// Main function 
int main() 
{ 
    int choice, num1, num2, result_int, square_num;
    float result_float;

    printf("Welcome to BRAVE Calculator!!\n\n"); 

    printf("Enter a choice from the following:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Square\n6. Exit\n");

    do
    {
        printf("Enter your choice: "); 
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
                printf("Enter two numbers to add: ");
                scanf("%d %d", &num1, &num2);
                result_int = add(num1, num2);
                printf("The sum of %d and %d is: %d\n", num1, num2, result_int);
                break;

            case 2:
                printf("Enter two numbers to subtract: ");
                scanf("%d %d", &num1, &num2);
                result_int = subtract(num1, num2);
                printf("The difference between %d and %d is: %d\n", num1, num2, result_int);
                break;

            case 3:
                printf("Enter two numbers to multiply: ");
                scanf("%d %d", &num1, &num2);
                result_int = multiply(num1, num2);
                printf("The product of %d and %d is: %d\n", num1, num2, result_int);
                break;

            case 4:
                printf("Enter two numbers to divide: ");
                scanf("%d %d", &num1, &num2);
                result_float = divide(num1, num2);
                if(result_float != -1) 
                { 
                    printf("The quotient of %d and %d is: %f\n", num1, num2, result_float);
                } 
                break;

            case 5:
                printf("Enter a number to square: ");
                scanf("%d", &num1);
                square_num = square(num1);
                printf("The square of %d is: %d\n", num1, square_num);
                break;

            case 6:
                printf("Thank you for using BRAVE Calculator!!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } 
    while(choice != 6); 

    return 0;
}