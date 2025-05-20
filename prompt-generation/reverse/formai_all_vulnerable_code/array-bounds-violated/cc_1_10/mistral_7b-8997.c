//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: lively
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

void reverse(char *str, int start, int end) {
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int isPalindrome(char *str) {
    int len = strlen(str);
    if (len <= 1)
        return 1;

    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1])
            return 0;
    }

    return 1;
}

int main() {
    char input[MAX_LEN];
    int len;
    printf("Welcome to the Palindrome Checker!\n");
    printf("Enter a string (max length %d): ", MAX_LEN);
    fgets(input, sizeof(input), stdin);

    len = strlen(input);
    if (len > MAX_LEN) {
        printf("Error: string too long!\n");
        return 1;
    }

    // Remove newline character if present
    if (input[len - 1] == '\n')
        input[len - 1] = '\0';

    printf("You entered: %s\n", input);

    // Make the string lowercase for comparison
    for (int i = 0; i < len; i++) {
        if (isalpha(input[i]))
            input[i] = tolower(input[i]);
    }

    // Check if the string is a palindrome
    if (isPalindrome(input))
        printf("Congratulations! Your string is a palindrome!\n");
    else {
        reverse(input, 0, len - 1); // Reverse the string
        if (strcmp(input, input + len - 1) == 0) // Compare with the original string
            printf("Your string is a palindrome (case insensitive)!\n");
        else
            printf("Sorry, your string is not a palindrome.\n");
    }

    return 0;
}