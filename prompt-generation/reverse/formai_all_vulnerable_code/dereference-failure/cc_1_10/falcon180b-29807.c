//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to convert decimal to binary
void decToBin(int dec) {
    char bin[33]; // Maximum 32 bits + 1 for null terminator
    int i = 0;
    while (dec > 0) {
        bin[i++] = (dec % 2) + '0';
        dec /= 2;
    }
    bin[i] = '\0';
    printf("%s\n", bin);
}

// Function to convert binary to decimal
int binToDec(char *bin) {
    int dec = 0, base = 1;
    while (*bin) {
        dec += (*bin - '0') * base;
        base *= 2;
        bin++;
    }
    return dec;
}

// Function to generate a random binary number
void genRandomBin(int numBits) {
    srand(time(NULL));
    char *bin = (char *)malloc(numBits + 1);
    for (int i = 0; i < numBits; i++) {
        bin[i] = rand() % 2 + '0';
    }
    bin[numBits] = '\0';
    printf("Random binary number: %s\n", bin);
}

// Function to count the number of 1's in a binary number
int countOnes(char *bin) {
    int count = 0;
    while (*bin) {
        if (*bin == '1') {
            count++;
        }
        bin++;
    }
    return count;
}

int main() {
    // Example usage
    decToBin(42);
    binToDec("101010");
    genRandomBin(8);
    countOnes("11010100");
    return 0;
}