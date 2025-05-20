//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void reverse_string(char* str) {
    int length = strlen(str);
    char* reversed = malloc(length + 1);
    char* start = str;
    char* end = str + length - 1;
    while (start < end) {
        *reversed++ = *end--;
        *reversed = '\0';
    }
    strcpy(str, reversed);
    free(reversed);
}

void capitalize_string(char* str) {
    int length = strlen(str);
    char* capitalized = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        if (isalpha(str[i])) {
            capitalized[i] = toupper(str[i]);
        } else {
            capitalized[i] = str[i];
        }
    }
    strcpy(str, capitalized);
    free(capitalized);
}

void remove_spaces(char* str) {
    int length = strlen(str);
    char* no_spaces = malloc(length + 1);
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (!isspace(str[i])) {
            no_spaces[j++] = str[i];
        }
    }
    no_spaces[j] = '\0';
    strcpy(str, no_spaces);
    free(no_spaces);
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    printf("Original string: %s\n", input);
    printf("Reversed string: ");
    reverse_string(input);
    printf("%s\n", input);
    printf("Capitalized string: ");
    capitalize_string(input);
    printf("%s\n", input);
    printf("String with spaces removed: ");
    remove_spaces(input);
    printf("%s\n", input);
    return 0;
}