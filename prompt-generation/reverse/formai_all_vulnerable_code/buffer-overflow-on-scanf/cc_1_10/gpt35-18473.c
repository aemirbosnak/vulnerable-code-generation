//FormAI DATASET v1.0 Category: Bitwise operations ; Style: genious
/**
 * Program that demonstrates the bit manipulation techniques in C
 * Author: Genius Chatbot
 * Date: 1st April, 2022
**/

#include <stdio.h>

/* Function to display the binary representation of a number */
void displayBinary(unsigned int num) {
    for(int i=31 ; i>=0 ; i--) {
        putchar((num & (1<<i)) ? '1' : '0');
        if(i % 4 == 0) putchar(' ');
    }
    putchar('\n');
}

int main() {

    unsigned int a, b;

    printf("Enter value of a:");
    scanf("%u", &a);
    printf("Enter value of b:");
    scanf("%u", &b);
    printf("\nDisplaying binary representation of a and b:\n");
    displayBinary(a);
    displayBinary(b);

    printf("\nPerforming various bitwise operations...\n");

    /* Bitwise AND operation*/
    printf("\nThe result of a & b:\n");
    displayBinary(a & b);

    /* Bitwise OR operation*/ 
    printf("\nThe result of a | b:\n");
    displayBinary(a | b);

    /* Bitwise XOR operation*/
    printf("\nThe result of a ^ b:\n");
    displayBinary(a ^ b);

    /* Bitwise Complement operation*/
    printf("\nThe complement of a:\n");
    displayBinary(~a);

    /* Left Shift operation*/
    printf("\nThe result of a << 2:\n");
    displayBinary(a <<= 2);

    /* Right Shift operation*/
    printf("\nThe result of b >> 3:\n");
    displayBinary(b >>= 3);

    /* Checking if a is even or odd using bitwise AND */
    printf("\nChecking if a is even or odd using bitwise AND:\n");
    if(a & 1) printf("a is odd\n");
    else printf("a is even\n");

    /* Swapping two numbers using XOR */
    printf("\nSwapping values of a and b using XOR:\n");
    a ^= b;
    b ^= a;
    a ^= b;
    printf("a = %u, b = %u\n", a, b);

    /* Counting the number of bits set in a number */
    printf("\nCounting the number of bits set in a:\n");
    unsigned int count = 0, temp = a;
    while(temp) {
        temp &= (temp-1);
        count++;
    }
    printf("The number of bits set in a is %u\n", count);

    return 0;
}