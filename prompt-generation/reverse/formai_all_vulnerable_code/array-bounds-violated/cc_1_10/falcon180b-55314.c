//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char string[MAX_LENGTH];
    char *token;
    int count = 0;
    int length;

    // Prompt user for string input
    printf("Enter a string: ");
    fgets(string, MAX_LENGTH, stdin);

    // Remove trailing newline character
    length = strlen(string);
    if (string[length - 1] == '\n') {
        string[length - 1] = '\0';
    }

    // Count number of words in string
    token = strtok(string, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }

    // Reverse the string
    char reversed[MAX_LENGTH];
    strcpy(reversed, string);
    for (int i = strlen(reversed) - 1; i >= 0; i--) {
        reversed[i] = tolower(reversed[i]);
    }

    // Convert string to uppercase
    char uppercase[MAX_LENGTH];
    strcpy(uppercase, string);
    for (int i = 0; i < strlen(uppercase); i++) {
        uppercase[i] = toupper(uppercase[i]);
    }

    // Remove all vowels from string
    char vowels = "aeiouAEIOU";
    char vowelless[MAX_LENGTH];
    int j = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (strchr(vowels, tolower(string[i])) == NULL) {
            vowelless[j++] = string[i];
        }
    }
    vowelless[j] = '\0';

    // Print results
    printf("Original string: %s\n", string);
    printf("Number of words: %d\n", count);
    printf("Reversed string: %s\n", reversed);
    printf("Uppercase string: %s\n", uppercase);
    printf("Vowelless string: %s\n", vowelless);

    return 0;
}