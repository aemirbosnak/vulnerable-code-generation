//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

void reverse(char* str) {
    int len = strlen(str);
    char temp;
    for (int i = 0; i < len/2; i++) {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
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

void remove_spaces(char* str) {
    int len = strlen(str);
    int new_len = 0;
    char temp[MAX_SIZE];
    for (int i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            temp[new_len++] = str[i];
        }
    }
    temp[new_len] = '\0';
    strcpy(str, temp);
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Original string: %s\n", str);
    reverse(str);
    printf("Reversed string: %s\n", str);
    capitalize(str);
    printf("Capitalized string: %s\n", str);
    remove_spaces(str);
    printf("String with spaces removed: %s\n", str);
    return 0;
}