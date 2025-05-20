//Falcon-180B DATASET v1.0 Category: Text processing ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_file(FILE *fp, char *filename, WordCount words[]) {
    char line[MAX_WORD_LEN];
    while (fgets(line, MAX_WORD_LEN, fp)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            int len = strlen(word);
            if (len > MAX_WORD_LEN - 1) {
                len = MAX_WORD_LEN - 1;
            }
            strncpy(words[hash(word)].word, word, len);
            words[hash(word)].count++;
            word = strtok(NULL, ",.?!;:");
        }
    }
}

int hash(char *word) {
    int hash = 0;
    while (*word) {
        hash = (hash * 31) ^ *word++;
    }
    return hash % MAX_WORDS;
}

void print_counts(WordCount words[], int num_words) {
    printf("Word\tCount\n");
    for (int i = 0; i < num_words; i++) {
        if (words[i].count > 0) {
            printf("%s\t%d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *fp;
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    WordCount words[MAX_WORDS];
    read_file(fp, filename, words);

    int num_words = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            num_words++;
        }
    }

    print_counts(words, num_words);

    fclose(fp);
    return 0;
}