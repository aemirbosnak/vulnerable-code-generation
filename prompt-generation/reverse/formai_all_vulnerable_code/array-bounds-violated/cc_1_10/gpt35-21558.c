//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

int main(void) {
    char input[MAX_INPUT_SIZE];
    int length, i, j, mid;
    printf("Enter a string: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    length = strlen(input);

    // Check if string is empty
    if (length <= 1) {
        printf("Empty string.\n");
        return 0;
    }
    
    // Remove newline character from input
    if (input[length - 1] == '\n') {
        input[length - 1] = '\0';
        length--;
    }
    
    // Convert string to lowercase for comparison
    for (i = 0; i < length; i++) {
        input[i] = tolower(input[i]);
    }

    for (i = 0, j = length - 1; i <= j; i++, j--) {
        // Skip non-alphanumeric characters
        while (!isalnum(input[i])) {
            i++;
        }
        while (!isalnum(input[j])) {
            j--;
        }
        if (i > j) {
            break;
        }
        if (input[i] != input[j]) {
            printf("Not a palindrome.\n");
            return 0;
        }
    }
    printf("Palindrome!\n");
    return 0;
}