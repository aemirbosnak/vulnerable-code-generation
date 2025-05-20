//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is alphanumeric
int is_alphanumeric(char c) {
    return (isalnum(c) || isspace(c));
}

// Function to reverse a string
void reverse_string(char *str, int start, int end) {
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int len = strlen(str);

    // If the string has an odd length, there must be a middle character
    if (len % 2 == 1)
        return is_alphanumeric(str[len / 2]) && is_palindrome(str + len / 2 + 1);

    // If the string has an even length, we can check the palindrome property from the middle
    return is_alphanumeric(str[len / 2 - 1]) &&
           tolower(str[len / 2 - 1]) == tolower(str[len / 2]) &&
           is_palindrome(str + len / 2);
}

int main() {
    char input[101];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character from the input
    if (input[strlen(input) - 1] == '\n')
        input[strlen(input) - 1] = '\0';

    if (is_palindrome(input))
        printf("The string is a palindrome!\n");
    else
        printf("The string is not a palindrome.\n");

    return 0;
}