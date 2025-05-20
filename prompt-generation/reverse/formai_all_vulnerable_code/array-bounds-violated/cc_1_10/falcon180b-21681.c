//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

int main() {
    char input[MAX_SIZE];
    char *output = NULL;
    int i, j;

    printf("Enter a binary number: ");
    fgets(input, MAX_SIZE, stdin);

    // Remove trailing newline character
    i = strlen(input) - 1;
    if (input[i] == '\n') {
        input[i] = '\0';
    }

    output = malloc(strlen(input) * 8 + 1);
    if (output == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0, j = 0; i < strlen(input); i++) {
        if (isdigit(input[i])) {
            output[j++] = input[i];
        } else {
            printf("Invalid character found: %c\n", input[i]);
            free(output);
            return 1;
        }
    }

    // Pad with leading zeros if necessary
    while (j < 8) {
        output[j++] = '0';
    }

    output[j] = '\0';

    printf("Decimal equivalent: %s\n", output);

    free(output);

    return 0;
}