//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove leading and trailing spaces from the input string
    int i, j;
    for (i = 0, j = strlen(input) - 1; i < j; i++, j--) {
        if (!isspace(input[i]) &&!isspace(input[j])) {
            input[i] = toupper(input[i]);
            output[j] = toupper(output[j]);
        }
    }
    output[j] = '\0';

    // Reverse the string
    for (int k = 0; k < strlen(input) / 2; k++) {
        char temp = input[k];
        input[k] = input[strlen(input) - k - 1];
        input[strlen(input) - k - 1] = temp;
    }

    // Convert the string to title case
    for (int l = 0; l < strlen(input); l++) {
        if (isalpha(input[l])) {
            input[l] = toupper(input[l]);
        }
    }

    // Remove all vowels from the string
    char vowels[] = "AEIOUaeiou";
    for (int m = 0; m < strlen(input); m++) {
        if (strchr(vowels, input[m]) == NULL) {
            strcat(output, &input[m]);
        }
    }

    // Remove all consonants from the string
    for (int n = 0; n < strlen(input); n++) {
        if (strchr("AEIOUaeiou", input[n]) == NULL) {
            strcat(output, &input[n]);
        }
    }

    // Print the manipulated string
    printf("Original string: %s\n", input);
    printf("Manipulated string: %s\n", output);

    return 0;
}