//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 1000

void reverse_string(char* str) {
    int len = strlen(str);
    char* tmp = malloc(len + 1);
    strcpy(tmp, str);
    for (int i = 0; i < len / 2; i++) {
        char c = tmp[i];
        tmp[i] = tmp[len - i - 1];
        tmp[len - i - 1] = c;
    }
    strcpy(str, tmp);
    free(tmp);
}

void capitalize_string(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

void remove_whitespace(char* str) {
    int len = strlen(str);
    char* tmp = malloc(len + 1);
    strcpy(tmp, str);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (!isspace(tmp[i])) {
            tmp[j++] = tmp[i];
        }
    }
    tmp[j] = '\0';
    strcpy(str, tmp);
    free(tmp);
}

void count_words(char* str) {
    int len = strlen(str);
    int word_count = 1;
    for (int i = 0; i < len; i++) {
        if (isspace(str[i])) {
            word_count++;
        }
    }
    printf("Number of words: %d\n", word_count);
}

int main() {
    char input_str[MAX_STR_LEN];
    printf("Enter a string: ");
    scanf("%s", input_str);
    printf("Original string: %s\n", input_str);
    reverse_string(input_str);
    printf("Reversed string: %s\n", input_str);
    capitalize_string(input_str);
    printf("Capitalized string: %s\n", input_str);
    remove_whitespace(input_str);
    printf("String without whitespace: %s\n", input_str);
    count_words(input_str);
    return 0;
}