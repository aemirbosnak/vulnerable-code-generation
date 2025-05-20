//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 1024
#define MAX_WORDS 10000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compare_words(const void *a, const void *b) {
    WordCount *word1 = (WordCount *) a;
    WordCount *word2 = (WordCount *) b;

    return strcmp(word1->word, word2->word);
}

void read_file(FILE *file, WordCount *words, int *word_count) {
    char line[1024];
    char *word;
    int len;

    while (fgets(line, sizeof(line), file)!= NULL) {
        len = strlen(line);

        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        word = strtok(line, ",.?!;:\"'");

        while (word!= NULL) {
            len = strlen(word);

            if (len > 0 && len <= MAX_WORD_LEN) {
                strcpy(words[*word_count].word, word);
                words[*word_count].count = 1;
                (*word_count)++;
            }

            word = strtok(NULL, ",.?!;:\"'");
        }
    }
}

void count_words(WordCount *words, int word_count) {
    qsort(words, word_count, sizeof(WordCount), compare_words);

    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    WordCount words[MAX_WORDS];
    int word_count = 0;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    read_file(file, words, &word_count);

    if (word_count == 0) {
        printf("No words found in file.\n");
    } else {
        count_words(words, word_count);
    }

    fclose(file);

    return 0;
}