//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

struct word {
    char word[MAX_WORD_LEN];
    int count;
};

void read_file(FILE *fp, struct word *words) {
    char ch;
    int i, j;
    for (i = 0; i < MAX_WORDS; i++) {
        words[i].count = 0;
    }
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            j = 0;
            while (isalpha(ch)) {
                words[i].word[j++] = tolower(ch);
                ch = fgetc(fp);
            }
            words[i].word[j] = '\0';
            i++;
        }
    }
}

void search_words(FILE *fp, struct word *words) {
    char ch;
    int i, j, k;
    char search_word[MAX_WORD_LEN];
    printf("Enter a word to search: ");
    scanf("%s", search_word);
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, search_word) == 0) {
            printf("Found %s %d times\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *fp;
    char filename[50];
    printf("Enter the name of the file to search: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    struct word words[MAX_WORDS];
    read_file(fp, words);
    printf("Enter the word to search for:\n");
    search_words(fp, words);
    fclose(fp);
    return 0;
}