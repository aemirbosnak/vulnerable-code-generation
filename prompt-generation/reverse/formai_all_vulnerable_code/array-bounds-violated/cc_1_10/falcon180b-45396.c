//Falcon-180B DATASET v1.0 Category: Recursive ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function prototypes
void reverse_string(char *str, int start, int end);
void print_string(char *str);

int main() {
    char input[MAX_LINE_LENGTH];
    char reversed_input[MAX_LINE_LENGTH];
    int length;

    // Get user input
    printf("Enter a string: ");
    fgets(input, MAX_LINE_LENGTH, stdin);

    // Remove newline character from input
    length = strlen(input) - 1;
    input[length] = '\0';

    // Reverse input string and store it in reversed_input
    reverse_string(input, 0, length);
    strcpy(reversed_input, input);

    // Print reversed string
    printf("Reversed string: %s\n", reversed_input);

    return 0;
}

// Recursive function to reverse a string
void reverse_string(char *str, int start, int end) {
    char temp;

    if (start >= end) {
        return;
    }

    // Swap characters at start and end
    temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursively call function for next set of characters
    reverse_string(str, start + 1, end - 1);
}

// Function to print a string
void print_string(char *str) {
    printf("%s\n", str);
}