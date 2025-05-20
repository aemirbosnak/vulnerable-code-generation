//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main() {
    char input[MAX_LENGTH];
    char *ptr;
    int length, i;

    // Prompt the user to enter a string
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove leading and trailing whitespace
    length = strlen(input);
    if (length > 0 && isspace(input[0])) {
        for (i = 0; i < length; i++) {
            if (!isspace(input[i])) {
                strcpy(input, &input[i]);
                break;
            }
        }
    }
    if (length > 0 && isspace(input[length - 1])) {
        input[--length] = '\0';
    }

    // Reverse the string
    length = strlen(input);
    ptr = input + length - 1;
    while (ptr > input) {
        input[length - 1 - (ptr - input)] = *ptr;
        ptr--;
    }

    // Convert to uppercase
    for (i = 0; i < length; i++) {
        input[i] = toupper(input[i]);
    }

    // Count the number of words in the string
    length = strlen(input);
    int numWords = 1;
    for (i = 0; i < length; i++) {
        if (isspace(input[i])) {
            numWords++;
        }
    }

    // Print the modified string and the number of words
    printf("Modified string: %s\n", input);
    printf("Number of words: %d\n", numWords);

    return 0;
}