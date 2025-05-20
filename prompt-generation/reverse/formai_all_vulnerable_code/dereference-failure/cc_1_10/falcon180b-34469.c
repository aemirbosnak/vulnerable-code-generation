//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LENGTH 32

int main(int argc, char *argv[]) {
    char input[MAX_LINE_LENGTH];
    char *hex_output = NULL;
    char *dec_output = NULL;
    int hex_len, dec_len;
    int i, j, k;

    printf("Enter a decimal number: ");
    fgets(input, MAX_LINE_LENGTH, stdin);

    // Remove newline character
    input[strcspn(input, "\n")] = '\0';

    // Check if input is a valid decimal number
    for (i = 0; i < strlen(input); i++) {
        if (!isdigit(input[i])) {
            printf("Invalid input: %c is not a digit\n", input[i]);
            return 1;
        }
    }

    // Convert decimal to hexadecimal
    hex_len = strlen(input) * 2;
    hex_output = malloc(hex_len + 1);
    memset(hex_output, 0, hex_len + 1);
    sprintf(hex_output, "%X", atoi(input));

    // Convert hexadecimal to decimal
    dec_len = strlen(hex_output) / 2;
    dec_output = malloc(dec_len + 1);
    memset(dec_output, 0, dec_len + 1);
    for (i = 0, j = 0; i < strlen(hex_output); i += 2, j++) {
        dec_output[j] = hex_output[i] - '0';
    }

    printf("Hexadecimal: %s\n", hex_output);
    printf("Decimal: %s\n", dec_output);

    free(hex_output);
    free(dec_output);

    return 0;
}