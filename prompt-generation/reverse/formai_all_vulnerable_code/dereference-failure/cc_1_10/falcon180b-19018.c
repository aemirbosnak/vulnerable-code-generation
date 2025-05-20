//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

typedef struct {
    char* binary;
    char* octal;
    char* hexadecimal;
} conversion;

int main() {
    char input[MAX_LENGTH];
    conversion result;
    result.binary = (char*) malloc(MAX_LENGTH * sizeof(char));
    result.octal = (char*) malloc(MAX_LENGTH * sizeof(char));
    result.hexadecimal = (char*) malloc(MAX_LENGTH * sizeof(char));

    printf("Enter a binary number: ");
    fgets(input, MAX_LENGTH, stdin);

    int length = strlen(input);
    int i = 0;
    int j = 0;

    while (input[i]!= '\n') {
        if (input[i] == '0' || input[i] == '1') {
            result.binary[j] = input[i];
            j++;
        } else {
            printf("Invalid input. Please enter a valid binary number.\n");
            exit(1);
        }
        i++;
    }

    result.binary[j] = '\0';

    char* binary = result.binary;
    char* octal = result.octal;
    char* hexadecimal = result.hexadecimal;

    printf("\nBinary: %s\n", binary);
    printf("Octal: %s\n", octal);
    printf("Hexadecimal: %s\n", hexadecimal);

    free(binary);
    free(octal);
    free(hexadecimal);

    return 0;
}