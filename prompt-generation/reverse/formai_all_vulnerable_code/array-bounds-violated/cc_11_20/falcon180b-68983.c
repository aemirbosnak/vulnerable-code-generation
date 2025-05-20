//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000

int main() {
    char input_string[MAX_STRING_LENGTH];
    char output_string[MAX_STRING_LENGTH];
    int string_length;
    int i;

    // Prompt the user to input a string
    printf("Enter a string: ");
    fgets(input_string, MAX_STRING_LENGTH, stdin);

    // Remove any leading or trailing whitespace from the input string
    string_length = strlen(input_string);
    if (string_length > 0 && input_string[0] == '\n') {
        input_string[0] = '\0';
    }
    if (string_length > 0 && input_string[string_length - 1] == '\n') {
        input_string[string_length - 1] = '\0';
    }

    // Convert the input string to uppercase
    for (i = 0; i < string_length; i++) {
        input_string[i] = toupper(input_string[i]);
    }

    // Reverse the input string
    for (i = 0; i < string_length / 2; i++) {
        char temp = input_string[i];
        input_string[i] = input_string[string_length - i - 1];
        input_string[string_length - i - 1] = temp;
    }

    // Remove any leading or trailing whitespace from the reversed string
    if (input_string[0] == '\n') {
        input_string[0] = '\0';
    }
    if (input_string[string_length - 1] == '\n') {
        input_string[string_length - 1] = '\0';
    }

    // Convert the reversed string to lowercase
    for (i = 0; i < string_length; i++) {
        input_string[i] = tolower(input_string[i]);
    }

    // Remove any leading or trailing whitespace from the lowercase string
    if (input_string[0] == '\n') {
        input_string[0] = '\0';
    }
    if (input_string[string_length - 1] == '\n') {
        input_string[string_length - 1] = '\0';
    }

    // Print the modified string
    printf("Modified string: %s\n", input_string);

    return 0;
}