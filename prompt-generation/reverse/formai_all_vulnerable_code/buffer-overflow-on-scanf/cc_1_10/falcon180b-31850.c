//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverse(char* str) {
    int i = 0, j = strlen(str) - 1;
    char temp;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int i = 0, j = strlen(str) - 1;

    while (i < j) {
        if (str[i]!= str[j]) {
            return 0;
        }
        i++;
        j--;
    }

    return 1;
}

// Function to remove all vowels from a string
void removeVowels(char* str) {
    int i = 0;

    while (str[i]) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
            str[i] == 'o' || str[i] == 'u' || str[i] == 'A' ||
            str[i] == 'E' || str[i] == 'I' || str[i] == 'O' ||
            str[i] == 'U') {
            str[i] = '\0';
        }
        i++;
    }
}

int main() {
    char str1[100], str2[100];

    // Get input strings from user
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    // Reverse the strings
    reverse(str1);
    reverse(str2);

    // Check if the strings are palindromes
    if (isPalindrome(str1)) {
        printf("String 1 is a palindrome.\n");
    } else {
        printf("String 1 is not a palindrome.\n");
    }

    if (isPalindrome(str2)) {
        printf("String 2 is a palindrome.\n");
    } else {
        printf("String 2 is not a palindrome.\n");
    }

    // Remove vowels from the strings
    removeVowels(str1);
    removeVowels(str2);

    // Print the modified strings
    printf("Modified string 1: %s\n", str1);
    printf("Modified string 2: %s\n", str2);

    return 0;
}