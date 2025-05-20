//FormAI DATASET v1.0 Category: String manipulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to swap two characters
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Function to reverse a string
char* reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0, j = len-1; i < j; i++, j--)
        swap(&str[i], &str[j]);
    return str;
}

// Function to reverse words in a string
char* reverseWords(char *str) {
    int i = 0, j = 0;
    int len = strlen(str);
    while (i < len) {
        while (i < len && str[i] == ' ') i++;  // Skip leading spaces
        j = i + 1;
        while (j < len && str[j] != ' ') j++;  // Find the end of the current word
        swap(&str[i], &str[j-1]);              // Reverse the current word
        i = j;
    }
    return str;
}

// Function to capitalize the first letter of each word in a string
char* capitalizeWords(char *str) {
    int len = strlen(str);
    if (len == 0) return str;
    str[0] = toupper(str[0]);                 // Capitalize the first letter
    for (int i = 1; i < len; i++) {
        if (str[i-1] == ' ')                  // If previous character is space
            str[i] = toupper(str[i]);         // Capitalize the current character
        else
            str[i] = tolower(str[i]);         // Else, convert to lowercase
    }
    return str;
}

int main() {

    char str[100], c;
    printf("Enter string: ");
    scanf("%[^\n]", str);                      // Read the input string

    // Reverse the string
    char *revStr = reverseString(str);
    printf("\nReversed String: %s", revStr);

    // Reverse the words in the string
    char *revWordsStr = reverseWords(str);
    printf("\nWords Reversed String: %s", revWordsStr);

    // Capitalize the first letter of each word in the string
    char *capitalizedStr = capitalizeWords(str);
    printf("\nCapitalized String: %s", capitalizedStr);

    return 0;
}