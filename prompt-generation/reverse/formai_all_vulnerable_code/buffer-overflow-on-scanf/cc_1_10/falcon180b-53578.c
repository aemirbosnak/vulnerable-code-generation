//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: excited
#include<stdio.h>
#include<stdlib.h>

// Function to swap two numbers using bitwise XOR
void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

// Function to print a binary number
void print_binary(int num) {
    int i = 0;
    while (num > 0) {
        printf("%d", num & 1);
        num >>= 1;
        i++;
        if (i == 8) {
            printf("\n");
            i = 0;
        }
    }
}

// Function to print a decimal number
void print_decimal(int num) {
    printf("%d\n", num);
}

// Function to print a hexadecimal number
void print_hexadecimal(int num) {
    char hex[10];
    sprintf(hex, "%X", num);
    printf("%s\n", hex);
}

// Function to perform bitwise operations
void bitwise_operations(int num1, int num2) {
    int and_result, or_result, xor_result;
    and_result = num1 & num2;
    or_result = num1 | num2;
    xor_result = num1 ^ num2;
    printf("Bitwise AND: ");
    print_decimal(and_result);
    printf("Bitwise OR: ");
    print_decimal(or_result);
    printf("Bitwise XOR: ");
    print_decimal(xor_result);
}

// Function to perform bit manipulation
void bit_manipulation(int num) {
    int i = 0;
    while (num > 0) {
        printf("%d", num & 1);
        num >>= 1;
        i++;
        if (i == 8) {
            printf("\n");
            i = 0;
        }
    }
}

int main() {
    int num1, num2, choice;
    printf("Enter a decimal number: ");
    scanf("%d", &num1);
    printf("Enter another decimal number: ");
    scanf("%d", &num2);
    printf("Enter 1 for bitwise operations or 2 for bit manipulation: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            bitwise_operations(num1, num2);
            break;
        case 2:
            bit_manipulation(num1);
            break;
        default:
            printf("Invalid choice!");
    }

    return 0;
}