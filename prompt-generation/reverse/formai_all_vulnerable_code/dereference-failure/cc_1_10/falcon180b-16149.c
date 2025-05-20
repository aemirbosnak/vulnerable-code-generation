//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define NUM_BITS 32
#define NUM_BYTES (NUM_BITS / 8)

unsigned int get_bit(unsigned char *bytes, int bit_num) {
    int byte_num = bit_num / NUM_BYTES;
    int bit_in_byte = bit_num % NUM_BYTES;

    return (bytes[byte_num] >> bit_in_byte) & 0x1;
}

void set_bit(unsigned char *bytes, int bit_num, int value) {
    int byte_num = bit_num / NUM_BYTES;
    int bit_in_byte = bit_num % NUM_BYTES;

    if (value == 0) {
        bytes[byte_num] &= ~(1 << bit_in_byte);
    } else {
        bytes[byte_num] |= (1 << bit_in_byte);
    }
}

int main() {
    unsigned char bytes[NUM_BYTES];
    for (int i = 0; i < NUM_BYTES; i++) {
        bytes[i] = 0;
    }

    printf("Enter a binary number (up to %d bits): ", NUM_BITS);
    scanf("%s", bytes);

    int num_bits = strlen(bytes);
    if (num_bits > NUM_BITS) {
        printf("Error: Binary number must be %d bits or less\n", NUM_BITS);
        exit(1);
    }

    for (int i = 0; i < NUM_BYTES; i++) {
        if (i < num_bits) {
            printf("%d", get_bit(bytes, i));
        } else {
            printf("0");
        }
    }

    printf("\n");

    return 0;
}