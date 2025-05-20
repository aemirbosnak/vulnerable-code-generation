//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define MAX_LENGTH 1000
#define HEX_CHARS "0123456789ABCDEF"

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    int i, j;
    int length;
    int num;
    bool valid_input = FALSE;

    printf("Welcome to the Surrealist C Hexadecimal Converter!\n");
    printf("Please enter a string to convert to hexadecimal:\n");
    fgets(input, MAX_LENGTH, stdin);
    length = strlen(input);

    // Check if input is valid
    for (i = 0; i < length; i++) {
        if (!isprint(input[i])) {
            printf("Error: Input contains invalid characters.\n");
            return 1;
        }
    }

    // Convert input to hexadecimal
    for (i = 0, j = 0; i < length; i++) {
        if (isdigit(input[i])) {
            num = input[i] - '0';
        } else {
            num = toupper(input[i]) - 'A' + 10;
        }
        output[j++] = HEX_CHARS[num];
    }
    output[j] = '\0';

    // Print output
    printf("Hexadecimal representation: %s\n", output);

    return 0;
}