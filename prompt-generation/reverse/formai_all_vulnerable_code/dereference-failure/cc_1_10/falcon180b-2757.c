//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverse(char *str) {
    int len = strlen(str);
    char *end = str + len - 1;
    while (str < end) {
        char temp = *str;
        *str = *end;
        *end = temp;
        str++;
        end--;
    }
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i]!= str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to translate text to alien language
void translate(char *input) {
    int len = strlen(input);
    char *output = malloc(len + 1);
    strcpy(output, input);

    // Reverse the string
    reverse(output);

    // Translate each character to alien language
    for (int i = 0; i < len; i++) {
        if (isalpha(output[i])) {
            if (isupper(output[i])) {
                output[i] = output[i] + 13;
            } else {
                output[i] = output[i] + 7;
            }
        }
    }

    // Reverse the string back to original order
    reverse(output);

    // Print the translated text
    printf("Translated text: %s\n", output);
}

int main() {
    char input[1000];

    // Get input from user
    printf("Enter text to translate: ");
    fgets(input, 1000, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Call translate function
    translate(input);

    return 0;
}