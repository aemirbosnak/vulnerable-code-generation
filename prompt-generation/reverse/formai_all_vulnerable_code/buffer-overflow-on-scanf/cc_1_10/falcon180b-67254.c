//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void reverseString(char* str) {
    int length = strlen(str);
    char temp[MAX_LENGTH];
    strcpy(temp, str);

    for (int i = 0; i < length / 2; i++) {
        char tempChar = temp[i];
        temp[i] = temp[length - i - 1];
        temp[length - i - 1] = tempChar;
    }

    strcpy(str, temp);
}

void replaceChar(char* str, char oldChar, char newChar) {
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;
        }
    }
}

void capitalizeString(char* str) {
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

void removeWhitespace(char* str) {
    int length = strlen(str);
    int newLength = 0;

    for (int i = 0; i < length; i++) {
        if (!isspace(str[i])) {
            str[newLength++] = str[i];
        }
    }

    str[newLength] = '\0';
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", input);

    printf("Original string: %s\n", input);

    reverseString(input);
    printf("Reversed string: %s\n", input);

    char oldChar = 'e';
    char newChar = 'a';
    replaceChar(input, oldChar, newChar);
    printf("String with %c replaced by %c: %s\n", oldChar, newChar, input);

    capitalizeString(input);
    printf("Capitalized string: %s\n", input);

    removeWhitespace(input);
    printf("String with whitespace removed: %s\n", input);

    return 0;
}