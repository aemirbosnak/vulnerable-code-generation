//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordCount;

int compare_words(const void *a, const void *b) {
    WordCount *word_a = (WordCount *)a;
    WordCount *word_b = (WordCount *)b;
    if (word_a->count == word_b->count) {
        return 0;
    } else if (word_a->count > word_b->count) {
        return -1;
    } else {
        return 1;
    }
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    WordCount words[1000];
    int num_words = 0;
    int i;

    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int in_word = 0;
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                in_word = 1;
            } else {
                if (in_word) {
                    line[i] = '\0';
                    strcpy(word, &line[i - 1]);
                    words[num_words].word = strdup(word);
                    words[num_words].count = 1;
                    num_words++;
                    in_word = 0;
                }
            }
        }
        if (in_word) {
            line[strlen(line) - 1] = '\0';
            strcpy(word, &line[strlen(line) - 1]);
            words[num_words].word = strdup(word);
            words[num_words].count = 1;
            num_words++;
        }
    }

    fclose(file);

    qsort(words, num_words, sizeof(WordCount), compare_words);

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}