//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int randnum(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a binary number
void printbinary(int num) {
    for (int i = 31; i >= 0; i--) {
        if (num & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
}

// Function to perform bitwise operations
void bitwiseops(int num1, int num2) {
    printf("Bitwise operations on %d and %d:\n", num1, num2);
    printf("AND: ");
    printf("%d\n", num1 & num2);
    printf("OR: ");
    printf("%d\n", num1 | num2);
    printf("XOR: ");
    printf("%d\n", num1 ^ num2);
    printf("NOT: ");
    printf("%d\n", ~num1);
}

int main() {
    srand(time(NULL));
    int num1 = randnum(0, 100);
    int num2 = randnum(0, 100);

    printf("Random numbers:\n");
    printf("num1: %d\n", num1);
    printf("num2: %d\n", num2);

    printf("Binary representation of num1: ");
    printbinary(num1);
    printf("\n");

    printf("Bitwise operations:\n");
    bitwiseops(num1, num2);

    return 0;
}