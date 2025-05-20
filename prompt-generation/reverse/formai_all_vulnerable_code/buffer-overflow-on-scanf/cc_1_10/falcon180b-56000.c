//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: active
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main() {
    char input_string[MAX_LENGTH];
    char output_string[MAX_LENGTH];
    char reversed_string[MAX_LENGTH];
    int input_length, output_length, reversed_length;
    int i, j;

    // Get input string from user
    printf("Enter a string: ");
    scanf("%s", input_string);
    input_length = strlen(input_string);

    // Remove all spaces from input string
    for (i = 0; i < input_length; i++) {
        if (isspace(input_string[i])) {
            input_string[i] = '\0';
        }
    }

    // Reverse input string
    for (i = input_length - 1, j = 0; i >= 0; i--, j++) {
        reversed_string[j] = input_string[i];
    }
    reversed_string[j] = '\0';

    // Convert all characters to uppercase
    for (i = 0; reversed_string[i]!= '\0'; i++) {
        reversed_string[i] = toupper(reversed_string[i]);
    }

    // Remove all non-alphanumeric characters from reversed string
    output_length = 0;
    for (i = 0; reversed_string[i]!= '\0'; i++) {
        if (isalnum(reversed_string[i])) {
            output_string[output_length++] = reversed_string[i];
        }
    }
    output_string[output_length] = '\0';

    // Print output string
    printf("Reversed string with no spaces and all uppercase: %s\n", output_string);

    return 0;
}