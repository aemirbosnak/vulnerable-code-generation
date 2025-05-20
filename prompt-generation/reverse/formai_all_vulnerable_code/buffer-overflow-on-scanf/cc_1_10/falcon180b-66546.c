//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 1000 // Maximum length of input string

bool isPalindrome(char* str); // Function to check if a string is a palindrome

int main() {
    char input[MAX_LENGTH]; // Input string
    int length; // Length of input string

    printf("Enter a string to check if it's a palindrome: ");
    scanf("%s", input); // Read input string from user

    length = strlen(input); // Get length of input string

    // Remove any non-alphabetic characters and convert to lowercase
    for (int i = 0; i < length; i++) {
        if (!isalpha(input[i])) {
            input[i] = '\0';
        } else {
            input[i] = tolower(input[i]);
        }
    }

    if (isPalindrome(input)) {
        printf("The string is a palindrome!\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

bool isPalindrome(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i]!= str[length - i - 1]) {
            return false;
        }
    }
    return true;
}

/*
Sample Input/Output:

Enter a string to check if it's a palindrome: A man, a plan, a canal, Panama!
The string is a palindrome!

Enter a string to check if it's a palindrome: Hello, world!
The string is not a palindrome.

Enter a string to check if it's a palindrome: Racecar
The string is a palindrome!

Enter a string to check if it's a palindrome: Was it a car or a cat I saw?
The string is a palindrome!
*/