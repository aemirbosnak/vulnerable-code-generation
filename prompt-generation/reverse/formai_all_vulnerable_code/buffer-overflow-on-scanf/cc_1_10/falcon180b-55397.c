//Falcon-180B DATASET v1.0 Category: File handling ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 256
#define MAX_WORDS 1024

typedef struct {
    char **words;
    int num_words;
} WordList;

void read_words(FILE *fp, WordList *word_list) {
    char line[MAX_LINE_LENGTH];
    char *word = malloc(MAX_WORD_LENGTH);
    int num_words = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *token = strtok(line, " \n\t\r\f\v");
        while (token!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Error: Too many words in line.\n");
                exit(1);
            }
            word_list->words[num_words] = strdup(token);
            num_words++;
            token = strtok(NULL, " \n\t\r\f\v");
        }
    }
    word_list->num_words = num_words;
}

void write_words(FILE *fp, WordList *word_list) {
    for (int i = 0; i < word_list->num_words; i++) {
        fprintf(fp, "%s ", word_list->words[i]);
    }
    fprintf(fp, "\n");
}

void reverse_words(WordList *word_list) {
    for (int i = 0; i < word_list->num_words / 2; i++) {
        char *temp = word_list->words[i];
        word_list->words[i] = word_list->words[word_list->num_words - i - 1];
        word_list->words[word_list->num_words - i - 1] = temp;
    }
}

int main() {
    char filename[MAX_LINE_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    WordList word_list;
    word_list.num_words = 0;
    word_list.words = malloc(MAX_WORDS * sizeof(char *));
    read_words(fp, &word_list);
    printf("Original text:\n");
    write_words(stdout, &word_list);
    reverse_words(&word_list);
    printf("\nReversed text:\n");
    write_words(stdout, &word_list);
    fclose(fp);
    return 0;
}