//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void reverse_string(char *str) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void capitalize_string(char *str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void remove_whitespace(char *str) {
    int i, j;
    for (i = 0, j = 0; str[i]!= '\0'; i++) {
        if (!isspace(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

void remove_vowels(char *str) {
    int i, j;
    for (i = 0, j = 0; str[i]!= '\0'; i++) {
        if (!isalpha(str[i])) {
            str[j++] = str[i];
        } else if (str[i]!= 'a' && str[i]!= 'e' && str[i]!= 'i' && str[i]!= 'o' && str[i]!= 'u') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

void count_chars(char *str) {
    int i, count = 0;
    for (i = 0; str[i]!= '\0'; i++) {
        count++;
    }
    printf("Number of characters in the string: %d\n", count);
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", str);

    reverse_string(str);
    printf("Reversed string: %s\n", str);

    capitalize_string(str);
    printf("Capitalized string: %s\n", str);

    remove_whitespace(str);
    printf("String without whitespace: %s\n", str);

    remove_vowels(str);
    printf("String without vowels: %s\n", str);

    count_chars(str);

    return 0;
}