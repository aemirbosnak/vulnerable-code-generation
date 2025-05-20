//FormAI DATASET v1.0 Category: Text processing ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Text Processor!\n");

    // Ask user for input
    char input[100];
    printf("Please enter a string: ");
    fgets(input, 100, stdin);

    // Remove newline character from input
    int len = strlen(input);
    if (input[len-1] == '\n') {
        input[len-1] = '\0';
    }

    // Count number of vowels in input
    int vowels = 0;
    for (int i = 0; i < len; i++) {
        char c = input[i];
        // Check if char is a vowel
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            vowels++;
        }
    }
    printf("The number of vowels in the string is: %d\n", vowels);

    // Reverse the input string
    char reversed[100];
    int j = 0;
    for (int i = len-1; i >= 0; i--) {
        reversed[j] = input[i];
        j++;
    }
    reversed[j] = '\0';
    printf("The reverse of the string is: %s\n", reversed);

    // Convert input to uppercase
    char uppercase[100];
    for (int i = 0; i < len; i++) {
        char c = input[i];
        if (c >= 'a' && c <= 'z') {
            // Convert lowercase to uppercase
            uppercase[i] = c - 32;
        } else {
            uppercase[i] = c;
        }
    }
    uppercase[len] = '\0';
    printf("The uppercase version of the string is: %s\n", uppercase);

    // Replace spaces with underscores
    char replaced[100];
    for (int i = 0; i < len; i++) {
        char c = input[i];
        if (c == ' ') {
            replaced[i] = '_';
        } else {
            replaced[i] = c;
        }
    }
    replaced[len] = '\0';
    printf("The string with spaces replaced by underscores is: %s\n", replaced);

    printf("Thank you for using the Text Processor!\n");
    return 0;
}