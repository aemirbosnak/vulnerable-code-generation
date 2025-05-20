//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: imaginative
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LEN 100
#define MAX_FILE_NAME_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_file(FILE *fp, char *filename) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            filename[i++] = tolower(ch);
        } else {
            filename[i] = '\0';
            break;
        }
    }
}

int compare_words(const void *a, const void *b) {
    const WordCount *wc1 = (const WordCount *)a;
    const WordCount *wc2 = (const WordCount *)b;
    return strcmp(wc1->word, wc2->word);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    char filename[MAX_FILE_NAME_LEN];
    read_file(fp, filename);

    int total_words = 0;
    WordCount *word_counts = NULL;
    int num_words = 0;

    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word)!= EOF) {
        total_words++;
        if (num_words >= MAX_WORD_LEN) {
            printf("Error: too many unique words\n");
            exit(1);
        }
        WordCount wc;
        strcpy(wc.word, word);
        wc.count = 1;
        word_counts = realloc(word_counts, sizeof(WordCount) * ++num_words);
        word_counts[num_words - 1] = wc;
    }

    qsort(word_counts, num_words, sizeof(WordCount), compare_words);

    printf("Total words: %d\n", total_words);
    printf("Unique words: %d\n", num_words);
    printf("Word counts:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    free(word_counts);
    fclose(fp);

    return 0;
}