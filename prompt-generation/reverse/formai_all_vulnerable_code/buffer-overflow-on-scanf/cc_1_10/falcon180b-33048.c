//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000

void print_string_in_reverse(char* str) {
    int length = strlen(str);
    for(int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void remove_whitespace_and_punctuation(char* str) {
    int length = strlen(str);
    char new_str[MAX_STRING_LENGTH];
    int new_length = 0;
    bool in_word = false;
    for(int i = 0; i < length; i++) {
        if(isalnum(str[i])) {
            in_word = true;
        } else if(in_word) {
            new_str[new_length++] = str[i];
            in_word = false;
        }
    }
    if(in_word) {
        new_str[new_length++] = str[length - 1];
    }
    new_str[new_length] = '\0';
    strcpy(str, new_str);
}

void reverse_string(char* str) {
    int length = strlen(str);
    char new_str[MAX_STRING_LENGTH];
    int new_length = 0;
    for(int i = length - 1; i >= 0; i--) {
        new_str[new_length++] = str[i];
    }
    new_str[new_length] = '\0';
    strcpy(str, new_str);
}

void capitalize_first_letter(char* str) {
    str[0] = toupper(str[0]);
}

void convert_to_lowercase(char* str) {
    for(int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char input_string[MAX_STRING_LENGTH];
    printf("Enter a string: ");
    scanf("%s", input_string);

    remove_whitespace_and_punctuation(input_string);
    printf("String without whitespace and punctuation: %s\n", input_string);

    reverse_string(input_string);
    printf("String in reverse: %s\n", input_string);

    capitalize_first_letter(input_string);
    printf("String with first letter capitalized: %s\n", input_string);

    convert_to_lowercase(input_string);
    printf("String in lowercase: %s\n", input_string);

    return 0;
}