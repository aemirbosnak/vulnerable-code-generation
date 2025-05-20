//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

// Function prototypes
void convert_hexadecimal(char *hex, char *binary);
int is_valid_hexadecimal(char *hex);

int main() {
    char hex[100];
    char binary[300];
    int i;

    // Prompt user to enter hexadecimal number
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    // Check if input is valid hexadecimal
    if (!is_valid_hexadecimal(hex)) {
        printf("Invalid hexadecimal input.\n");
        return 1;
    }

    // Convert hexadecimal to binary
    convert_hexadecimal(hex, binary);

    // Print binary equivalent
    printf("Binary equivalent: %s\n", binary);

    return 0;
}

// Function to convert hexadecimal to binary
void convert_hexadecimal(char *hex, char *binary) {
    int i, j;
    char temp[100];

    // Initialize binary string
    strcpy(binary, "");

    // Convert each hexadecimal digit to binary
    for (i = 0; i < strlen(hex); i++) {
        sprintf(temp, "%c", hex[i]);
        if (isdigit(temp[0])) {
            strcat(binary, "0");
        } else {
            strcat(binary, "1");
        }
    }
}

// Function to check if input is valid hexadecimal
int is_valid_hexadecimal(char *hex) {
    int i;
    for (i = 0; i < strlen(hex); i++) {
        if (!isxdigit(hex[i])) {
            return 0;
        }
    }
    return 1;
}