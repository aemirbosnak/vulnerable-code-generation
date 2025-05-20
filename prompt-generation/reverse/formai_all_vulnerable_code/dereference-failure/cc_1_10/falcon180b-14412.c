//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void reverse(char* str) {
    int len = strlen(str);
    char* start = str;
    char* end = str + len - 1;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

void capitalize(char* str) {
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

void remove_whitespace(char* str) {
    int len = strlen(str);
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            str[j] = str[i];
            j++;
        }
    }

    str[j] = '\0';
}

int main() {
    char input[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    printf("Original string: %s\n", input);

    reverse(input);
    printf("Reversed string: %s\n", input);

    capitalize(input);
    printf("Capitalized string: %s\n", input);

    remove_whitespace(input);
    printf("String without whitespace: %s\n", input);

    return 0;
}