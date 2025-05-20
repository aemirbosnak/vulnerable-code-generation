//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    int length, i, j;

    printf("Enter a binary number: ");
    scanf("%s", input);
    length = strlen(input);

    // Check if the input is a valid binary number
    for (i = 0; i < length; i++) {
        if (input[i]!= '0' && input[i]!= '1') {
            printf("Invalid binary number\n");
            return 0;
        }
    }

    // Convert binary to decimal
    for (i = strlen(input) - 1, j = 0; i >= 0; i--, j++) {
        output[j] = input[i] - '0';
    }
    output[j] = '\0';

    // Convert decimal to binary
    length = 0;
    for (i = strlen(output) - 1; i >= 0; i--) {
        if (output[i] == 0) {
            output[i] = '0';
            length++;
        } else {
            output[i] = '1';
            length++;
            break;
        }
    }

    // Pad the output with leading zeros
    for (i = strlen(output) - 1; i < MAX_LENGTH - 1; i++) {
        output[i] = '0';
        length++;
    }
    output[length] = '\0';

    printf("Binary number: %s\n", output);

    return 0;
}