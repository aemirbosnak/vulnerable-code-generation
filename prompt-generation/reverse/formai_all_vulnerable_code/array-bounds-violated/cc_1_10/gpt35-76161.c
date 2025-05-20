//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORDS 10000
#define MAX_LEN 100

typedef struct {
    char *word;
    int frequency;
} word_freq;

word_freq words[MAX_WORDS];

int cmp(const void *a, const void *b) {
    return ((word_freq *)b)->frequency - ((word_freq *)a)->frequency;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *filename, line[MAX_LEN];
    int i, j, len, count = 0;

    if(argc < 2) {
        printf("Error: Please specify a file name.\n");
        exit(1);
    }
    filename = argv[1];

    file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error: Unable to open file %s.\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LEN, file) != NULL) {
        len = strlen(line);
        if(line[len-1] == '\n') line[len-1] = '\0';

        char *word = strtok(line, " \t");
        while (word != NULL) {
            for(i = 0; word[i]; i++) {
                word[i] = tolower(word[i]);
            }

            for(i = 0; i < count; i++) {
                if(strcmp(words[i].word, word) == 0) {
                    words[i].frequency++;
                    break;
                }
            }

            if(i == count) {
                words[i].word = malloc(strlen(word)+1);
                strcpy(words[i].word, word);
                words[i].frequency = 1;
                count++;
            }

            word = strtok(NULL, " \t");
        }
    }

    qsort(words, count, sizeof(word_freq), cmp);

    printf("Word count: %d\n", count);
    printf("==================\n");
    for(i = 0; i < count; i++) {
        printf("%s - %d\n", words[i].word, words[i].frequency);
        free(words[i].word);
    }

    fclose(file);

    return 0;
}