//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is an alphabet or not
int is_alphabet(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

// Function to check if a given string is a palindrome or not
int is_palindrome(char *str, int start, int end) {
    if (start >= end)
        return 1;
    if (isalpha(str[start])) {
        if (tolower(str[start]) != tolower(str[end]))
            return 0;
    }
    return is_palindrome(str, start + 1, end - 1);
}

// Function to reverse the given string
void reverse_string(char *str, int start, int end) {
    char temp;
    if (start >= end)
        return;
    temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverse_string(str, start + 1, end - 1);
}

// Function to print the given string in reverse order
void print_reverse(char *str) {
    int len = strlen(str);
    reverse_string(str, 0, len - 1);
    printf("%s\n", str);
}

// Function to check if the given string is a romantic palindrome or not
// A romantic palindrome is a palindrome where the first and last characters are the same alphabet and the middle is the reversed version of the first half
int is_romantic_palindrome(char *str) {
    if (strlen(str) <= 1)
        return 1;
    if (isalpha(str[0]) && isalpha(str[strlen(str) - 1])) {
        if (tolower(str[0]) != tolower(str[strlen(str) - 1]))
            return 0;
        char *first_half = (char *)malloc((strlen(str) / 2 + 1) * sizeof(char));
        strncpy(first_half, str, strlen(str) / 2);
        first_half[strlen(str) / 2] = '\0';
        int mid = strlen(str) / 2;
        int last_index = strlen(str) - 1;
        reverse_string(str, mid, last_index);
        if (is_palindrome(str, 0, mid - 1) && strcmp(first_half, str) == 0)
            return 1;
    }
    return 0;
}

// Main function
int main() {
    char str[101];
    printf("Enter a string: ");
    scanf("%s", str);
    if (is_romantic_palindrome(str))
        printf("The given string is a romantic palindrome.\n");
    else
        printf("The given string is not a romantic palindrome.\n");
    print_reverse(str);
    return 0;
}