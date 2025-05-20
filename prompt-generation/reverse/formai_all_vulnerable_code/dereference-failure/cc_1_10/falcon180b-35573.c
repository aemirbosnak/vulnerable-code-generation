//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM_SIZE 32 // maximum number of digits
#define MAX_BINARY_SIZE (MAX_NUM_SIZE * 2) // maximum binary size

void print_binary(char binary[MAX_BINARY_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        printf("%c", binary[i]);
    }
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <decimal number>\n", argv[0]);
        return 1;
    }

    char decimal[MAX_NUM_SIZE];
    strcpy(decimal, argv[1]);

    int decimal_size = strlen(decimal);
    if (decimal_size == 0) {
        printf("Error: empty input\n");
        return 1;
    }

    char binary[MAX_BINARY_SIZE];
    int binary_size = 0;
    int current_bit = 0;

    for (int i = 0; i < decimal_size; i++) {
        char c = decimal[i];
        if (!isdigit(c)) {
            printf("Error: input contains non-numeric characters\n");
            return 1;
        }

        int digit = c - '0';
        while (current_bit > 0) {
            binary[binary_size++] = '0';
            current_bit--;
        }
        binary[binary_size++] = '1';
        current_bit++;
    }

    while (current_bit > 0) {
        binary[binary_size++] = '0';
        current_bit--;
    }
    binary[binary_size] = '\0';

    printf("Decimal: %s\n", decimal);
    printf("Binary:   ");
    print_binary(binary, binary_size);
    printf("\n");

    return 0;
}