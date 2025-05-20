//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define NUM_BITS 8
#define NUM_BYTES (NUM_BITS/8)

void print_binary(unsigned char c) {
    for (int i = NUM_BITS-1; i >= 0; i--) {
        printf("%d", (c >> i) & 1);
    }
    printf("\n");
}

unsigned char get_binary_input() {
    unsigned char binary[NUM_BYTES];
    printf("Enter a binary number (up to %d bits):\n", NUM_BITS);
    for (int i = 0; i < NUM_BYTES; i++) {
        scanf("%c", &binary[i]);
    }
    unsigned char result = 0;
    for (int i = 0; i < NUM_BYTES; i++) {
        result |= binary[i] << (i*8);
    }
    return result;
}

int main() {
    unsigned char num1 = get_binary_input();
    unsigned char num2 = get_binary_input();
    unsigned char result;
    printf("Enter operation (+, -, *, /):\n");
    char op = getchar();
    switch(op) {
        case '+':
            result = num1 | num2;
            break;
        case '-':
            result = num1 & ~num2;
            break;
        case '*':
            result = 0;
            for (int i = 0; i < NUM_BITS; i++) {
                if ((num1 >> i) & 1 && (num2 >> i) & 1) {
                    result |= 1 << i;
                }
            }
            break;
        case '/':
            result = 0;
            for (int i = NUM_BITS-1; i >= 0; i--) {
                if (num2 >> i == 1) {
                    result |= (num1 >> (NUM_BITS-1-i)) & 1;
                }
            }
            break;
        default:
            printf("Invalid operation.\n");
            return 1;
    }
    printf("Result: ");
    print_binary(result);
    return 0;
}