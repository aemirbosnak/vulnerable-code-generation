//Falcon-180B DATASET v1.0 Category: Text processing ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordCount;

void read_file(FILE *fp, char *filename) {
    char ch;
    int in_word = 0;
    char word[MAX_WORD_LENGTH];
    int word_length = 0;

    while ((ch = fgetc(fp))!= EOF) {
        if (isspace(ch)) {
            if (in_word) {
                word[word_length] = '\0';
                printf("%s ", word);
                in_word = 0;
            }
        } else {
            if (!in_word) {
                in_word = 1;
            }
            if (word_length == MAX_WORD_LENGTH - 1) {
                printf("Error: Word too long\n");
                exit(1);
            }
            word[word_length++] = ch;
        }
    }

    if (in_word) {
        word[word_length] = '\0';
        printf("%s ", word);
    }
}

void count_words(char *filename) {
    FILE *fp;
    int num_words = 0;
    char word[MAX_WORD_LENGTH];
    int word_length = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    while (fscanf(fp, "%s", word)!= EOF) {
        num_words++;
    }

    printf("Number of words in file %s: %d\n", filename, num_words);

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    char *ext = strrchr(filename, '.');
    if (ext == NULL || strcmp(ext, ".txt")!= 0) {
        printf("Error: File must have.txt extension\n");
        exit(1);
    }

    read_file(stdin, filename);
    count_words(filename);

    return 0;
}