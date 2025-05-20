//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_LENGTH 32

int main(int argc, char *argv[]) {
    char input[MAX_NUM_LENGTH];
    char output[MAX_NUM_LENGTH + 1];
    int num;
    int i, j;
    int is_negative;
    int is_binary;

    // Check for correct number of arguments
    if (argc!= 2) {
        printf("Usage: %s <decimal_number>\n", argv[0]);
        return 1;
    }

    // Check if input is a valid decimal number
    if (sscanf(argv[1], "%d", &num)!= 1) {
        printf("Invalid decimal number.\n");
        return 1;
    }

    // Convert decimal to binary
    sprintf(output, "%b", num);

    // Add leading zeros to binary number if necessary
    j = strlen(output);
    if (j < MAX_NUM_LENGTH) {
        for (i = 0; i < MAX_NUM_LENGTH - j; i++) {
            output[i] = '0';
        }
        output[MAX_NUM_LENGTH] = '\0';
    }

    // Check if binary number is negative
    is_negative = 0;
    if (output[0] == '1') {
        is_binary = 1;
        for (i = 1; i < strlen(output); i++) {
            if (output[i] == '0') {
                is_binary = 0;
                break;
            }
        }
    } else {
        is_binary = 0;
    }

    // Convert binary to decimal
    if (is_binary) {
        sprintf(output, "-%d", num);
        is_negative = 1;
    } else {
        sprintf(output, "%d", num);
    }

    // Print result
    if (is_negative) {
        printf("The binary representation of %d is %s.\n", num, output);
    } else {
        printf("The binary representation of %d is %s.\n", num, output);
    }

    return 0;
}