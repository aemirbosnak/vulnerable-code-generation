//Falcon2-11B DATASET v1.0 Category: Bitwise operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is power of two
int isPowerOfTwo(int num) {
    if (num == 0)
        return 1;
    if (num & (num - 1))
        return 0;
    return 1;
}

// Function to print the binary representation of a number
void printBinary(int num) {
    int binNum = 0;
    while (num > 0) {
        binNum = binNum * 2 + num % 2;
        num = num / 2;
    }
    printf("%d (%d)\n", num, binNum);
}

// Function to check if two numbers are equal in binary representation
int areEqualBinary(int num1, int num2) {
    return (num1 == num2) && (isPowerOfTwo(num1) && isPowerOfTwo(num2));
}

// Function to count the number of bits set in a number
int countSetBits(int num) {
    int count = 0;
    while (num) {
        num &= (num - 1);
        count++;
    }
    return count;
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Check if the numbers are equal in binary representation
    if (areEqualBinary(num1, num2)) {
        printf("The numbers are equal in binary representation.\n");
    } else {
        printf("The numbers are not equal in binary representation.\n");
    }

    // Count the number of bits set in the numbers
    int setBitsNum1 = countSetBits(num1);
    int setBitsNum2 = countSetBits(num2);
    if (setBitsNum1 == setBitsNum2) {
        printf("The numbers have the same number of set bits.\n");
    } else {
        printf("The numbers do not have the same number of set bits.\n");
    }

    // Print the binary representation of the numbers
    printBinary(num1);
    printf("\n");
    printBinary(num2);

    return 0;
}