//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to concatenate two strings
char *concatenate(char *str1, char *str2) {
    // Check if either string is NULL
    if (str1 == NULL || str2 == NULL) {
        return NULL;
    }

    // Allocate memory for the concatenated string
    char *newStr = (char *)malloc(strlen(str1) + strlen(str2) + 1);
    if (newStr == NULL) {
        return NULL;
    }

    // Copy the first string into the new string
    strcpy(newStr, str1);

    // Concatenate the second string to the end of the first string
    strcat(newStr, str2);

    // Return the concatenated string
    return newStr;
}

// Function to reverse a string
char *reverse(char *str) {
    // Check if the string is NULL
    if (str == NULL) {
        return NULL;
    }

    // Allocate memory for the reversed string
    char *newStr = (char *)malloc(strlen(str) + 1);
    if (newStr == NULL) {
        return NULL;
    }

    // Copy the string into the new string
    strcpy(newStr, str);

    // Reverse the string
    for (int i = 0; i < strlen(newStr) / 2; i++) {
        char temp = newStr[i];
        newStr[i] = newStr[strlen(newStr) - i - 1];
        newStr[strlen(newStr) - i - 1] = temp;
    }

    // Return the reversed string
    return newStr;
}

// Function to find the longest common substring
char *longestCommonSubstring(char *str1, char *str2) {
    // Check if either string is NULL
    if (str1 == NULL || str2 == NULL) {
        return NULL;
    }

    // Find the lengths of the strings
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Create a matrix to store the lengths of the longest common substrings
    int **matrix = (int **)malloc(sizeof(int *) * len1);
    for (int i = 0; i < len1; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * len2);
    }

    // Initialize the first row and column of the matrix
    for (int i = 0; i < len1; i++) {
        matrix[i][0] = 0;
    }
    for (int j = 0; j < len2; j++) {
        matrix[0][j] = 0;
    }

    // Fill in the rest of the matrix
    for (int i = 1; i < len1; i++) {
        for (int j = 1; j < len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }

    // Find the longest common substring
    int maxLen = 0;
    int maxI = 0;
    int maxJ = 0;
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (matrix[i][j] > maxLen) {
                maxLen = matrix[i][j];
                maxI = i;
                maxJ = j;
            }
        }
    }

    // Allocate memory for the longest common substring
    char *subStr = (char *)malloc(maxLen + 1);
    if (subStr == NULL) {
        return NULL;
    }

    // Copy the longest common substring from the matrix
    for (int i = maxI - maxLen + 1; i <= maxI; i++) {
        subStr[i - (maxI - maxLen + 1)] = str1[i];
    }
    subStr[maxLen] = '\0';

    // Return the longest common substring
    return subStr;
}

int main() {
    // Test the concatenate function
    char *str1 = "Hello";
    char *str2 = "World";
    char *newStr = concatenate(str1, str2);
    printf("Concatenated string: %s\n", newStr);

    // Test the reverse function
    char *reversedStr = reverse(str1);
    printf("Reversed string: %s\n", reversedStr);

    // Test the longestCommonSubstring function
    char *subStr = longestCommonSubstring(str1, str2);
    printf("Longest common substring: %s\n", subStr);

    // Free the allocated memory
    free(newStr);
    free(reversedStr);
    free(subStr);

    return 0;
}