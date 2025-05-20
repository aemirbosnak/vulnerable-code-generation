//FormAI DATASET v1.0 Category: Bitwise operations ; Style: innovative
#include <stdio.h>

/* 
   This program showcases some innovative uses of bitwise operators in C programming language. 
   It takes an integer input from the user and then performs various bitwise operations on it.
   The program then displays the results of the bitwise operations on the screen.
*/

int main(void) {
    
    int input;  // variable to hold user input
    
    printf("Welcome to the Bitwise Operations Program!\n\n");
    
    // Prompt the user for an integer input
    printf("Please enter an integer: ");
    scanf("%d", &input);
    printf("\n");

    // Using the bitwise NOT operator (~) to invert all bits of the number
    printf("Inverting each bit of %d...\n", input);
    printf("%d becomes %d\n", input, ~input);
    printf("\n");

    // Using the bitwise OR operator (|) to set a specific bit of the number to 1
    int bitPosition;
    printf("Please enter the bit position you want to set to 1: ");
    scanf("%d", &bitPosition);
    int mask = 1 << bitPosition;
    printf("Setting bit position %d to 1 in %d...\n", bitPosition, input);
    printf("%d becomes %d\n", input, input | mask);
    printf("\n");

    // Using the bitwise AND operator (&) to check if a specific bit of the number is set to 1
    printf("Checking if bit position %d is set to 1 in %d...\n", bitPosition, input);
    printf("Bit position %d is %s set to 1 in %d\n", bitPosition, (input & mask) ? "" : "not", input);
    printf("\n");

    // Using the bitwise XOR operator (^) to toggle a specific bit of the number
    printf("Toggling bit position %d in %d...\n", bitPosition, input);
    printf("%d becomes %d\n", input, input ^ mask);
    printf("\n");

    // Using the bitwise shift operators (<< and >>) to shift the bits of the number by a certain amount
    int shiftAmount;
    printf("Please enter the amount of bits you want to shift the number by: ");
    scanf("%d", &shiftAmount);
    printf("Shifting %d by %d bits...\n", input, shiftAmount);
    printf("%d becomes %d (shift left)\n", input, input << shiftAmount);
    printf("%d becomes %d (shift right)\n", input, input >> shiftAmount);
    printf("\n");

    // Using bitwise operators to implement logical operations, like calculating the maximum and minimum of two numbers
    int num1, num2;
    printf("Please enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("Calculating the maximum and minimum of %d and %d...\n", num1, num2);
    int max = (num1 > num2) ? num1 : num2;
    int min = (num1 < num2) ? num1 : num2;
    printf("The maximum is %d\n", max);
    printf("The minimum is %d\n", min);

    printf("\nThank you for using the Bitwise Operations Program!\n");

    return 0;
}