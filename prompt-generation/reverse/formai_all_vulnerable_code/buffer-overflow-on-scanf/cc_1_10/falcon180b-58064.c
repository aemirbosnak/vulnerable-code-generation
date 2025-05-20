//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void reverse_string(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void capitalize_string(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

void remove_whitespace(char* str) {
    int length = strlen(str);
    int new_length = 0;
    for (int i = 0; i < length; i++) {
        if (!isspace(str[i])) {
            str[new_length++] = str[i];
        }
    }
    str[new_length] = '\0';
}

void count_vowels(char* str) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            count++;
        }
    }
    printf("The number of vowels in the string is: %d\n", count);
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", str);

    // Example usage of functions
    reverse_string(str);
    printf("Reversed string: %s\n", str);

    capitalize_string(str);
    printf("Capitalized string: %s\n", str);

    remove_whitespace(str);
    printf("String without whitespace: %s\n", str);

    count_vowels(str);

    return 0;
}