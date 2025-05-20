//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum input length
#define MAX_LENGTH 100

// Define list of banned words
char bannedWords[][MAX_LENGTH] = {"hack", "virus", "malware"};

// Function to check if input contains a banned word
int containsBannedWord(char *input) {
    int i, n = sizeof(bannedWords) / MAX_LENGTH;
    for (i = 0; i < n; i++) {
        if (strstr(input, bannedWords[i]) != NULL)
            return 1;
    }
    return 0;
}

int main() {
    char input[MAX_LENGTH];
    int isValid = 0;
    printf("Enter your input: ");
    fgets(input, MAX_LENGTH, stdin);
    // Remove trailing newline character
    input[strlen(input) - 1] = '\0';
    
    // Check if input contains banned word
    if (containsBannedWord(input)) {
        printf("Your input contains a banned word.\n");
        printf("Please enter valid input.\n");
        isValid = 0;
    } else {
        // Sanitize input by replacing all non-alphabetic characters with underscores
        int i;
        for (i = 0; i < strlen(input); i++) {
            if (!isalpha(input[i])) {
                input[i] = '_';
            }
        }
        printf("Sanitized input: %s\n", input);
        isValid = 1;
    }
    
    // Repeat until valid input is entered
    while (!isValid) {
        printf("Enter your input: ");
        fgets(input, MAX_LENGTH, stdin);
        // Remove trailing newline character
        input[strlen(input) - 1] = '\0';
        
        // Check if input contains banned word
        if (containsBannedWord(input)) {
            printf("Your input contains a banned word.\n");
            printf("Please enter valid input.\n");
            isValid = 0;
        } else {
            // Sanitize input by replacing all non-alphabetic characters with underscores
            int i;
            for (i = 0; i < strlen(input); i++) {
                if (!isalpha(input[i])) {
                    input[i] = '_';
                }
            }
            printf("Sanitized input: %s\n", input);
            isValid = 1;
        }
    }
    
    printf("Thank you for using our input sanitizer!\n");
    return 0;
}