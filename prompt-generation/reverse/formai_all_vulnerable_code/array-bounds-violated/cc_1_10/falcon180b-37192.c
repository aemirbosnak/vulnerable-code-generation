//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000

int main() {
    char input_string[MAX_STRING_LENGTH];
    char output_string[MAX_STRING_LENGTH];
    char reverse_string[MAX_STRING_LENGTH];
    char upper_string[MAX_STRING_LENGTH];
    char lower_string[MAX_STRING_LENGTH];
    int string_length;
    int i, j;

    printf("Enter a string: ");
    fgets(input_string, MAX_STRING_LENGTH, stdin);
    string_length = strlen(input_string);

    // Remove leading and trailing spaces
    input_string[string_length - 1] = '\0';
    for (i = 0; i < string_length - 1; i++) {
        if (isspace(input_string[i])) {
            input_string[i] = '\0';
        }
    }

    // Reverse the string
    for (i = strlen(input_string) - 1, j = 0; i >= 0; i--, j++) {
        reverse_string[j] = input_string[i];
    }
    reverse_string[j] = '\0';

    // Convert to uppercase
    for (i = 0; i < strlen(reverse_string); i++) {
        upper_string[i] = toupper(reverse_string[i]);
    }

    // Convert to lowercase
    for (i = 0; i < strlen(upper_string); i++) {
        lower_string[i] = tolower(upper_string[i]);
    }

    // Print the results
    printf("Original string: %s\n", input_string);
    printf("Reversed string: %s\n", reverse_string);
    printf("Uppercase string: %s\n", upper_string);
    printf("Lowercase string: %s\n", lower_string);

    return 0;
}