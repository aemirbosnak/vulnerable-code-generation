//Falcon-180B DATASET v1.0 Category: Database querying ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *fp, char *filename, WordCount words[]) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = tolower(ch);
            int j = 1;
            while ((ch = fgetc(fp))!= EOF && isalnum(ch)) {
                if (j < MAX_WORD_LENGTH - 1) {
                    words[i].word[j++] = tolower(ch);
                }
            }
            words[i].word[j] = '\0';
            words[i].count = 1;
            i++;
        }
    }
}

void write_file(FILE *fp, WordCount words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        fprintf(fp, "%s: %d\n", words[i].word, words[i].count);
    }
}

int compare_words(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *fp;
    char filename[100];
    printf("Enter the name of the input file: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    WordCount words[MAX_WORDS];
    int num_words = 0;
    read_file(fp, filename, words);
    fclose(fp);
    qsort(words, num_words, sizeof(WordCount), compare_words);
    printf("Enter the name of the output file: ");
    scanf("%s", filename);
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: could not create output file.\n");
        exit(1);
    }
    write_file(fp, words, num_words);
    fclose(fp);
    printf("Done.\n");
    return 0;
}