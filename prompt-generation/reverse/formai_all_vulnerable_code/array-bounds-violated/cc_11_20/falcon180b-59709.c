//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

int main() {
    char input_string[MAX_STRING_LENGTH];
    char *output_string = NULL;
    size_t input_string_length = 0;
    size_t output_string_length = 0;

    // Prompt user for input string
    printf("Enter input string (maximum length %d): ", MAX_STRING_LENGTH - 1);
    fgets(input_string, MAX_STRING_LENGTH, stdin);
    input_string_length = strlen(input_string);

    // Remove leading/trailing whitespace from input string
    while (isspace(input_string[0])) {
        memmove(input_string, input_string + 1, input_string_length - 1);
        input_string_length--;
    }
    while (isspace(input_string[input_string_length - 1])) {
        input_string_length--;
    }

    // Reverse input string
    output_string = malloc(input_string_length + 1);
    if (output_string == NULL) {
        printf("Error: Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    output_string_length = 0;
    for (int i = input_string_length - 1; i >= 0; i--) {
        output_string[output_string_length++] = input_string[i];
    }
    output_string[output_string_length] = '\0';

    // Convert input string to uppercase
    for (int i = 0; i < input_string_length; i++) {
        input_string[i] = toupper(input_string[i]);
    }

    // Convert input string to lowercase
    for (int i = 0; i < input_string_length; i++) {
        input_string[i] = tolower(input_string[i]);
    }

    // Count number of vowels in input string
    int vowel_count = 0;
    for (int i = 0; i < input_string_length; i++) {
        if (input_string[i] == 'a' || input_string[i] == 'e' || input_string[i] == 'i' || input_string[i] == 'o' || input_string[i] == 'u') {
            vowel_count++;
        }
    }

    // Print results
    printf("Input string: %s\n", input_string);
    printf("Output string: %s\n", output_string);
    printf("Number of vowels: %d\n", vowel_count);

    free(output_string);
    return 0;
}