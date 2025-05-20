//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 5005
#define MAX_WORD_LEN 25
#define UNKNOWN_WORD "UNK"

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordFreq;

int compare_words(const void *a, const void *b)
{
    return ((WordFreq*)b)->count - ((WordFreq*)a)->count;
}

int main(void)
{
    char input_words[MAX_WORDS][MAX_WORD_LEN];
    int index = 0;
    char input_word[MAX_WORD_LEN];
    while (scanf("%s", input_word) == 1) {
        strcpy(input_words[index++], input_word);
    }

    WordFreq words[MAX_WORDS];
    int num_words = 0;
    for (int i = 0; i < index; i++) {
        int found = 0;
        for (int j = 0; j < num_words; j++) {
            if (strcmp(words[j].word, input_words[i]) == 0) {
                words[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[num_words].word, input_words[i]);
            words[num_words].count = 1;
            num_words++;
        }
    }

    qsort(words, num_words, sizeof(WordFreq), compare_words);

    char output_words[MAX_WORDS * MAX_WORD_LEN];
    int output_index = 0;
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i].word, UNKNOWN_WORD) == 0) {
            continue;
        }
        sprintf(output_words + output_index, "%s %d\n", words[i].word, words[i].count);
        output_index += strlen(output_words + output_index);
    }
    output_words[output_index] = '\0';

    printf("%s", output_words);
    return 0;
}