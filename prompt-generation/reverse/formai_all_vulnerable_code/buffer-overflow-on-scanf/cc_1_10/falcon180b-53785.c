//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 1000

// function to count the number of bits set in a given number
int countBits(unsigned int n) {
    int count = 0;
    while (n > 0) {
        if (n & 1) {
            count++;
        }
        n >>= 1;
    }
    return count;
}

// function to print the binary representation of a given number
void printBinary(unsigned int n) {
    printf("Binary representation: ");
    for (int i = sizeof(unsigned int) * CHAR_BIT - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

// function to find the smallest number that has a given number of bits set
unsigned int findSmallest(int numBitsSet) {
    unsigned int smallest = 0;
    for (int i = 0; i < numBitsSet; i++) {
        smallest |= (1 << i);
    }
    return smallest;
}

// function to find the largest number that has a given number of bits set
unsigned int findLargest(int numBitsSet) {
    unsigned int largest = (~0U) >> (sizeof(unsigned int) * CHAR_BIT - numBitsSet);
    return largest;
}

int main() {
    int numBitsSet;
    printf("Enter the number of bits to set: ");
    scanf("%d", &numBitsSet);

    // find the smallest and largest numbers that have the given number of bits set
    unsigned int smallest = findSmallest(numBitsSet);
    unsigned int largest = findLargest(numBitsSet);

    // print the smallest and largest numbers
    printf("Smallest number with %d bits set: ", numBitsSet);
    printBinary(smallest);
    printf("Largest number with %d bits set: ", numBitsSet);
    printBinary(largest);

    return 0;
}