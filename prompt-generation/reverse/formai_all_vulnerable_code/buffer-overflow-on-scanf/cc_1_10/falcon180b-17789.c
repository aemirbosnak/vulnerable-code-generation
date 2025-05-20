//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to reverse a string
void reverse_string(char *str) {
    int len = strlen(str);
    char *rev_str = malloc(len + 1); // Allocate memory for reversed string
    int i, j;

    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        rev_str[j] = str[i];
    }
    rev_str[len] = '\0'; // Add null terminator to the end of the reversed string

    printf("Reversed string: %s\n", rev_str);
    free(rev_str); // Free memory allocated for the reversed string
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int len = strlen(str);
    char *rev_str = malloc(len + 1); // Allocate memory for reversed string
    int i, j;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i]!= str[j]) {
            free(rev_str); // Free memory allocated for the reversed string
            return 0; // The string is not a palindrome
        }
    }

    free(rev_str); // Free memory allocated for the reversed string
    return 1; // The string is a palindrome
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    scanf("%s", str);

    // Check if the string is a palindrome
    int result = is_palindrome(str);

    if (result) {
        printf("The string is a palindrome\n");
    } else {
        printf("The string is not a palindrome\n");
    }

    return 0;
}