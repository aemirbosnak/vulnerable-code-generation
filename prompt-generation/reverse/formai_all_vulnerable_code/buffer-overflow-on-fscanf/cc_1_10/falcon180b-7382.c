//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare_words(const void *a, const void *b) {
    const WordCount *word_a = (const WordCount *)a;
    const WordCount *word_b = (const WordCount *)b;

    return strcmp(word_a->word, word_b->word);
}

int main() {
    char input[MAX_WORD_LENGTH];
    char *word;
    FILE *file;
    WordCount words[MAX_WORDS];
    int num_words = 0;
    int i;

    printf("Enter the name of the text file: ");
    scanf("%s", input);

    file = fopen(input, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(file, "%s", input)!= EOF) {
        word = strtok(input, ",.!?;:");
        while (word!= NULL) {
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                strcpy(words[num_words].word, word);
                words[num_words].count = 1;
                num_words++;
                if (num_words >= MAX_WORDS) {
                    printf("Maximum number of words reached.\n");
                    break;
                }
            }
            word = strtok(NULL, ",.!?;:");
        }
    }

    fclose(file);

    qsort(words, num_words, sizeof(WordCount), compare_words);

    printf("Word count:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}