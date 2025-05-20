//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 1000

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int i, j, len;
    char clean_str[MAX_STR_LEN];
    strcpy(clean_str, str);

    // Remove all non-alphanumeric characters and convert to lowercase
    len = strlen(clean_str);
    for (i = 0, j = 0; i < len; i++) {
        if (isalnum(clean_str[i])) {
            clean_str[j++] = tolower(clean_str[i]);
        }
    }
    clean_str[j] = '\0';

    // Check if the cleaned string is equal to its reverse
    int is_pal = 1;
    for (i = 0, j = strlen(clean_str) - 1; i < j; i++, j--) {
        if (clean_str[i]!= clean_str[j]) {
            is_pal = 0;
            break;
        }
    }

    return is_pal;
}

int main() {
    char input_str[MAX_STR_LEN];

    // Prompt the user to enter a string
    printf("Enter a string to check if it's a palindrome: ");
    fgets(input_str, MAX_STR_LEN, stdin);

    // Remove the newline character at the end of the input string
    int len = strlen(input_str);
    if (input_str[len - 1] == '\n') {
        input_str[--len] = '\0';
    }

    // Check if the input string is a palindrome
    if (is_palindrome(input_str)) {
        printf("The input string is a palindrome.\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }

    return 0;
}