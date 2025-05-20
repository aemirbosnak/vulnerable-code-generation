//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert input to lowercase
void toLowerCase(char *str) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

// Function to check if character is alphanumeric
int isAlnum(char c) {
    return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

// Main function
int main() {
    char input[1000];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    int i = 0, j = strlen(input)-1;
    toLowerCase(input);

    while (i < j) {
        // Check if characters are alphanumeric
        while (!isAlnum(input[i])) {
            i++;
        }
        while (!isAlnum(input[j])) {
            j--;
        }

        // Compare characters
        if (input[i] != input[j]) {
            printf("The input is not a palindrome.");
            return 0;
        }
        i++;
        j--;
    }
    printf("The input is a palindrome.");
    return 0;
}