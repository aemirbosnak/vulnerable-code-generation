//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

char *binary_to_decimal(char *binary) {
    int decimal = 0;
    int power = 0;
    int length = strlen(binary);

    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }

    char *result = malloc(MAX_LENGTH * sizeof(char));
    sprintf(result, "%d", decimal);

    return result;
}

char *decimal_to_binary(int decimal) {
    char *binary = malloc(MAX_LENGTH * sizeof(char));
    int power = 0;

    while (decimal > 0) {
        if (decimal % 2 == 1) {
            strcat(binary, "1");
        } else {
            strcat(binary, "0");
        }
        decimal /= 2;
        power++;
    }

    for (int i = 0; i < power - 1; i++) {
        strcat(binary, "0");
    }

    return binary;
}

int main() {
    char input[MAX_LENGTH];
    char *binary = NULL;
    char *decimal = NULL;

    printf("Enter a binary number: ");
    scanf("%s", input);

    if (strlen(input) > MAX_LENGTH) {
        printf("Error: Binary number too large.\n");
        exit(1);
    }

    for (int i = 0; i < strlen(input); i++) {
        if (!isdigit(input[i])) {
            printf("Error: Invalid input.\n");
            exit(1);
        }
    }

    binary = strdup(input);

    decimal = binary_to_decimal(binary);

    printf("Decimal equivalent: %s\n", decimal);

    free(binary);
    free(decimal);

    return 0;
}