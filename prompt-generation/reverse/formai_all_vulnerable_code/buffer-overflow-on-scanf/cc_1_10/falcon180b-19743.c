//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BITS 32

// Function to print the binary representation of a number
void print_binary(unsigned int num) {
    for (int i = NUM_BITS - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

// Function to generate a random number with the given number of bits
unsigned int generate_random_number(int bits) {
    unsigned int max_value = (1 << bits) - 1;
    unsigned int rand_num = rand() % max_value;
    return rand_num;
}

// Function to perform bitwise operations on two numbers
void bitwise_operations(unsigned int num1, unsigned int num2, char operation) {
    switch (operation) {
        case '&':
            printf("Bitwise AND: %d\n", num1 & num2);
            break;
        case '|':
            printf("Bitwise OR: %d\n", num1 | num2);
            break;
        case '^':
            printf("Bitwise XOR: %d\n", num1 ^ num2);
            break;
        case '~':
            printf("Bitwise NOT: %d\n", ~num1);
            break;
        case '<<':
            printf("Left shift: %d\n", num1 << num2);
            break;
        case '>>':
            printf("Right shift: %d\n", num1 >> num2);
            break;
    }
}

int main() {
    srand(time(NULL));

    // Generate two random numbers with 8 bits each
    unsigned int num1 = generate_random_number(8);
    unsigned int num2 = generate_random_number(8);

    // Print the binary representation of the numbers
    printf("Number 1: ");
    print_binary(num1);
    printf("\nNumber 2: ");
    print_binary(num2);

    // Perform bitwise operations on the numbers
    char operation;
    while (1) {
        printf("\nEnter the operation you want to perform (AND, OR, XOR, NOT, LS, RS): ");
        scanf("%c", &operation);
        bitwise_operations(num1, num2, operation);
        printf("\nDo you want to perform another operation? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    return 0;
}