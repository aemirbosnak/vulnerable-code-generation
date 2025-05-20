//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

typedef struct {
    char filename[MAX_WORD_LENGTH];
    FILE *file;
    int word_count;
} FileInfo;

int compare_words(const void *a, const void *b) {
    WordFrequency *word_a = (WordFrequency *) a;
    WordFrequency *word_b = (WordFrequency *) b;

    if (word_a->frequency > word_b->frequency) {
        return -1;
    } else if (word_a->frequency < word_b->frequency) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char filename[MAX_WORD_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int word_count = 0;
    WordFrequency words[MAX_WORD_LENGTH];

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        word_count++;
        int i;
        for (i = 0; i < word_count; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].frequency++;
                break;
            }
        }
        if (i == word_count) {
            strcpy(words[word_count - 1].word, word);
            words[word_count - 1].frequency = 1;
            word_count++;
        }
    }

    qsort(words, word_count, sizeof(WordFrequency), compare_words);

    printf("Word\tFrequency\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s\t%d\n", words[i].word, words[i].frequency);
    }

    fclose(file);
    return 0;
}