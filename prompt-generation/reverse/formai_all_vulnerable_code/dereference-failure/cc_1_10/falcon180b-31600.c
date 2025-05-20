//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string
void reverse(char *str) {
    int len = strlen(str);
    char *ptr = str + len - 1;
    while (ptr >= str) {
        *str++ = *ptr--;
    }
    *str = '\0';
}

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i])!= tolower(str[len - 1 - i])) {
            return 0;
        }
    }
    return 1;
}

// Function to convert a string to title case
void titleCase(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

int main() {
    char input[1000];
    char reversed[1000];
    char titleCased[1000];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove trailing newline character
    input[strcspn(input, "\n")] = '\0';

    // Reverse the input string
    strcpy(reversed, input);
    reverse(reversed);

    // Check if the reversed string is a palindrome
    if (isPalindrome(reversed)) {
        printf("The reversed string is a palindrome.\n");
    } else {
        printf("The reversed string is not a palindrome.\n");
    }

    // Convert the input string to title case
    strcpy(titleCased, input);
    titleCase(titleCased);

    printf("Title case of the input string: %s\n", titleCased);

    return 0;
}