//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main() {
    char input[100];
    char output[200];
    int i, j, k, length, value;
    char hex[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    printf("Enter a decimal number: ");
    scanf("%s", input);

    // Check if input is valid decimal number
    for (i = 0; i < strlen(input); i++) {
        if (!isdigit(input[i])) {
            printf("Invalid input. Please enter a valid decimal number.\n");
            return 0;
        }
    }

    length = strlen(input);
    strcpy(output, "");

    // Convert decimal to hexadecimal
    for (i = length - 1, j = 0; i >= 0; i--) {
        value = input[i] - '0';
        if (value > 9) {
            output[j++] = hex[value - 10];
        } else {
            output[j++] = input[i];
        }
    }

    // Reverse the output
    for (i = 0, j = strlen(output) - 1; i < j; i++, j--) {
        char temp = output[i];
        output[i] = output[j];
        output[j] = temp;
    }

    // Add leading zeros if necessary
    k = strlen(output);
    while (k < 8) {
        output[k++] = '0';
    }

    // Print the output
    printf("Hexadecimal equivalent: %s\n", output);

    return 0;
}