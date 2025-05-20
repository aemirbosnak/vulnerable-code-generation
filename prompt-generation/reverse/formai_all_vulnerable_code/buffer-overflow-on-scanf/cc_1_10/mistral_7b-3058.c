//MISTRAL-7B DATASET v1.0 Category: Data recovery tool ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define N 7 // Number of check bits

void generate_parity_bits(unsigned char data, unsigned char *parity) {
    int i;
    for (i = 0; i < N; i++) {
        parity[i] = data ^ (1 << i);
    }
}

void correct_single_bit_error(unsigned char data, unsigned char *parity) {
    int i;
    unsigned char error = 0;
    for (i = 0; i < N; i++) {
        error ^= parity[i] ^ (data & (1 << i));
    }
    data ^= error;
}

int main() {
    unsigned char data, i;
    unsigned char parity[N];

    printf("Enter data byte: ");
    scanf("%hhu", &data);

    generate_parity_bits(data, parity);

    printf("\nData byte: %hhu\n", data);
    printf("Parity bits:");
    for (i = 0; i < N; i++) {
        printf(" %hhu", parity[i]);
    }
    printf("\n");

    // Simulate a single bit error
    data ^= (1 << (rand() % 8));

    printf("\nCorrupted data byte: %hhu\n", data);

    correct_single_bit_error(data, parity);

    printf("\nRecovered data byte: %hhu\n", data);

    return 0;
}