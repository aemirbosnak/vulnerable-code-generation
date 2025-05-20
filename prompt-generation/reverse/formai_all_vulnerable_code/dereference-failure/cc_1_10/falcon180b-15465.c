//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define ESC_SEQUENCE "\\"

void reverse_string(char* str);
void capitalize_string(char* str);
void remove_whitespace(char* str);
void escape_sequences(char* str);

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    printf("Original string: %s\n", input);

    // Remove whitespace
    remove_whitespace(input);
    printf("String with whitespace removed: %s\n", input);

    // Capitalize the string
    capitalize_string(input);
    printf("Capitalized string: %s\n", input);

    // Reverse the string
    reverse_string(input);
    printf("Reversed string: %s\n", input);

    // Escape sequences
    escape_sequences(input);
    printf("String with escaped sequences: %s\n", input);

    return 0;
}

void reverse_string(char* str) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void capitalize_string(char* str) {
    int i;

    for (i = 0; str[i]!= '\0'; i++) {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

void remove_whitespace(char* str) {
    int i, j;

    for (i = 0, j = 0; str[i]!= '\0'; i++) {
        if (!isspace(str[i])) {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}

void escape_sequences(char* str) {
    int i, j;
    char temp;

    for (i = 0, j = 0; str[i]!= '\0'; i++) {
        if (str[i] == ESC_SEQUENCE[0]) {
            j = i + 1;
            while (str[j]!= '\0' && str[j]!= ESC_SEQUENCE[0]) {
                j++;
            }
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i = j - 1;
        }
    }
}