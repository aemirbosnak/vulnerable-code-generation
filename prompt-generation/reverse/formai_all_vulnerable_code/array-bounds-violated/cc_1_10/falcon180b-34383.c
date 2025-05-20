//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

// Function to check if a string contains only hexadecimal characters
int is_hex(char *str) {
    int i = 0;
    while (str[i]) {
        if (!isxdigit(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int main() {
    char input[MAX_BUFFER_SIZE];
    char output[MAX_BUFFER_SIZE];
    int len;
    int i;

    // Prompt the user to enter a hexadecimal string
    printf("Enter a hexadecimal string: ");
    fgets(input, MAX_BUFFER_SIZE, stdin);

    // Remove the newline character from the input string
    len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Check if the input string contains only hexadecimal characters
    if (!is_hex(input)) {
        printf("Error: Input string must contain only hexadecimal characters.\n");
        return 1;
    }

    // Convert the hexadecimal string to binary
    for (i = 0; i < strlen(input); i++) {
        if (isdigit(input[i])) {
            sprintf(&output[i * 2], "%c", input[i]);
        } else {
            sprintf(&output[i * 2], "%c", input[i] - 'A' + 10);
        }
    }

    // Print the binary string
    printf("Binary representation of the input string: %s\n", output);

    return 0;
}