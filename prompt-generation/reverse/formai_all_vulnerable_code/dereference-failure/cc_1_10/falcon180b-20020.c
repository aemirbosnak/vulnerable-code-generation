//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string
void reverse(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1);
    for (int i = len - 1; i >= 0; i--) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0';
    printf("Reversed string: %s\n", reversed);
    free(reversed);
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i])!= tolower(str[len - 1 - i])) {
            return 0;
        }
    }
    return 1;
}

// Function to remove all vowels from a string
void removeVowels(char* str) {
    int len = strlen(str);
    char* vowels = "aeiouAEIOU";
    char* result = malloc(len + 1);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (!strchr(vowels, tolower(str[i]))) {
            result[j++] = tolower(str[i]);
        }
    }
    result[j] = '\0';
    printf("Result: %s\n", result);
    free(result);
}

// Function to count the number of words in a string
int countWords(char* str) {
    int len = strlen(str);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (isspace(str[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    char* input = "A man a plan a canal Panama";
    printf("Original string: %s\n", input);

    reverse(input);

    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    removeVowels(input);

    printf("Number of words: %d\n", countWords(input));

    return 0;
}