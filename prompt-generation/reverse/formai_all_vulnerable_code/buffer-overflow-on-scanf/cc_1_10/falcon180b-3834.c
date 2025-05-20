//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to count the number of words in a string
int countWords(char* str) {
    int count = 0;
    char* token = strtok(str, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Function to reverse a string
void reverseString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to convert a string to uppercase
void toUpperCase(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to convert a string to lowercase
void toLowerCase(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to remove all whitespace from a string
void removeWhitespace(char* str) {
    int len = strlen(str);
    int newLen = 0;
    for (int i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            str[newLen++] = str[i];
        }
    }
    str[newLen] = '\0';
}

// Function to replace all occurrences of a character with another character
void replaceChar(char* str, char oldChar, char newChar) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;
        }
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Example 1: Count the number of words in the string
    int numWords = countWords(str);
    printf("Number of words: %d\n", numWords);

    // Example 2: Reverse the string
    reverseString(str);
    printf("Reversed string: %s\n", str);

    // Example 3: Convert the string to uppercase
    toUpperCase(str);
    printf("Uppercase string: %s\n", str);

    // Example 4: Convert the string to lowercase
    toLowerCase(str);
    printf("Lowercase string: %s\n", str);

    // Example 5: Remove all whitespace from the string
    removeWhitespace(str);
    printf("String without whitespace: %s\n", str);

    // Example 6: Replace all occurrences of a character with another character
    replaceChar(str, 'a', 'b');
    printf("String with replacements: %s\n", str);

    return 0;
}