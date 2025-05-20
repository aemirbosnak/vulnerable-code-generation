//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

int main() {
    char input[MAX_INPUT_SIZE];
    char output[MAX_INPUT_SIZE * 3];
    int i, j, len;

    printf("Enter a hexadecimal number: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // remove newline character
    len = strlen(input);
    input[len - 1] = '\0';

    for (i = 0, j = 0; i < len; i++) {
        if (isxdigit(input[i])) {
            if (isdigit(input[i])) {
                output[j] = input[i];
            } else {
                output[j] = tolower(input[i]);
            }
            j++;
        }
    }

    printf("Hexadecimal: ");
    for (i = 0; i < j; i++) {
        printf("%c", output[i]);
    }

    printf("\nDecimal: ");
    for (i = 0; i < j; i += 2) {
        printf("%d", (int)strtol(&output[i], NULL, 16));
        if (i + 1 < j) {
            printf(" ");
        }
    }

    printf("\nBinary: ");
    for (i = 0; i < j; i += 2) {
        printf("%d", (int)strtol(&output[i], NULL, 16));
    }

    return 0;
}