//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT_SIZE 1024
#define BITS_PER_BYTE 8

void get_binary(unsigned char *binary, const unsigned char *input, int length) {
    for (int i = 0; i < length; ++i) {
        binary[i / BITS_PER_BYTE] <<= (BITS_PER_BYTE - (i % BITS_PER_BYTE));
        binary[i / BITS_PER_BYTE] |= input[i];
    }
}

double entropy(const unsigned char *input, int length) {
    double entropy = 0.0;
    int counts[256] = { 0 };

    for (int i = 0; i < length; ++i) {
        ++counts[input[i]];
    }

    for (int i = 0; i < 256; ++i) {
        double p = (double)counts[i] / length;
        entropy += p * log2(p);
    }

    return entropy * -1;
}

int main() {
    unsigned char input[MAX_INPUT_SIZE];
    unsigned char binary[MAX_INPUT_SIZE / BITS_PER_BYTE + 1];

    printf("Enter input: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strlen(input) - 1] = '\0';

    int length = strlen((char *)input);

    get_binary(binary, (const unsigned char *)input, length);

    double entropy_value = entropy(binary, length * BITS_PER_BYTE);

    printf("Original input: %s\n", input);
    printf("Binary representation: ");

    for (int i = 0; i < length / BITS_PER_BYTE + 1; ++i) {
        printf("%02X ", binary[i]);
    }

    printf("\n");
    printf("Entropy: %.8f bits\n", entropy_value);

    return 0;
}