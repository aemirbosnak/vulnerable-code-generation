//FormAI DATASET v1.0 Category: String manipulation ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {
    
    char str1[50];
    char str2[] = "I'm just a string";
    char funnyStr[100];
    
    printf("Hey there! Give me a string: ");
    scanf("%s", str1);
    
    printf("\nYour string is: %s\n", str1);
    printf("My string is: %s\n", str2);
    
    printf("\nNow let's manipulate these strings in a funny way!\n");
    
    // Concatenating two strings
    strcat(funnyStr, str1);
    strcat(funnyStr, str2);
    printf("\nConcatenated string: %s\n", funnyStr);
    
    // Converting to uppercase
    for (int i = 0; i < strlen(funnyStr); i++) {
        funnyStr[i] = toupper(funnyStr[i]);
    }
    printf("\nUppercase string: %s\n", funnyStr);
    
    // Reversing the string
    char reversed[100];
    int j = 0;
    for (int i = strlen(funnyStr) - 1; i >= 0; i--) {
        reversed[j] = funnyStr[i];
        j++;
    }
    printf("\nReversed string: %s\n", reversed);
    
    // Finding a specific character position
    char ch = 'S';
    int position = 0;
    for (int i = 0; i < strlen(funnyStr); i++) {
        if (funnyStr[i] == ch) {
            position = i + 1;
            break;
        }
    }
    printf("\nThe character '%c' is at position %d in the string.\n", ch, position);
    
    // Replacing a character
    char replaceChar = 'M';
    for (int i = 0; i < strlen(funnyStr); i++) {
        if (funnyStr[i] == replaceChar) {
            funnyStr[i] = 'W';
        }
    }
    printf("\nString with character '%c' replaced: %s\n", replaceChar, funnyStr);
    
    // Trimming the string
    char trimmed[100];
    int start = 4;
    int end = 15;
    j = 0;
    for (int i = start; i <= end; i++) {
        trimmed[j] = funnyStr[i];
        j++;
    }
    trimmed[j] = '\0';
    printf("\nTrimmed string: %s\n", trimmed);
    
    printf("\nThat's all folks! Thanks for playing with strings!\n");
    
    return 0;
}