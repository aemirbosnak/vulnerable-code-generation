//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to convert a string to uppercase
void toUppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to find the length of a string manually
int stringLength(const char *str) {
    int length = 0;
    while (*str++) {
        length++;
    }
    return length;
}

// Function to create a substring from a string
char* substring(const char *src, int start, int len) {
    if (start < 0 || start >= stringLength(src) || len < 0) {
        return NULL;
    }
    
    char *sub = (char*)malloc(len + 1);
    if (sub == NULL) {
        return NULL; // Memory allocation error
    }

    int i;
    for (i = 0; i < len && src[start + i]; i++) {
        sub[i] = src[start + i];
    }
    sub[i] = '\0'; // Null-terminate the substring
    return sub;
}

// Function to concatenate two strings
char* concatenate(const char *str1, const char *str2) {
    int len1 = stringLength(str1);
    int len2 = stringLength(str2);
    
    char *result = (char*)malloc(len1 + len2 + 1);
    if (result == NULL) {
        return NULL; // Memory allocation error
    }

    strcpy(result, str1);
    strcat(result, str2);
    
    return result;
}

// Main function to demonstrate string manipulation
int main() {
    char inputStr[100];
    printf("Welcome to the String Manipulation Program!\n");
    printf("Please enter a string (max 99 characters): ");
    fgets(inputStr, sizeof(inputStr), stdin); 
    inputStr[strcspn(inputStr, "\n")] = 0; // Remove the newline character if present

    printf("\nYou entered: '%s'\n", inputStr);

    // Reverse the string
    reverseString(inputStr);
    printf("Reversed string: '%s'\n", inputStr);

    // Convert to uppercase
    toUppercase(inputStr);
    printf("Uppercase string: '%s'\n", inputStr);

    // Get substring
    int start, length;
    printf("Enter starting position (0-based) for substring: ");
    scanf("%d", &start);
    printf("Enter length of substring: ");
    scanf("%d", &length);
    
    char *subStr = substring(inputStr, start, length);
    if (subStr != NULL) {
        printf("Substring (position %d, length %d): '%s'\n", start, length, subStr);
        free(subStr);
    } else {
        printf("Invalid substring parameters.\n");
    }

    // Concatenate with another string
    char anotherStr[100];
    printf("Enter another string to concatenate: ");
    getchar(); // Clear the newline from the input buffer
    fgets(anotherStr, sizeof(anotherStr), stdin);
    anotherStr[strcspn(anotherStr, "\n")] = 0; // Remove the newline character if present

    char *concatenatedStr = concatenate(inputStr, anotherStr);
    if (concatenatedStr != NULL) {
        printf("Concatenated string: '%s'\n", concatenatedStr);
        free(concatenatedStr);
    } else {
        printf("Memory allocation error for concatenation.\n");
    }

    printf("Thank you for using the String Manipulation Program! Goodbye!\n");

    return 0;
}