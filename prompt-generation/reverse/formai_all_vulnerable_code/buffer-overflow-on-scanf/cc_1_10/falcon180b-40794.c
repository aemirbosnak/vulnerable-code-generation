//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main(int argc, char *argv[]) {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    int length;
    int i;
    int num;
    int decimal = 0;
    int binary[MAX_LENGTH];
    int j;

    // Get user input
    printf("Enter a decimal number: ");
    scanf("%s", input);

    // Validate input
    length = strlen(input);
    if (length == 0) {
        printf("Error: Input is empty.\n");
        return 1;
    }
    for (i = 0; i < length; i++) {
        if (!isdigit(input[i])) {
            printf("Error: Input contains non-numeric characters.\n");
            return 1;
        }
    }

    // Convert decimal to binary
    num = atoi(input);
    while (num > 0) {
        binary[decimal++] = num % 2;
        num /= 2;
    }

    // Reverse binary array
    for (j = 0; j < decimal; j++) {
        binary[j] = binary[decimal - j - 1];
    }

    // Convert binary to ASCII
    for (j = 0; j < decimal; j++) {
        output[j] = binary[j] + '0';
    }
    output[decimal] = '\0';

    // Print output
    printf("Binary: %s\n", output);

    return 0;
}