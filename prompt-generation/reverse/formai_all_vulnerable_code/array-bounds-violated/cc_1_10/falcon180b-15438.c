//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main() {
    char input_string[MAX_LENGTH];
    char output_string[MAX_LENGTH];
    char *token;
    int i = 0, j = 0;

    // Prompt user for input string
    printf("Enter a string: ");
    fgets(input_string, MAX_LENGTH, stdin);

    // Remove leading and trailing whitespace
    while (isspace(input_string[i])) {
        i++;
    }
    while (isspace(input_string[j])) {
        j--;
    }
    strncpy(output_string, &input_string[i], j - i + 1);
    output_string[j - i + 1] = '\0';

    // Reverse the string
    for (i = strlen(output_string) - 1, j = 0; i >= 0; i--, j++) {
        output_string[j] = output_string[i];
    }
    output_string[j] = '\0';

    // Convert string to uppercase
    for (i = 0; output_string[i]!= '\0'; i++) {
        output_string[i] = toupper(output_string[i]);
    }

    // Count number of words and characters
    token = strtok(output_string, " ");
    while (token!= NULL) {
        i++;
        if (i == 1) {
            printf("The string has %d word(s) and %d character(s).\n", i, strlen(output_string));
        }
        token = strtok(NULL, " ");
    }

    return 0;
}