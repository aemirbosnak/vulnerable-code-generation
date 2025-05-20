//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: accurate
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define BIT_SIZE(x) (CHAR_BIT * (sizeof(x) / sizeof(char)))

typedef struct {
    uint8_t a;
    uint16_t b;
    uint32_t c;
    uint64_t d;
} MyData;

void print_binary(uint32_t value) {
    int i;
    for (i = 31; i >= 0; i--) {
        putchar(value & (1 << i) ? '1' : '0');
        value <<= 1;
    }
    putchar('\n');
}

void apply_bitwise_operations(MyData data) {
    // Perform bitwise AND operation
    uint32_t and_result = data.a & data.b;
    print_binary(and_result);

    // Perform bitwise OR operation
    uint32_t or_result = data.a | data.b;
    print_binary(or_result);

    // Perform bitwise XOR operation
    uint32_t xor_result = data.a ^ data.b;
    print_binary(xor_result);

    // Perform bitwise NOT operation
    uint32_t not_result = ~data.a;
    print_binary(not_result);

    // Perform bitwise left shift operation
    uint32_t left_shift_result = data.a << 3;
    print_binary(left_shift_result);

    // Perform bitwise right shift operation
    uint32_t right_shift_result = data.a >> 3;
    print_binary(right_shift_result);

    // Perform bitwise zero fill right shift operation
    uint32_t zero_fill_right_shift_result = data.a >> 3;
    print_binary(zero_fill_right_shift_result);
}

int main() {
    MyData my_data = {.a = 0b11110111, .b = 0b01111011, .c = 0b1111111111111111, .d = 0b111111111111111111111111};
    printf("Original data:\n");
    print_binary(my_data.a);
    print_binary(my_data.b);
    print_binary(my_data.c);
    print_binary(my_data.d);

    printf("\nBitwise AND:\n");
    apply_bitwise_operations(my_data);

    printf("\nBitwise OR:\n");
    apply_bitwise_operations(my_data);

    printf("\nBitwise XOR:\n");
    apply_bitwise_operations(my_data);

    printf("\nBitwise NOT:\n");
    apply_bitwise_operations(my_data);

    printf("\nBitwise left shift:\n");
    apply_bitwise_operations(my_data);

    printf("\nBitwise right shift:\n");
    apply_bitwise_operations(my_data);

    printf("\nBitwise zero fill right shift:\n");
    apply_bitwise_operations(my_data);

    return 0;
}