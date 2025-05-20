//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    char temp[MAX_LENGTH];

    // Prompt user for input string
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove leading and trailing whitespace from input string
    int i = 0;
    int j = strlen(input) - 1;
    while (isspace(input[i])) {
        i++;
    }
    while (isspace(input[j])) {
        j--;
        input[j] = '\0';
    }

    // Reverse the input string
    j = strlen(input) - 1;
    for (i = 0; i < j; i++, j--) {
        temp[i] = input[j];
        input[j] = input[i];
    }
    input[j] = '\0';

    // Remove all vowels from the reversed string
    char vowels[] = "aeiouAEIOU";
    for (i = 0; i < strlen(input); i++) {
        if (strchr(vowels, tolower(input[i])) == NULL) {
            strcat(output, &input[i]);
        }
    }

    // Reverse the output string
    j = strlen(output) - 1;
    for (i = 0; i < j; i++, j--) {
        temp[i] = output[j];
        output[j] = output[i];
    }
    output[j] = '\0';

    // Print the final output string
    printf("Output: %s\n", output);

    return 0;
}