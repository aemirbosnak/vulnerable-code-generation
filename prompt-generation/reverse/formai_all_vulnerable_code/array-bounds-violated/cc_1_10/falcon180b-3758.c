//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define MAX_WORD_LEN 64

typedef struct {
    char *filename;
    int num_words;
    char **words;
} Metadata;

void add_word(char **words, int *num_words, char *word) {
    if (*num_words >= MAX_WORD_LEN) {
        fprintf(stderr, "Error: Too many words in file.\n");
        exit(1);
    }
    char *new_word = malloc(strlen(word) + 1);
    strcpy(new_word, word);
    (*words)[*num_words] = new_word;
    (*num_words)++;
}

void extract_metadata(char *filename, Metadata *metadata) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file.\n");
        exit(1);
    }
    char line[MAX_LINE_LEN];
    char *word = NULL;
    int num_words = 0;
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        char *p = line;
        while ((word = strtok_r(p, " \t\r\n", &p))!= NULL) {
            add_word(&metadata->words, &num_words, word);
        }
    }
    fclose(fp);
    metadata->num_words = num_words;
}

void print_metadata(Metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("Number of words: %d\n", metadata->num_words);
    for (int i = 0; i < metadata->num_words; i++) {
        printf("Word %d: %s\n", i, metadata->words[i]);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    char *filename = argv[1];
    Metadata metadata;
    metadata.filename = filename;
    extract_metadata(filename, &metadata);
    print_metadata(&metadata);
    for (int i = 0; i < metadata.num_words; i++) {
        free(metadata.words[i]);
    }
    free(metadata.words);
    return 0;
}