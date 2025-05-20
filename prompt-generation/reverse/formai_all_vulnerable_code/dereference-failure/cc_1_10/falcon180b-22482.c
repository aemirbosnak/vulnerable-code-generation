//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000
#define MAX_WORD_SIZE 50
#define MAX_LINE_SIZE 80

void search(char* text, char* pattern, int* count) {
    int i, j, k, len;
    int found = 0;
    char* temp = malloc(MAX_SIZE);
    strcpy(temp, text);
    temp[strlen(temp) - 1] = '\0';
    len = strlen(temp);
    for (i = 0; i < len; i++) {
        if (isalpha(temp[i])) {
            temp[i] = tolower(temp[i]);
        }
    }
    for (i = 0; i < len; i++) {
        if (isalpha(temp[i])) {
            for (j = i; j < len; j++) {
                if (!isalpha(temp[j])) {
                    temp[j] = '\0';
                    break;
                }
            }
            k = 0;
            while (temp[i] == pattern[k]) {
                i++;
                k++;
            }
            if (k == strlen(pattern)) {
                found = 1;
                (*count)++;
            }
        }
    }
    if (!found) {
        printf("Pattern not found in text.\n");
    }
}

int main() {
    char text[MAX_SIZE];
    char pattern[MAX_WORD_SIZE];
    int count = 0;
    printf("Enter a string: ");
    fgets(text, MAX_SIZE, stdin);
    printf("Enter a pattern: ");
    fgets(pattern, MAX_WORD_SIZE, stdin);
    search(text, pattern, &count);
    return 0;
}