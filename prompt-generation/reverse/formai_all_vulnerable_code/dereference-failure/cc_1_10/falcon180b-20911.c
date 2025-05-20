//Falcon-180B DATASET v1.0 Category: File handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_LINE_LENGTH 1000

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    FILE *fp;
} File;

typedef struct {
    char word[MAX_LINE_LENGTH];
    int count;
} WordCount;

int compare_strings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void read_file(File *file) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file->fp)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            WordCount *word_count = malloc(sizeof(WordCount));
            strcpy(word_count->word, word);
            word_count->count = 1;
            hsearch(word_count, compare_strings);
            word = strtok(NULL, ",.?!;:");
        }
    }
}

void print_word_counts(int count, WordCount *word_count) {
    printf("%s: %d\n", word_count->word, word_count->count);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage:./program <file_name>\n");
        return 1;
    }

    File file;
    strcpy(file.file_name, argv[1]);
    file.fp = fopen(file.file_name, "r");

    if (file.fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    read_file(&file);

    int num_words = 0;
    WordCount *word_counts = NULL;
    while ((word_counts = hsearch(word_counts, compare_strings))!= NULL) {
        num_words++;
    }

    printf("Total number of words: %d\n", num_words);

    int i = 0;
    for (i = 0; i < num_words; i++) {
        print_word_counts(i+1, word_counts);
    }

    fclose(file.fp);

    return 0;
}