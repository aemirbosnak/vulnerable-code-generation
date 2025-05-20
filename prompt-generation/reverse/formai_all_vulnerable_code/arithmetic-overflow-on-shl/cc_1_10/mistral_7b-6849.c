//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: ultraprecise
#include <stdint.h>
#include <stdio.h>

#define COUNTER_INIT 0x12345678
#define BIT_MASK_1   0x00000001
#define BIT_MASK_2   0x00000002
#define BIT_MASK_3   0x00000004
#define BIT_MASK_4   0x00000008
#define BIT_MASK_5   0x00000010
#define BIT_MASK_16  0x00010000
#define BIT_MASK_32  0x00100000

volatile uint32_t counter = COUNTER_INIT;

void set_bit(uint32_t *pCounter, uint32_t bitIndex) {
    uint32_t bitMask = 1 << bitIndex;
    *pCounter |= bitMask;
}

void clear_bit(uint32_t *pCounter, uint32_t bitIndex) {
    uint32_t bitMask = ~(1 << bitIndex);
    *pCounter &= bitMask;
}

void toggle_bit(uint32_t *pCounter, uint32_t bitIndex) {
    uint32_t bitMask = 1 << bitIndex;
    *pCounter ^= bitMask;
}

void check_bit(uint32_t *pCounter, uint32_t bitIndex) {
    uint32_t bitMask = 1 << bitIndex;
    if (*pCounter & bitMask) {
        printf("Bit %d is set\n", bitIndex);
    } else {
        printf("Bit %d is clear\n", bitIndex);
    }
}

void test_bit_operations() {
    printf("Initial counter value: %x\n", counter);

    // Set bit 0
    set_bit(&counter, 0);
    check_bit(&counter, 0);

    // Set bit 1
    set_bit(&counter, 1);
    check_bit(&counter, 1);

    // Clear bit 0
    clear_bit(&counter, 0);
    check_bit(&counter, 0);

    // Clear bit 1
    clear_bit(&counter, 1);
    check_bit(&counter, 1);

    // Toggle bit 0
    toggle_bit(&counter, 0);
    check_bit(&counter, 0);

    // Toggle bit 1
    toggle_bit(&counter, 1);
    check_bit(&counter, 1);

    // Set bit 16
    set_bit(&counter, 16);
    check_bit(&counter, 16);

    // Set bit 32
    set_bit(&counter, 32);
    check_bit(&counter, 32);

    printf("Final counter value: %x\n", counter);
}

int main() {
    test_bit_operations();
    while (1) {} // Infinite loop to prevent program termination
}