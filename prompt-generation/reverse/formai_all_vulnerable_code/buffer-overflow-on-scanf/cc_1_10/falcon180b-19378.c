//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void print_string(char* str) {
    printf("String: %s\n", str);
}

void reverse_string(char* str) {
    int length = strlen(str);
    char reversed_str[MAX_LENGTH];

    for (int i = length - 1; i >= 0; i--) {
        reversed_str[i] = str[length - 1 - i];
    }

    reversed_str[length] = '\0';

    printf("Reversed String: %s\n", reversed_str);
}

void to_uppercase(char* str) {
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        str[i] = toupper(str[i]);
    }

    printf("Uppercase String: %s\n", str);
}

void to_lowercase(char* str) {
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        str[i] = tolower(str[i]);
    }

    printf("Lowercase String: %s\n", str);
}

void count_vowels(char* str) {
    int count = 0;
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        if (isalpha(str[i])) {
            if (tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || tolower(str[i]) == 'i' || tolower(str[i]) == 'o' || tolower(str[i]) == 'u') {
                count++;
            }
        }
    }

    printf("Number of Vowels: %d\n", count);
}

void find_substring(char* str, char* substr) {
    char* pos = strstr(str, substr);

    if (pos!= NULL) {
        printf("Substring found at position: %d\n", pos - str);
    } else {
        printf("Substring not found.\n");
    }
}

int main() {
    char string[MAX_LENGTH];

    printf("Enter a string: ");
    scanf("%s", string);

    print_string(string);
    reverse_string(string);
    to_uppercase(string);
    to_lowercase(string);
    count_vowels(string);

    char substring[MAX_LENGTH];

    printf("Enter a substring to find: ");
    scanf("%s", substring);

    find_substring(string, substring);

    return 0;
}