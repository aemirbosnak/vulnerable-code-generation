//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: excited
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to remove all vowels from a given string
void removeVowels(char* str) {
    int i = 0;
    while (str[i]!= '\0') {
        if (tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || tolower(str[i]) == 'i' || tolower(str[i]) == 'o' || tolower(str[i]) == 'u') {
            str[i] = '\0';
        }
        i++;
    }
}

// Function to reverse a given string
void reverseString(char* str) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to check if a given string is a palindrome
int isPalindrome(char* str) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        if (tolower(str[i])!= tolower(str[j])) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Remove all vowels from the string
    printf("String without vowels: ");
    removeVowels(str);
    printf("%s\n", str);

    // Reverse the string
    printf("Reversed string: ");
    reverseString(str);
    printf("%s\n", str);

    // Check if the string is a palindrome
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}