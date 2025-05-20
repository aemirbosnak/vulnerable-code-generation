//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

void to_lowercase(char* s) {
    for (int i = 0; s[i]; i++) {
        s[i] = tolower(s[i]);
    }
}

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH], c;
    int word_count = 0;
    int char_count = 0;
    int freq_table[26] = {0};
    while (1) {
        c = fgetc(fp);

        if (c == EOF) {
            break;
        }

        char_count++;

        if (isalpha(c)) {
            word[word_count++] = c;
        } else if (word_count > 0) {
            word[word_count] = '\0';
            to_lowercase(word);
            freq_table[word[0] - 'a']++;

            word_count = 0;
        }
    }

    fclose(fp);

    printf("\nWord frequency count:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", i + 'a', freq_table[i]);
    }

    printf("\nTotal number of characters: %d\n", char_count);

    return 0;
}