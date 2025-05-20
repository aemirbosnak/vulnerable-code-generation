//Falcon2-11B DATASET v1.0 Category: Syntax parsing ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to parse the syntax of a C program
int parseSyntax(char* input) {
    // Initialize variables
    int count = 0;
    char* token = NULL;
    char* delimiters = " \t\n;(){}[]=, ";

    // Loop through the input string
    while (*input!= '\0') {
        // Find the first delimiter in the input string
        while (*input!= '\0' &&!strchr(delimiters, *input)) {
            input++;
        }

        // Check if we found a delimiter
        if (*input == '\0') {
            break;
        }

        // Extract the token
        token = strsep(&input, delimiters);

        // Increment the count
        count++;
    }

    // Check if we found any tokens
    if (count == 0) {
        printf("No tokens found in the input string.\n");
        return -1;
    } else {
        printf("Found %d tokens in the input string.\n", count);
        return count;
    }
}

int main() {
    // Read input from the user
    printf("Enter a C program: ");
    char* input = (char*) malloc(sizeof(char) * 1000);
    scanf("%s", input);

    // Parse the syntax of the input program
    int syntaxCount = parseSyntax(input);

    // Print the result
    if (syntaxCount == -1) {
        printf("No tokens found in the input string.\n");
    } else {
        printf("Found %d tokens in the input string.\n", syntaxCount);
    }

    // Free the memory allocated for the input string
    free(input);

    return 0;
}