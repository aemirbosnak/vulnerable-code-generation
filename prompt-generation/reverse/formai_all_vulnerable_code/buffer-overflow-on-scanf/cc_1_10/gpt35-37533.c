//FormAI DATASET v1.0 Category: Spell checking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORD_SIZE 50

bool isLetter(char c) {
    return isalpha(c) ? true : false;
}

char* toLowerCase(char *str) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
    return str;
}

bool isMatch(char *word, char *dictionary[]) {
    int i = 0;
    while (dictionary[i] != NULL) {
        if (strcmp(word, dictionary[i]) == 0) {
            return true;
        }
        i++;
    }
    return false;
}

void checkSpelling(char *input, char *dictionary[]) {
    char word[MAX_WORD_SIZE];
    int i = 0, j = 0;
    while(input[i]) {
        if (isLetter(input[i])) {
            word[j] = input[i];
            j++;
        } else if (j > 0) {
            word[j] = '\0';
            if (!isMatch(toLowerCase(word), dictionary)) {
                printf("Misspelled: %s\n", word);
            }
            j = 0;
        }
        i++;
    }
}

int main() {
    char *dictionary[] = {"apple", "orange", "banana", "mango", NULL};
    char input[200];
    printf("Enter a string: ");
    scanf("%[^\n]s", input);
    checkSpelling(input, dictionary);
    return 0;
}