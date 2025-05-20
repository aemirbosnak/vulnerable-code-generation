//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: random
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Function to check if a string is a palindrome
bool is_palindrome(char* str) {
    int i, j;
    int len = strlen(str);

    // Remove non-alphanumeric characters and convert to lowercase
    for (i = 0, j = 0; i < len; i++) {
        if (isalnum(str[i])) {
            str[j++] = tolower(str[i]);
        }
    }
    str[j] = '\0';
    len = j;

    // Check if the string is a palindrome
    for (i = 0; i < len/2; i++) {
        if (str[i]!= str[len-i-1]) {
            return false;
        }
    }

    return true;
}

int main() {
    char* input_str;
    bool is_palindrome_result;

    // Get input string from user
    printf("Enter a string: ");
    scanf("%s", input_str);

    // Check if the string is a palindrome
    is_palindrome_result = is_palindrome(input_str);

    // Print result
    if (is_palindrome_result) {
        printf("%s is a palindrome.\n", input_str);
    } else {
        printf("%s is not a palindrome.\n", input_str);
    }

    return 0;
}