//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main() {
    char input_string[MAX_LENGTH];
    char output_string[MAX_LENGTH];

    // Get input string from user
    printf("Enter a string: ");
    scanf("%s", input_string);

    // Remove leading and trailing white spaces
    int length = strlen(input_string);
    for (int i = 0; i < length; i++) {
        if (isspace(input_string[i]) || input_string[i] == '\n') {
            input_string[i] = '\0';
        }
    }

    // Reverse the string
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = input_string[start];
        input_string[start] = input_string[end];
        input_string[end] = temp;
        start++;
        end--;
    }

    // Convert to uppercase
    for (int i = 0; i < length; i++) {
        input_string[i] = toupper(input_string[i]);
    }

    // Remove all vowels
    char vowels[] = "AEIOUaeiou";
    int new_length = 0;
    for (int i = 0; i < length; i++) {
        if (strchr(vowels, input_string[i]) == NULL) {
            output_string[new_length++] = input_string[i];
        }
    }
    output_string[new_length] = '\0';

    // Print the modified string
    printf("Modified string: %s\n", output_string);

    return 0;
}