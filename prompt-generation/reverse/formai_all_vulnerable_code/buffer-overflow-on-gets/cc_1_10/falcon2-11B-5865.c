//Falcon2-11B DATASET v1.0 Category: Palindrome Checker ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100], palindrome[100];
    int i, j;

    // Get input string
    printf("Enter a string: ");
    gets(str);

    // Convert to lowercase
    for (i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }

    // Reverse string
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    // Check if string is palindrome
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (str[i]!= str[j]) {
            printf("%s is not a palindrome.\n", str);
            return 0;
        }
    }

    // Print palindrome
    printf("%s is a palindrome.\n", str);

    // Get input string again
    printf("Enter another string: ");
    gets(str);

    // Check if string is palindrome
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (str[i]!= str[j]) {
            printf("Romeo: %s is not a palindrome.\n", str);
            return 0;
        }
    }

    // Print palindrome
    printf("Romeo: %s is a palindrome.\n", str);

    return 0;
}