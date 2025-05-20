//Falcon-180B DATASET v1.0 Category: Text processing ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(FILE* fp, struct word_count words[MAX_WORDS]) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isspace(ch)) {
            words[i].word[words[i].count] = '\0';
            words[i].count++;
            i++;
            if (i >= MAX_WORDS) {
                printf("Error: Maximum number of words exceeded.\n");
                exit(1);
            }
        } else {
            words[i].word[words[i].count++] = tolower(ch);
        }
    }
    words[i].word[words[i].count] = '\0';
    words[i].count++;
}

void sort_words(struct word_count words[MAX_WORDS]) {
    int i, j;
    struct word_count temp;
    for (i = 0; i < MAX_WORDS - 1; i++) {
        for (j = i + 1; j < MAX_WORDS; j++) {
            if (strcmp(words[i].word, words[j].word) > 0) {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_word_counts(struct word_count words[MAX_WORDS]) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE* fp;
    struct word_count words[MAX_WORDS];
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    read_file(fp, words);
    fclose(fp);
    sort_words(words);
    print_word_counts(words);
    return 0;
}