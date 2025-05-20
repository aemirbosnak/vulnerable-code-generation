//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

void reverseString(char* str) {
    int length = strlen(str);
    char* reversed = malloc(length + 1);
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        reversed[i] = str[j];
        reversed[j] = str[i];
    }
    reversed[length] = '\0';
    printf("Reversed string: %s\n", reversed);
}

void concatenateStrings(char* str1, char* str2) {
    int length1 = strlen(str1), length2 = strlen(str2);
    char* concatenated = malloc(length1 + length2 + 1);
    strcpy(concatenated, str1);
    strcat(concatenated, str2);
    printf("Concatenated string: %s\n", concatenated);
}

void substring(char* str, int start, int end) {
    int length = strlen(str);
    char* sub = malloc(end - start + 1);
    strncpy(sub, str + start, end - start);
    sub[end - start] = '\0';
    printf("Substring: %s\n", sub);
}

void replaceCharacter(char* str, char oldChar, char newChar) {
    int length = strlen(str);
    char* replaced = malloc(length + 1);
    int i;
    for (i = 0; i < length; i++) {
        if (str[i] == oldChar) {
            replaced[i] = newChar;
        } else {
            replaced[i] = str[i];
        }
    }
    replaced[length] = '\0';
    printf("Replaced string: %s\n", replaced);
}

int main() {
    char str1[MAX_LENGTH] = "Hello, world!";
    char str2[MAX_LENGTH] = "How are you?";
    char str3[MAX_LENGTH];
    int i;

    // Example 1: Reverse a string
    reverseString(str1);

    // Example 2: Concatenate two strings
    strcpy(str3, str1);
    strcat(str3, str2);

    // Example 3: Extract a substring
    substring(str3, 5, 10);

    // Example 4: Replace a character
    replaceCharacter(str3, 'o', '0');

    return 0;
}