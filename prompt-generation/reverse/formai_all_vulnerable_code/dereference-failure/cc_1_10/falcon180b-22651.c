//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function to check if a string is palindrome
int isPalindrome(char *str) {
    int len = strlen(str);
    int i = 0, j = len - 1;

    // Remove non-alphanumeric characters and convert to lowercase
    char *cleanStr = malloc(len + 1);
    memset(cleanStr, 0, len + 1);
    for (int k = 0; k < len; k++) {
        if (isalnum(str[k])) {
            cleanStr[k] = tolower(str[k]);
        }
    }

    // Compare clean string with its reverse
    while (i < j) {
        if (cleanStr[i]!= cleanStr[j]) {
            return 0;
        }
        i++;
        j--;
    }

    return 1;
}

int main() {
    char input[1000];

    // Get input from user
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Check if input is palindrome
    if (isPalindrome(input)) {
        printf("The given string is a palindrome.\n");
    } else {
        printf("The given string is not a palindrome.\n");
    }

    return 0;
}