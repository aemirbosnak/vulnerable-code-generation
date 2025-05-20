//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_NUM_LENGTH 32
#define MAX_BIN_LENGTH 65

int main() {
    char num_str[MAX_NUM_LENGTH];
    char bin_str[MAX_BIN_LENGTH];
    bool is_valid_input = false;
    int num;

    srand(time(NULL));
    printf("Welcome to the Post-Apocalyptic Binary Converter!\n");
    printf("Enter a number to convert to binary (between 0 and %d): ", RAND_MAX);
    scanf("%s", num_str);

    // Validate input
    for (int i = 0; i < strlen(num_str); i++) {
        if (num_str[i] < '0' || num_str[i] > '9') {
            printf("Invalid input. Please enter a valid number.\n");
            return 1;
        }
    }

    num = atoi(num_str);
    if (num < 0 || num > RAND_MAX) {
        printf("Invalid input. Please enter a number between 0 and %d.\n", RAND_MAX);
        return 1;
    }

    is_valid_input = true;

    // Convert decimal to binary
    int i = 0;
    while (num > 0) {
        bin_str[i++] = (num % 2) + '0';
        num /= 2;
    }

    // Reverse the binary string
    for (int j = 0; j < i / 2; j++) {
        char temp = bin_str[j];
        bin_str[j] = bin_str[i - j - 1];
        bin_str[i - j - 1] = temp;
    }

    bin_str[i] = '\0';

    if (is_valid_input) {
        printf("The binary representation of %s is: %s\n", num_str, bin_str);
    }

    return 0;
}