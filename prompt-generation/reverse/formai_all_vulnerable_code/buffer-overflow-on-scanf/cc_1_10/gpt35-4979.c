//FormAI DATASET v1.0 Category: String manipulation ; Style: rigorous
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50]; // First string variable
    char str2[50]; // Second string variable

    printf("Enter the first string: ");
    scanf("%s", str1); // Take input from user for first string

    printf("Enter the second string: ");
    scanf("%s", str2); // Take input from user for second string

    int len1 = strlen(str1); // Get the length of first string
    int len2 = strlen(str2); // Get the length of second string

    // Concatenate two strings
    char mergedStr[100];
    strcat(mergedStr, str1);
    strcat(mergedStr, str2);
    printf("Merged string: %s\n", mergedStr);

    // Copy contents of one string to another
    char copiedStr[50];
    strcpy(copiedStr, str1);
    printf("Copied string: %s\n", copiedStr);

    // Compare two strings
    int cmp = strcmp(str1, str2);
    if (cmp == 0) {
        printf("Strings are equal\n");
    } else {
        printf("Strings are not equal\n");
    }

    // Reverse a string
    char reversedStr[50];
    int i, j;
    for (i = 0, j = len1 - 1; i < len1; i++, j--) {
        reversedStr[i] = str1[j];
    }
    reversedStr[i] = '\0';
    printf("Reversed string: %s\n", reversedStr);

    // Convert string to uppercase
    char upperCaseStr[50];
    for (i = 0; str1[i] != '\0'; i++) {
        upperCaseStr[i] = toupper(str1[i]);
    }
    upperCaseStr[i] = '\0';
    printf("String in uppercase: %s\n", upperCaseStr);

    // Convert string to lowercase
    char lowerCaseStr[50];
    for (i = 0; str2[i] != '\0'; i++) {
        lowerCaseStr[i] = tolower(str2[i]);
    }
    lowerCaseStr[i] = '\0';
    printf("String in lowercase: %s\n", lowerCaseStr);

    return 0;
}