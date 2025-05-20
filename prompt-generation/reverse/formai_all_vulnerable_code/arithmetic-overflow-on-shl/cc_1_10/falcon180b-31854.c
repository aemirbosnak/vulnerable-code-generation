//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define BIT_COUNT 8
#define MAX_VALUE (1 << BIT_COUNT)

void print_binary(int value) {
    char binary[BIT_COUNT + 1] = {0};
    int i = 0;

    for (; value > 0; value >>= 1, ++i) {
        binary[i] = '0' + (value & 1);
    }

    printf("Binary representation: %s\n", binary);
}

void set_bit(int *value, int position) {
    *value |= (1 << position);
}

void clear_bit(int *value, int position) {
    *value &= ~(1 << position);
}

void toggle_bit(int *value, int position) {
    *value ^= (1 << position);
}

void shift_left(int *value, int count) {
    *value <<= count;
}

void shift_right(int *value, int count) {
    *value >>= count;
}

int main() {
    int value = 0;

    printf("Enter a value (0 - %d): ", MAX_VALUE);
    scanf("%d", &value);

    print_binary(value);

    set_bit(&value, 3);
    clear_bit(&value, 5);
    toggle_bit(&value, 7);

    printf("\nValue after bit manipulation: %d\n", value);

    shift_left(&value, 2);
    shift_right(&value, 3);

    printf("Value after shifting: %d\n", value);

    return 0;
}