//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char *word;
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    WordCount *word_counts = NULL;
    int num_words = 0;
    int i, j;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int word_start = 0;
        while (1) {
            j = word_start;
            while (j < strlen(line) &&!isspace(line[j])) {
                j++;
            }
            if (j == word_start) {
                break;
            }
            strncpy(word, &line[word_start], j - word_start);
            word[j - word_start] = '\0';
            for (i = 0; i < num_words; i++) {
                if (strcmp(word_counts[i].word, word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                word_counts = realloc(word_counts, sizeof(WordCount) * (num_words + 1));
                if (word_counts == NULL) {
                    printf("Error: Could not allocate memory.\n");
                    return 1;
                }
                word_counts[num_words].word = strdup(word);
                word_counts[num_words].count = 1;
                num_words++;
            }
            word_start = j + 1;
        }
    }

    fclose(fp);

    printf("Word\tCount\n");
    for (i = 0; i < num_words; i++) {
        printf("%s\t%d\n", word_counts[i].word, word_counts[i].count);
    }

    for (i = 0; i < num_words; i++) {
        free(word_counts[i].word);
    }
    free(word_counts);

    return 0;
}