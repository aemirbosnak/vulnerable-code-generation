//FormAI DATASET v1.0 Category: Bitwise operations ; Style: single-threaded
#include<stdio.h>

void set_bit(int *num, int pos) {
    *num |= (1<<pos);
}

void clear_bit(int *num, int pos) {
    *num &= ~(1<<pos);
}

int get_bit(int num, int pos) {
    return (num & (1<<pos))>>pos;
}

void print_bits(int num) {
    for(int i=31;i>=0;i--) {
        printf("%d", get_bit(num, i));
    }
    printf("\n");
}

int main() {
    int num1 = 135, num2 = 167;
    printf("Number 1: ");
    print_bits(num1);
    printf("Number 2: ");
    print_bits(num2);

    printf("\nSetting 3rd bit of number 1:\n");
    set_bit(&num1, 3);
    printf("Number 1 after setting bit: ");
    print_bits(num1);

    printf("\nClearing 5th bit of number 2:\n");
    clear_bit(&num2, 5);
    printf("Number 2 after clearing bit: ");
    print_bits(num2);

    printf("\nXOR operation between number 1 and number 2:\n");
    int xor_result = num1^num2;
    printf("Result after XOR: ");
    print_bits(xor_result);

    printf("\nLeft shift operation on number 1:\n");
    int shift_result = num1<<2;
    printf("Result after shift: ");
    print_bits(shift_result);

    printf("\nRight shift operation on number 2:\n");
    shift_result = num2>>3;
    printf("Result after shift: ");
    print_bits(shift_result);

    return 0;
}