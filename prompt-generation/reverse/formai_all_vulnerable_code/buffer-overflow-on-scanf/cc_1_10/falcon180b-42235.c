//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a letter or not
int is_letter(char c) {
    if (isalpha(c)) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if a string is a palindrome or not
int is_palindrome(char *str) {
    int len = strlen(str);
    int i, j;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (!is_letter(str[i]) ||!is_letter(str[j])) {
            continue;
        }
        if (tolower(str[i])!= tolower(str[j])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char filename[100];
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read the file line by line
    char line[100];
    while (fgets(line, 100, fp)!= NULL) {
        // Remove any leading/trailing whitespace from the line
        int i, j;
        for (i = 0, j = strlen(line) - 1; i < j; i++, j--) {
            if (!isspace(line[i]) &&!isspace(line[j])) {
                break;
            }
        }
        line[i] = '\0';

        // Check if the line is a palindrome
        if (is_palindrome(line)) {
            printf("Palindrome found: %s\n", line);
        }
    }

    // Close the file
    fclose(fp);

    return 0;
}