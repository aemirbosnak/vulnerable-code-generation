//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_BITS 32

// Function to calculate the number of bits in a given integer
int countBits(int num) {
    int count = 0;
    while (num > 0) {
        num >>= 1;
        count++;
    }
    return count;
}

// Function to reverse the order of bits in a given integer
int reverseBits(int num) {
    char* str = (char*)&num;
    int len = sizeof(int);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    return *(int*)str;
}

// Function to check if a given integer is a power of 2
int isPowerOfTwo(int num) {
    if (num == 0) {
        return 0;
    }
    while (num > 1) {
        if (num % 2!= 0) {
            return 0;
        }
        num /= 2;
    }
    return 1;
}

// Function to find the highest set bit in a given integer
int highestSetBit(int num) {
    int count = 0;
    while (num > 0) {
        count++;
        num >>= 1;
    }
    return count - 1;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Calculate the number of bits in the given integer
    int numBits = countBits(num);
    printf("Number of bits in %d: %d\n", num, numBits);

    // Reverse the order of bits in the given integer
    int reversedNum = reverseBits(num);
    printf("Reversed bits of %d: %d\n", num, reversedNum);

    // Check if the given integer is a power of 2
    int isPower = isPowerOfTwo(num);
    printf("Is %d a power of 2? %s\n", num, isPower? "Yes" : "No");

    // Find the highest set bit in the given integer
    int highestSetBitNum = highestSetBit(num);
    printf("Highest set bit in %d is %d\n", num, highestSetBitNum);

    return 0;
}