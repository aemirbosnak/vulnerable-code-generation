//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words = 0;

void add_word(char *word) {
    if (num_words >= MAX_WORDS) {
        printf("Error: Too many words.\n");
        return;
    }
    strcpy(words[num_words], word);
    num_words++;
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            char word[MAX_WORD_LENGTH];
            int len = 0;
            while (isalpha(ch)) {
                if (len >= MAX_WORD_LENGTH) {
                    printf("Error: Word too long.\n");
                    fclose(fp);
                    return 1;
                }
                word[len++] = tolower(ch);
                ch = fgetc(fp);
            }
            word[len] = '\0';
            add_word(word);
        }
    }

    fclose(fp);

    printf("Enter search word: ");
    char search_word[MAX_WORD_LENGTH];
    scanf("%s", search_word);

    int matches = 0;
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i], search_word) == 0) {
            printf("Found %s\n", words[i]);
            matches++;
        }
    }

    if (matches == 0) {
        printf("No matches found.\n");
    }

    return 0;
}