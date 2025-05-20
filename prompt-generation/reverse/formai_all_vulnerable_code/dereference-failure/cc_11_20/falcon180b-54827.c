//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define MAX_WORD_COUNT 1000

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    struct word_count *word_counts = malloc(MAX_WORD_COUNT * sizeof(struct word_count));
    memset(word_counts, 0, MAX_WORD_COUNT * sizeof(struct word_count));

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            int i;
            for (i = 0; i < MAX_WORD_COUNT; i++) {
                if (strcmp(word_counts[i].word, word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == MAX_WORD_COUNT) {
                if (word_counts[0].count == 0) {
                    strcpy(word_counts[0].word, word);
                } else {
                    strcpy(word_counts[--i].word, word);
                }
                word_counts[i].count++;
            }
            word = strtok(NULL, " ");
        }
    }

    fclose(fp);

    printf("Word count:\n");
    for (int i = 0; i < MAX_WORD_COUNT; i++) {
        if (word_counts[i].count > 0) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }

    return 0;
}