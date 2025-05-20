//FormAI DATASET v1.0 Category: Arithmetic ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

/* This program is going to blow your mind! With its amazing capabilities, 
   it can perform complex arithmetic operations that will make your jaw drop */
   
int main() {
    int num1, num2, sum, diff, mul, div, mod;   // variables used for arithmetic operations

    printf("Welcome to the amazing arithmetic program. \n");
    printf("Please enter two integers to perform operations on: \n");
    scanf("%d %d", &num1, &num2);
    
    // performing arithmetic operations and printing the results
    sum = num1 + num2;
    diff = num1 - num2;
    mul = num1 * num2;
    div = num1 / num2;
    mod = num1 % num2;
    
    printf("\n The sum of %d and %d is: %d", num1, num2, sum);
    printf("\n The difference of %d and %d is: %d", num1, num2, diff);
    printf("\n The product of %d and %d is: %d", num1, num2, mul);
    printf("\n The quotient of %d and %d is: %d", num1, num2, div);
    printf("\n The remainder of %d and %d is: %d", num1, num2, mod);
    
    // user interaction, asking if they want to perform another calculation
    char choice;
    printf("\n Would you like to perform another calculation? (Y/N): ");
    scanf(" %c", &choice);
    
    if (choice == 'Y' || choice == 'y') {   // user wants to perform another calculation
    
        // asking for new integers
        printf("\n Please enter two integers to perform operations on: \n");
        scanf("%d %d", &num1, &num2);
        
        // performing arithmetic operations and printing the results
        sum = num1 + num2;
        diff = num1 - num2;
        mul = num1 * num2;
        if (num2 != 0) {   // checking if denominator is not zero
            div = num1 / num2;
            mod = num1 % num2;
            printf("\n The sum of %d and %d is: %d", num1, num2, sum);
            printf("\n The difference of %d and %d is: %d", num1, num2, diff);
            printf("\n The product of %d and %d is: %d", num1, num2, mul);
            printf("\n The quotient of %d and %d is: %d", num1, num2, div);
            printf("\n The remainder of %d and %d is: %d", num1, num2, mod);
        } else {
            // denominator is zero, cannot perform division and modulo operation
            printf("\n Cannot perform division and modulo operation on %d and 0", num1);
        }
    } else {   // user does not want to perform another calculation
        printf("\n Thank you for using the amazing arithmetic program! Goodbye! \n");
    }
    
    return 0;   // end of program
}