//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

void displayBits(int num) {
    printf("The binary representation of %d is: ", num);
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0) printf(" "); // Add space every byte for readability
    }
    printf("\n");
}

int main() {
    int num1, num2;
    
    printf("Welcome to the Bitwise Operations Explorer!\n");
    printf("Let's discover how bitwise operations work in C.\n");
    
    // Gathering two numbers from the user
    printf("Please enter the first integer: ");
    scanf("%d", &num1);
    
    printf("Please enter the second integer: ");
    scanf("%d", &num2);

    // Displaying their binary representation
    displayBits(num1);
    displayBits(num2);
    
    // Bitwise AND
    int andResult = num1 & num2;
    printf("Bitwise AND (%d & %d) = %d\n", num1, num2, andResult);
    displayBits(andResult);
    
    // Bitwise OR
    int orResult = num1 | num2;
    printf("Bitwise OR (%d | %d) = %d\n", num1, num2, orResult);
    displayBits(orResult);
    
    // Bitwise XOR
    int xorResult = num1 ^ num2;
    printf("Bitwise XOR (%d ^ %d) = %d\n", num1, num2, xorResult);
    displayBits(xorResult);
    
    // Bitwise NOT
    int notNum1 = ~num1;
    int notNum2 = ~num2;
    printf("Bitwise NOT (~%d) = %d\n", num1, notNum1);
    displayBits(notNum1);
    printf("Bitwise NOT (~%d) = %d\n", num2, notNum2);
    displayBits(notNum2);
    
    // Left Shift
    printf("Left shifting %d by 1 gives us: %d\n", num1, (num1 << 1));
    displayBits(num1 << 1);
    
    printf("Left shifting %d by 1 gives us: %d\n", num2, (num2 << 1));
    displayBits(num2 << 1);

    // Right Shift
    printf("Right shifting %d by 1 gives us: %d\n", num1, (num1 >> 1));
    displayBits(num1 >> 1);
    
    printf("Right shifting %d by 1 gives us: %d\n", num2, (num2 >> 1));
    displayBits(num2 >> 1);

    // Experiment with combinations
    int experimentResult = (num1 & num2) | (num1 ^ num2);
    printf("Combining AND and XOR: ((%d & %d) | (%d ^ %d)) = %d\n", num1, num2, num1, num2, experimentResult);
    displayBits(experimentResult);

    // Final exploration
    printf("What happens when we OR the result of AND with a NOT?\n");
    int finalResult = andResult | notNum1;
    printf("Result: (%d & %d) | ~%d = %d\n", num1, num2, num1, finalResult);
    displayBits(finalResult);

    printf("Thank you for exploring bitwise operations with us!\n");
    return 0;
}