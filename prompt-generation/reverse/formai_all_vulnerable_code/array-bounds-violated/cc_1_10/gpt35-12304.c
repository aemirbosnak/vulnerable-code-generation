//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char vowels[] = {'a', 'e', 'i', 'o', 'u'};

int is_vowel(char ch) {
    for (int i = 0; i < sizeof(vowels)/sizeof(char); i++) {
        if (ch == vowels[i]) {
            return 1;
        }
    }
    return 0;
}

void convert(char* str, char* result) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (is_vowel(str[i])) {
            result[j++] = str[i];
        }
        if (str[i] == 'c') {
            result[j++] = 'x';
        }
        if (str[i] == 'd') {
            result[j++] = 't';
        }
        if (str[i] == 'h') {
            result[j++] = 'y';
        }
        if (str[i] == 'q') {
            result[j++] = 'k';
        }
        if (str[i] == 'v') {
            result[j++] = 'w';
        }
        i++;
    }
    result[j] = '\0';
}

int main() {
    char str[MAX], result[MAX];
    printf("Enter the word in C Alien language: ");
    fgets(str, MAX, stdin);
    str[strlen(str)-1] = '\0';
    convert(str, result);
    printf("The word in English language: %s", result);
    return 0;
}