//Falcon-180B DATASET v1.0 Category: Text processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of words in a string
int countWords(char *str) {
    int count = 0;
    char *token = strtok(str, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Function to reverse a string
char *reverseString(char *str) {
    int len = strlen(str);
    char *revStr = malloc(len + 1);
    int i, j;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        revStr[i] = str[j];
        revStr[j] = str[i];
    }
    revStr[len] = '\0';
    return revStr;
}

// Function to convert all characters in a string to lowercase
void toLowerCase(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char inputString[1000];
    char *outputString;
    int wordCount;
    int i;

    // Get input string from user
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Remove newline character from input string
    if (inputString[strcspn(inputString, "\n")] == '\n') {
        inputString[strcspn(inputString, "\n")] = '\0';
    }

    // Convert string to lowercase
    toLowerCase(inputString);

    // Reverse the string
    outputString = reverseString(inputString);

    // Count the number of words in the string
    wordCount = countWords(outputString);

    // Print the reversed string and word count
    printf("Reversed string: %s\n", outputString);
    printf("Number of words: %d\n", wordCount);

    return 0;
}