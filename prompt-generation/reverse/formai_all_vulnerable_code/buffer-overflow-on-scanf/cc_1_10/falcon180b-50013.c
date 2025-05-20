//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare(const void* a, const void* b) {
    WordCount* wc1 = (WordCount*)a;
    WordCount* wc2 = (WordCount*)b;
    return strcmp(wc1->word, wc2->word);
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    int word_length = 0;
    int num_words = 0;
    WordCount words[MAX_WORDS];

    while (fscanf(file, "%s", word)!= EOF) {
        word_length = strlen(word);
        if (word_length > MAX_WORD_LENGTH) {
            printf("Word '%s' is too long.\n", word);
            continue;
        }
        strcpy(words[num_words].word, word);
        words[num_words].count = 1;
        num_words++;
    }

    qsort(words, num_words, sizeof(WordCount), compare);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    fclose(file);
    return 0;
}