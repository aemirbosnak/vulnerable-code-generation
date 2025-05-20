//FormAI DATASET v1.0 Category: Bitwise operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Function to print binary representation of an integer
void printBinary(unsigned int num) {
    int i;
    printf("Binary Representation: ");
    for (i = 31; i >= 0; i--)
        (num & (1 << i)) ? printf("1") : printf("0");
    printf("\n");
}

// Function to perform XOR with a given key
void xorEncrypt(char *str, char *key) {
    int i, j = 0, keyLen = strlen(key);
    for (i = 0; str[i]; i++) {
        str[i] ^= key[j];
        j = ++j % keyLen;
    }
}

int main() {
    unsigned int a = 60; // Binary: 0011 1100
    unsigned int b = 13; // Binary: 0000 1101
    unsigned int result;

    printf("Input A: %u\n", a);
    printf("Input B: %u\n", b);

    // Perform bitwise AND operation
    result = a & b;
    printf("Result of A & B: %u\n", result);
    printBinary(result);

    // Perform bitwise OR operation
    result = a | b;
    printf("Result of A | B: %u\n", result);
    printBinary(result);

    // Perform bitwise XOR operation
    result = a ^ b;
    printf("Result of A ^ B: %u\n", result);
    printBinary(result);

    // Perform bitwise Left Shift operation
    result = a << 2;
    printf("Result of A << 2: %u\n", result);
    printBinary(result);

    // Perform bitwise Right Shift operation
    result = a >> 2;
    printf("Result of A >> 2: %u\n", result);
    printBinary(result);

    // Perform bitwise NOT operation
    result = ~a;
    printf("Result of ~A: %u\n", result);
    printBinary(result);

    char str[] = "Hello World!";
    char key[] = "SecretKey";

    printf("String before encryption: %s\n", str);
    xorEncrypt(str, key);
    printf("String after encryption: %s\n", str);
    xorEncrypt(str, key);
    printf("String after decryption: %s\n", str);

    return 0;
}