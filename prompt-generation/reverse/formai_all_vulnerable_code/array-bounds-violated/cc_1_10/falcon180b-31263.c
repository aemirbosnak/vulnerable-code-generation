//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    char *output = NULL;
    int length;

    printf("Enter a binary number: ");
    if (fgets(input, MAX_LENGTH, stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove newline character from input
    length = strlen(input);
    if (input[length - 1] == '\n') {
        input[length - 1] = '\0';
        length--;
    }

    output = malloc(2 * length + 1);
    if (output == NULL) {
        printf("Error allocating memory.\n");
        return 1;
    }

    length = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (!isdigit(input[i])) {
            printf("Error: Input is not a binary number.\n");
            free(output);
            return 1;
        }
        if (input[i] == '1') {
            output[length++] = '0';
        } else {
            output[length++] = '1';
        }
    }
    output[length] = '\0';

    printf("Binary to decimal conversion: %s\n", output);

    free(output);
    return 0;
}