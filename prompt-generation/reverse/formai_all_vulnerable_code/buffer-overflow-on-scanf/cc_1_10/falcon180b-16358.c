//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function to reverse a string
void reverse(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1);
    int i = 0;
    for (int j = len - 1; j >= 0; j--) {
        reversed[i] = str[j];
        i++;
    }
    reversed[i] = '\0';
    printf("Reversed string: %s\n", reversed);
    free(reversed);
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i]!= str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to convert a string to uppercase
void toUpper(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }
    printf("String in uppercase: %s\n", str);
}

// Function to convert a string to lowercase
void toLower(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
    printf("String in lowercase: %s\n", str);
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
    printf("Number of vowels: %d\n", count);
    return count;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    printf("Original string: %s\n", str);
    reverse(str);
    toUpper(str);
    toLower(str);
    countVowels(str);

    return 0;
}