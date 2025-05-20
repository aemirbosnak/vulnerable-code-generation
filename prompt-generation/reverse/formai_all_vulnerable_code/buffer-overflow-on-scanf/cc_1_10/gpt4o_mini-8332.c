//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100

void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void replaceCharacter(char *str, char oldChar, char newChar) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;
        }
    }
}

void splitString(char *str, char delimiter) {
    printf("Splitting the string \"%s\" by '%c':\n", str, delimiter);
    char *token = strtok(str, &delimiter);
    while (token != NULL) {
        printf(" - %s\n", token);
        token = strtok(NULL, &delimiter);
    }
}

int main() {
    char inputString[MAX_STRING_LENGTH];

    printf("🚀 Welcome to the Ultimate C String Manipulation Program! 🎉\n");
    printf("Please enter a string (max %d characters): ", MAX_STRING_LENGTH - 1);
    fgets(inputString, MAX_STRING_LENGTH, stdin);
    inputString[strcspn(inputString, "\n")] = 0; // Remove newline character

    printf("\nYou entered: \"%s\"\n", inputString);

    // Convert to uppercase
    char upperString[MAX_STRING_LENGTH];
    strcpy(upperString, inputString);
    toUpperCase(upperString);
    printf("Uppercase: \"%s\"\n", upperString);
    
    // Convert to lowercase
    char lowerString[MAX_STRING_LENGTH];
    strcpy(lowerString, inputString);
    toLowerCase(lowerString);
    printf("Lowercase: \"%s\"\n", lowerString);

    // Reverse the string
    char reverseStringArray[MAX_STRING_LENGTH];
    strcpy(reverseStringArray, inputString);
    reverseString(reverseStringArray);
    printf("Reversed: \"%s\"\n", reverseStringArray);

    // Replace characters
    char charToReplace, replacementChar;
    printf("Enter a character to replace in your string: ");
    scanf(" %c", &charToReplace);
    printf("Enter a character to replace '%c' with: ", charToReplace);
    scanf(" %c", &replacementChar);
    char replacedString[MAX_STRING_LENGTH];
    strcpy(replacedString, inputString);
    replaceCharacter(replacedString, charToReplace, replacementChar);
    printf("After replacing '%c' with '%c': \"%s\"\n", charToReplace, replacementChar, replacedString);

    // Split the string
    char delimiter;
    printf("Enter a delimiter to split the string: ");
    scanf(" %c", &delimiter);
    char splittedString[MAX_STRING_LENGTH];
    strcpy(splittedString, inputString);
    splitString(splittedString, delimiter);

    printf("\n🎊 Thank you for using the Ultimate C String Manipulation Program! 🎊\n");
    return 0;
}