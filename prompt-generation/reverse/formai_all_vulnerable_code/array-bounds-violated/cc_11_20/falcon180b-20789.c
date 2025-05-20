//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    char temp[MAX_LENGTH];
    int length;
    int i, j;

    // Prompt user for input
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove leading/trailing white spaces
    length = strlen(input);
    if (input[length - 1] == '\n') {
        input[length - 1] = '\0';
        length--;
    }
    for (i = 0; i < length; i++) {
        if (!isspace(input[i])) {
            strncpy(temp, input + i, length - i);
            strcpy(input, temp);
            length = strlen(input);
            break;
        }
    }

    // Reverse the string
    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp[i] = input[j];
        temp[j] = input[i];
    }
    strcpy(input, temp);

    // Convert to uppercase
    for (i = 0; i < length; i++) {
        input[i] = toupper(input[i]);
    }

    // Remove vowels
    strcpy(output, input);
    for (i = 0; i < length; i++) {
        if (input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U') {
            output[i] = '\0';
        }
    }

    // Output result
    printf("Original string: %s\n", input);
    printf("Reversed string: %s\n", input);
    printf("Uppercase string: %s\n", input);
    printf("String without vowels: %s\n", output);

    return 0;
}