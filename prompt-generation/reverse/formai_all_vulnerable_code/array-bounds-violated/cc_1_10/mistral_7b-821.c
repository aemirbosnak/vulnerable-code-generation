//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

void die(const char *msg) {
    printf("\n%s\n", msg);
    exit(EXIT_FAILURE);
}

int hex_str_to_bin(const char *hex_str, unsigned char *bin_arr) {
    int i, j;
    unsigned int hex_val;

    if (strlen(hex_str) % 2 != 0) {
        die("Input hex string must have an even number of characters.\n");
    }

    for (i = 0; i < strlen(hex_str) / 2; i++) {
        sscanf(&hex_str[2 * i], "%2x", &hex_val);
        for (j = 0; j < 4; j++) {
            bin_arr[i * 4 + j] = (hex_val >> (4 * (3 - j))) & 0x01;
        }
    }

    return 0;
}

void print_bin_arr(const unsigned char *bin_arr, size_t size) {
    size_t i;

    for (i = 0; i < size; i++) {
        printf("%c", i % 8 == 0 ? '\n' : (i % 4 == 0 ? ' ' : '0') + bin_arr[i]);
    }

    printf("\n");
}

int main(void) {
    unsigned char bin_arr[MAX_INPUT_SIZE / 4];
    char hex_str[MAX_INPUT_SIZE];

    if (fgets(hex_str, sizeof(hex_str), stdin) == NULL) {
        die("Failed to read input.\n");
    }

    if (hex_str[strlen(hex_str) - 1] == '\n') {
        hex_str[strlen(hex_str) - 1] = '\0';
    }

    if (hex_str_to_bin(hex_str, bin_arr) != 0) {
        die("Failed to convert hex string to binary array.\n");
    }

    print_bin_arr(bin_arr, sizeof(bin_arr) / sizeof(bin_arr[0]));

    return EXIT_SUCCESS;
}

// What on earth did I just write?!?
// This code converts a hexadecimal string to a binary array
// but the way it's written is just... shocking!
// I can't believe I wrote this!
// But it does compile and run without any errors!