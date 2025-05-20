//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void print_binary(int num);
int get_random_number(int min, int max);
void bitwise_operations(int num);

int main() {
    int num;
    srand(time(NULL)); // Seed the random number generator

    printf("Enter a number between 0 and 255: ");
    scanf("%d", &num);

    if (num < 0 || num > 255) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Random number: %d\n", get_random_number(0, num));
    printf("Binary representation of %d: ", num);
    print_binary(num);

    bitwise_operations(num);

    return 0;
}

// Print the binary representation of a number
void print_binary(int num) {
    int i = 1;
    while (num > 0) {
        if (num % 2 == 1) {
            printf("1");
        } else {
            printf("0");
        }
        num /= 2;
        i++;
        if (i % 8 == 0) {
            printf("\n");
        }
    }
}

// Generate a random number between min and max (inclusive)
int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Perform bitwise operations on a number
void bitwise_operations(int num) {
    printf("\nBitwise operations:\n");

    // Bitwise AND
    printf("Bitwise AND with 0b10101010: ");
    printf("%d\n", num & 0b10101010);

    // Bitwise OR
    printf("Bitwise OR with 0b10101010: ");
    printf("%d\n", num | 0b10101010);

    // Bitwise XOR
    printf("Bitwise XOR with 0b10101010: ");
    printf("%d\n", num ^ 0b10101010);

    // Bitwise NOT
    printf("Bitwise NOT: ");
    printf("%d\n", ~num);

    // Bitwise left shift
    printf("Bitwise left shift by 4: ");
    printf("%d\n", num << 4);

    // Bitwise right shift
    printf("Bitwise right shift by 4: ");
    printf("%d\n", num >> 4);
}