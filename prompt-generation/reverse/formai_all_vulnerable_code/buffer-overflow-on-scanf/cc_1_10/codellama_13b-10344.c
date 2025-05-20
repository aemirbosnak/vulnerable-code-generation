//Code Llama-13B DATASET v1.0 Category: Firewall ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A romantic firewall program
int main(int argc, char *argv[]) {
    // Declare variables
    char input[100];
    char output[100];
    int i, j, k;

    // Print a message
    printf("Welcome to the romantic firewall program!\n");

    // Loop until user inputs "quit"
    while (strcmp(input, "quit") != 0) {
        // Get user input
        printf("Enter a word: ");
        scanf("%s", input);

        // Check if input is a palindrome
        if (is_palindrome(input)) {
            printf("The word is a palindrome.\n");
        } else {
            printf("The word is not a palindrome.\n");
        }
    }

    // Print goodbye message
    printf("Goodbye!\n");

    return 0;
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int len = strlen(str);
    int i, j;

    // Check if length is odd or even
    if (len % 2 == 0) {
        i = 0;
        j = len - 1;
    } else {
        i = 1;
        j = len - 1;
    }

    // Loop until i >= j
    while (i < j) {
        if (str[i] != str[j]) {
            return 0;
        }
        i++;
        j--;
    }

    // If i == j, the string is a palindrome
    return 1;
}