//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: beginner-friendly
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function to remove non-alphabetic characters and convert to lowercase
void cleanString(char* str) {
    int i = 0;
    int j = 0;

    while (str[i]) {
        if (isalpha(str[i])) {
            str[j] = tolower(str[i]);
            i++;
            j++;
        } else {
            i++;
        }
    }

    str[j] = '\0';
}

// Function to check if a string is a palindrome
bool isPalindrome(char* str) {
    int i = 0;
    int j = strlen(str) - 1;

    while (i < j) {
        if (str[i]!= str[j]) {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

int main() {
    char input[100];

    // Prompt user for input
    printf("Enter a string: ");
    scanf("%s", input);

    // Clean input string
    cleanString(input);

    // Check if input string is a palindrome
    if (isPalindrome(input)) {
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }

    return 0;
}