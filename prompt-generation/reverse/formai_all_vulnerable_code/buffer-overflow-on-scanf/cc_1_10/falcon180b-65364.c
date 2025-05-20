//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: authentic
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 1000

// Function to check if a string is a palindrome
bool is_palindrome(char* str) {
    int length = strlen(str);
    int i = 0;
    int j = length - 1;

    // Remove non-alphanumeric characters and convert to lowercase
    char cleaned_str[MAX_LENGTH];
    int cleaned_length = 0;
    while (cleaned_length < length && cleaned_length < MAX_LENGTH) {
        if (isalnum(str[i])) {
            cleaned_str[cleaned_length] = tolower(str[i]);
            cleaned_length++;
        }
        i++;
    }

    cleaned_str[cleaned_length] = '\0';

    // Check if cleaned string is a palindrome
    while (i < j) {
        if (cleaned_str[i]!= cleaned_str[j]) {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

int main() {
    char input_string[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", input_string);

    if (is_palindrome(input_string)) {
        printf("%s is a palindrome.\n", input_string);
    } else {
        printf("%s is not a palindrome.\n", input_string);
    }

    return 0;
}