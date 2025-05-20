//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void capitalize(char* str) {
    int i = 0;
    while (str[i]) {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
        i++;
    }
}

void reverse(char* str) {
    int i = 0;
    int j = strlen(str) - 1;
    char temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

void remove_whitespace(char* str) {
    int i = 0;
    int j = 0;
    while (str[i]) {
        if (!isspace(str[i])) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

int main() {
    char input_string[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", input_string);

    printf("Original string: %s\n", input_string);

    capitalize(input_string);
    printf("Capitalized string: %s\n", input_string);

    reverse(input_string);
    printf("Reversed string: %s\n", input_string);

    remove_whitespace(input_string);
    printf("String with whitespace removed: %s\n", input_string);

    return 0;
}