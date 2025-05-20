//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 1000

void reverse(char* str) {
    int len = strlen(str);
    char temp[len];
    strcpy(temp, str);
    strcpy(str, temp + len - 1);
    strcat(str, temp);
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
    char temp[len];
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            temp[j++] = str[i];
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

void remove_punctuation(char* str) {
    int len = strlen(str);
    char temp[len];
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (!ispunct(str[i])) {
            temp[j++] = str[i];
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

void replace_string(char* str, char* old_str, char* new_str) {
    int len1 = strlen(old_str);
    int len2 = strlen(new_str);
    char temp[MAX_LENGTH];
    int j = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (strncmp(str + i, old_str, len1) == 0) {
            strncpy(temp + j, new_str, len2);
            j += len2;
            i += len1 - 1;
        } else {
            temp[j++] = str[i];
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Original string: %s\n", str);

    reverse(str);
    printf("Reversed string: %s\n", str);

    capitalize(str);
    printf("Capitalized string: %s\n", str);

    remove_spaces(str);
    printf("String without spaces: %s\n", str);

    remove_punctuation(str);
    printf("String without punctuation: %s\n", str);

    char old_str[MAX_LENGTH] = "world";
    char new_str[MAX_LENGTH] = "universe";
    replace_string(str, old_str, new_str);
    printf("String with '%s' replaced with '%s': %s\n", old_str, new_str, str);

    return 0;
}