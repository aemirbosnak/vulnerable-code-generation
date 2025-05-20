//Falcon-180B DATASET v1.0 Category: File handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100

// Function to check if a string is a palindrome
int is_palindrome(char* str) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        if (tolower(str[i])!= tolower(str[j])) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main() {
    FILE* file;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    char longest_palindrome[MAX_LINE_LENGTH];
    int longest_palindrome_length = 0;

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file.\n");
        exit(1);
    }

    // Read file line by line
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        // Check if line is a palindrome
        if (is_palindrome(line)) {
            // If line is longer than current longest palindrome, update longest palindrome
            int line_length = strlen(line);
            if (line_length > longest_palindrome_length) {
                strcpy(longest_palindrome, line);
                longest_palindrome_length = line_length;
            }
        }
    }

    // Close file
    fclose(file);

    // Print longest palindrome
    if (longest_palindrome_length > 0) {
        printf("Longest palindrome: %s\n", longest_palindrome);
    } else {
        printf("No palindromes found.\n");
    }

    return 0;
}