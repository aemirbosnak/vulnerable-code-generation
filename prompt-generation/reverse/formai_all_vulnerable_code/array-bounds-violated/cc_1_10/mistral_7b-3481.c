//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define WIDTH 80
#define CHECKSUM_SIZE 4

void print_banner() {
    printf("\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("|                             Checksum Calculator                              |\n");
    printf("|                                                                                |\n");
    printf("|  This program calculates the checksum of a given string using a custom formula   |\n");
    printf("|                                                                                |\n");
    printf("|  Created by [Your Name]                                                          |\n");
    printf("|                                                                                |\n");
    printf("----------------------------------------------------------------------------------\n");
}

uint32_t calculate_checksum(const uint8_t *data, size_t length) {
    uint32_t sum = 0;
    for (size_t i = 0; i < length; i++) {
        sum += data[i] << ((i & 3) * 8);
    }
    sum = (sum >> 2) & 0xFFFFFFFF;
    return sum;
}

int main() {
    print_banner();

    char input[WIDTH];
    printf("Enter the string: ");
    fgets(input, WIDTH, stdin);
    size_t input_length = strlen(input);

    if (input[input_length - 1] == '\n') {
        input[input_length - 1] = '\0';
        input_length--;
    }

    const uint8_t *data = (const uint8_t *) input;

    uint32_t checksum = calculate_checksum(data, input_length);

    printf("\nChecksum: ");
    for (int i = CHECKSUM_SIZE * 8 - 8; i >= 0; i -= 8) {
        printf("%02X", (checksum >> i) & 0xFF);
        if (i && (i % CHECKSUM_SIZE * 8) == 0) {
            printf(":");
        }
    }

    printf("\n");

    return 0;
}