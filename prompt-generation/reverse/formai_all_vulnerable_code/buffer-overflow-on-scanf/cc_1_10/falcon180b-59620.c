//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH+1];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    WordCount *wc1 = (WordCount*)a;
    WordCount *wc2 = (WordCount*)b;
    return strcmp(wc1->word, wc2->word);
}

void print_word_counts(WordCount *word_counts, int num_words) {
    qsort(word_counts, num_words, sizeof(WordCount), compare);
    for (int i = 0; i < num_words; i++) {
        printf("%-50s %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    char text[1000000];
    char word[MAX_WORD_LENGTH+1];
    FILE *fp;
    int num_words = 0;
    WordCount word_counts[MAX_WORDS];

    printf("Enter the name of the text file: ");
    scanf("%s", text);

    fp = fopen(text, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while (fscanf(fp, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: too many words.\n");
            fclose(fp);
            return 1;
        }
        word[strcspn(word, ".,?!;:\"'")] = '\0'; // remove punctuation
        strcpy(&word_counts[num_words].word[0], word);
        num_words++;
    }

    fclose(fp);

    for (int i = 0; i < num_words; i++) {
        word_counts[i].count = 1;
    }

    for (int i = 0; i < num_words-1; i++) {
        for (int j = i+1; j < num_words; j++) {
            if (strcmp(&word_counts[i].word[0], &word_counts[j].word[0]) == 0) {
                word_counts[i].count++;
                word_counts[j].count = 0;
            }
        }
    }

    print_word_counts(word_counts, num_words);

    return 0;
}