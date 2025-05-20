//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: happy
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string
void reverse(char* str) {
    int len = strlen(str);
    char rev[len];
    int i, j;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        rev[i] = tolower(str[j]);
        rev[j] = tolower(str[i]);
    }
    rev[i] = '\0';
    printf("Reversed string: %s\n", rev);
}

// Function to count the number of vowels in a string
int countVowels(char* str) {
    int count = 0;
    while (*str) {
        if (tolower(*str) == 'a' || tolower(*str) == 'e' || tolower(*str) == 'i' || tolower(*str) == 'o' || tolower(*str) == 'u') {
            count++;
        }
        str++;
    }
    return count;
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i])!= tolower(str[len - i - 1])) {
            return 0;
        }
    }
    return 1;
}

// Function to remove all whitespace characters from a string
void removeWhitespace(char* str) {
    int len = strlen(str);
    char newStr[len];
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            newStr[j++] = tolower(str[i]);
        }
    }
    newStr[j] = '\0';
    printf("String without whitespace: %s\n", newStr);
}

// Main function
int main() {
    char str1[100];
    char str2[100];
    char str3[100];
    char str4[100];

    // Get user input for strings
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    printf("Enter third string: ");
    scanf("%s", str3);
    printf("Enter fourth string: ");
    scanf("%s", str4);

    // Call functions to manipulate strings
    reverse(str1);
    countVowels(str2);
    isPalindrome(str3);
    removeWhitespace(str4);

    return 0;
}