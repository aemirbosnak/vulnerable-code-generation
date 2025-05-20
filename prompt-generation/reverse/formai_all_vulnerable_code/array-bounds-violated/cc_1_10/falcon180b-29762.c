//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main(int argc, char *argv[]) {
    char hex[MAX_LENGTH], input[MAX_LENGTH], *ptr;
    int i, j, len;

    printf("Welcome to the Happy Hexadecimal Converter!\n");
    printf("Please enter a hexadecimal number to convert:\n");
    fgets(input, MAX_LENGTH, stdin);

    // Remove newline character
    len = strlen(input) - 1;
    if (input[len] == '\n') {
        input[len] = '\0';
    }

    len = strlen(input);

    // Check if input is valid hexadecimal
    for (i = 0; i < len; i++) {
        if (!isxdigit(input[i])) {
            printf("Invalid input: Please enter a valid hexadecimal number.\n");
            return 1;
        }
    }

    // Convert hexadecimal to decimal
    for (i = 0, j = 0; i < len; i++) {
        if (isdigit(input[i])) {
            hex[j++] = input[i];
        } else {
            hex[j++] = tolower(input[i]) - 'a' + 10;
        }
    }

    // Reverse the string
    ptr = &hex[j - 1];
    while (ptr > hex) {
        hex[j - 1] = hex[j - 2];
        j--;
        ptr--;
    }
    hex[0] = '0';
    j--;

    // Print the result
    printf("The decimal equivalent of %s is: %s\n", input, hex);

    return 0;
}