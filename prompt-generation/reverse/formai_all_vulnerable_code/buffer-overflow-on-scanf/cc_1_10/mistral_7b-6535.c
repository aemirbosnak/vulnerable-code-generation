//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 100

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void capitalizeFirstLetter(char *str) {
    if (strlen(str) > 0) {
        str[0] = toupper(str[0]);
    }
}

void printString(char *str) {
    printf("Original String: %s\n", str);
    reverseString(str);
    printf("Reversed String: %s\n", str);
    capitalizeFirstLetter(str);
    printf("Capitalized First Letter: %s\n", str);
}

bool isPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

bool isAnagram(char *str1, char *str2) {
    int str1Length = strlen(str1);
    int str2Length = strlen(str2);

    if (str1Length != str2Length) {
        return false;
    }

    int count[256] = {0};

    for (int i = 0; i < str1Length; i++) {
        count[str1[i]]++;
    }

    for (int i = 0; i < str2Length; i++) {
        count[str2[i]]--;
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    char inputString1[MAX_LENGTH];
    char inputString2[MAX_LENGTH];

    printf("Enter your first string: ");
    scanf("%s", inputString1);

    printf("Enter your second string: ");
    scanf("%s", inputString2);

    printString(inputString1);

    if (isPalindrome(inputString1)) {
        printf("%s is a palindrome.\n", inputString1);
    } else {
        printf("%s is not a palindrome.\n", inputString1);
    }

    if (isAnagram(inputString1, inputString2)) {
        printf("%s and %s are anagrams.\n", inputString1, inputString2);
    } else {
        printf("%s and %s are not anagrams.\n", inputString1, inputString2);
    }

    return 0;
}