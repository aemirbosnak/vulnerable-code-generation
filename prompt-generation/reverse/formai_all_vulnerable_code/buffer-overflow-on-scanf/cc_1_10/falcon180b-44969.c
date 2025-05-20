//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function to reverse a string
void reverseString(char* str) {
    int length = strlen(str);
    int i = 0;
    char temp;
    for (int j = length - 1; j >= 0; j--) {
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
        i++;
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i]!= str[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to remove all vowels from a string
void removeVowels(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || tolower(str[i]) == 'i' || tolower(str[i]) == 'o' || tolower(str[i]) == 'u') {
            str[i] = '\0';
        }
    }
}

// Function to replace all occurrences of a character in a string
void replaceChar(char* str, char oldChar, char newChar) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;
        }
    }
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", input);

    // Reverse the string
    reverseString(input);
    printf("Reversed string: %s\n", input);

    // Check if the string is a palindrome
    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    // Remove all vowels from the string
    removeVowels(input);
    printf("String without vowels: %s\n", input);

    // Replace all occurrences of a character in the string
    char oldChar, newChar;
    printf("Enter a character to replace: ");
    scanf(" %c", &oldChar);
    printf("Enter the new character: ");
    scanf(" %c", &newChar);
    replaceChar(input, oldChar, newChar);
    printf("String with %c replaced by %c: %s\n", oldChar, newChar, input);

    return 0;
}