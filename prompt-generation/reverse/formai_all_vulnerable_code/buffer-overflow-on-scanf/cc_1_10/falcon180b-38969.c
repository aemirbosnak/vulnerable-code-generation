//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isPalindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i])!= tolower(str[len - i - 1])) {
            return false;
        }
    }
    return true;
}

void reverseString(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1);
    if (reversed == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }
    for (int i = len - 1; i >= 0; i--) {
        reversed[i] = str[len - i - 1];
    }
    reversed[len] = '\0';
    strcpy(str, reversed);
    free(reversed);
}

void removeVowels(char* str) {
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int len = strlen(str);
    int newLen = 0;
    char* newStr = malloc(len + 1);
    if (newStr == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }
    for (int i = 0; i < len; i++) {
        if (strchr(vowels, tolower(str[i])) == NULL) {
            newStr[newLen++] = tolower(str[i]);
        }
    }
    newStr[newLen] = '\0';
    strcpy(str, newStr);
    free(newStr);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    printf("Original string: %s\n", str);

    removeVowels(str);
    printf("String without vowels: %s\n", str);

    reverseString(str);
    printf("Reversed string: %s\n", str);

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}