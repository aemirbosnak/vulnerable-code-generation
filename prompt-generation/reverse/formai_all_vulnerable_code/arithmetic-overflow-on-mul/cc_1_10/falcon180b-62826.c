//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: creative
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    char input[MAX_SIZE];
    char output[MAX_SIZE];
    int i, j, len, decimal;

    printf("Enter a hexadecimal number: ");
    fgets(input, MAX_SIZE, stdin);
    len = strlen(input);

    // Remove any leading or trailing white spaces
    for (i = 0; i < len; i++) {
        if (isspace(input[i])) {
            input[i] = '\0';
            len--;
        }
    }

    // Convert hexadecimal to decimal
    decimal = 0;
    for (i = 0; i < len; i++) {
        if (isdigit(input[i])) {
            decimal = decimal * 16 + input[i] - '0';
        } else if (isalpha(input[i])) {
            if (isupper(input[i])) {
                decimal = decimal * 16 + input[i] - 'A' + 10;
            } else {
                decimal = decimal * 16 + input[i] - 'a' + 10;
            }
        } else {
            printf("Invalid input\n");
            return 1;
        }
    }

    // Convert decimal to hexadecimal
    snprintf(output, MAX_SIZE, "%.8X", decimal);

    // Remove any leading zeros
    for (i = strlen(output) - 1, j = 0; i >= 0; i--, j++) {
        if (output[i]!= '0') {
            snprintf(output, MAX_SIZE, "%.*s", j, &output[i]);
            break;
        }
    }

    printf("Hexadecimal: %s\n", output);

    return 0;
}