//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

int main() {
    char hex[MAX_SIZE];
    char input[MAX_SIZE];
    int i, j = 0;
    char *ptr;

    // Prompt user to enter hexadecimal value
    printf("Enter a hexadecimal value: ");
    fgets(input, MAX_SIZE, stdin);

    // Remove newline character from input
    if ((ptr = strchr(input, '\n'))!= NULL) {
        *ptr = '\0';
    }

    // Convert hexadecimal value to uppercase
    for (i = 0; i < strlen(input); i++) {
        if (!isxdigit(input[i])) {
            printf("Invalid hexadecimal value!\n");
            return 0;
        }
        if (tolower(input[i]) >= 'a' && tolower(input[i]) <= 'f') {
            hex[j] = tolower(input[i]) + 'A' - 'a';
        } else {
            hex[j] = input[i];
        }
        j++;
    }

    // Convert hexadecimal value to decimal value
    int decimal = 0;
    for (i = strlen(hex) - 1; i >= 0; i--) {
        if (isdigit(hex[i])) {
            decimal += hex[i] - '0';
        } else {
            switch (hex[i]) {
                case 'A':
                    decimal += 10;
                    break;
                case 'B':
                    decimal += 11;
                    break;
                case 'C':
                    decimal += 12;
                    break;
                case 'D':
                    decimal += 13;
                    break;
                case 'E':
                    decimal += 14;
                    break;
                case 'F':
                    decimal += 15;
                    break;
            }
        }
        decimal *= 16;
    }

    // Print the decimal value
    printf("Decimal value: %d\n", decimal);

    return 0;
}