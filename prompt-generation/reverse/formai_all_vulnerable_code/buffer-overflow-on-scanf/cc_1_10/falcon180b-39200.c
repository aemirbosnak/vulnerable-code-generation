//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void reverseString(char* str) {
    int length = strlen(str);
    char reversed[MAX_LENGTH] = "";
    for (int i = length - 1; i >= 0; i--) {
        strcat(reversed, str[i]);
    }
    strcpy(str, reversed);
}

void capitalizeString(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

void removeWhiteSpace(char* str) {
    int length = strlen(str);
    char temp[MAX_LENGTH] = "";
    for (int i = 0; i < length; i++) {
        if (!isspace(str[i])) {
            strcat(temp, str[i]);
        }
    }
    strcpy(str, temp);
}

int main() {
    char input[MAX_LENGTH] = "";
    printf("Enter a string: ");
    scanf("%s", input);

    printf("Original string: %s\n", input);

    reverseString(input);
    printf("Reversed string: %s\n", input);

    capitalizeString(input);
    printf("Capitalized string: %s\n", input);

    removeWhiteSpace(input);
    printf("String without white space: %s\n", input);

    return 0;
}