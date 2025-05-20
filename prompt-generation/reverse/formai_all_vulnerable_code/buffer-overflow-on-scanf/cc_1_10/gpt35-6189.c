//FormAI DATASET v1.0 Category: Arithmetic ; Style: all-encompassing
// This is a program that performs arithmetic operations on two numbers
#include <stdio.h>

// Declare the main function
int main() {

    // Declare variables for the numbers and the result
    int num1, num2, result;
    
    //Get input values from user
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Perform addition
    result = num1 + num2;
    printf("%d + %d = %d\n", num1, num2, result);
    
    // Perform subtraction
    result = num1 - num2;
    printf("%d - %d = %d\n", num1, num2, result);
    
    // Perform multiplication
    result = num1 * num2;
    printf("%d * %d = %d\n", num1, num2, result);
    
    // Perform division
    if(num2 != 0) {
        result = num1 / num2;
        printf("%d / %d = %d\n", num1, num2, result);
    } else {
        printf("Cannot divide by zero\n");
    }
    
    // Perform modulo operation
    if(num2 != 0) {
        result = num1 % num2;
        printf("%d %% %d = %d\n", num1, num2, result);
    } else {
        printf("Cannot find remainder when dividing by zero\n");
    }
    
    // Increment the first number
    num1++;
    printf("Incrementing %d gives %d\n", num1-1, num1);
    
    // Decrement the second number
    num2--;
    printf("Decrementing %d gives %d\n", num2+1, num2);

    return 0;
}