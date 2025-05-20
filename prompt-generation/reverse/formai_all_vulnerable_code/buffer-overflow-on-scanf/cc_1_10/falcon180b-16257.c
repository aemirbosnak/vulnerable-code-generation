//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 1000 // Maximum length of a string

// Function to reverse a string
void reverseString(char* str) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to check if two strings are anagrams
int areAnagrams(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1!= len2) {
        return 0; // Strings are not of equal length, so they cannot be anagrams
    }

    char* copy1 = malloc(len1 * sizeof(char));
    char* copy2 = malloc(len2 * sizeof(char));

    strcpy(copy1, str1);
    strcpy(copy2, str2);

    reverseString(copy1);
    reverseString(copy2);

    if (strcmp(copy1, copy2) == 0) {
        return 1; // Strings are anagrams
    } else {
        return 0; // Strings are not anagrams
    }
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    if (areAnagrams(str1, str2)) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }

    return 0;
}