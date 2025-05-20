//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char *word;
    WordCount *word_counts = malloc(MAX_WORDS * sizeof(WordCount));
    int num_words = 0;
    int i;

    file = fopen("sample_text.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        word = strtok(line, ",.!?;:");
        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                exit(1);
            }
            word_counts[num_words].word[0] = tolower(word[0]);
            strncpy(word_counts[num_words].word + 1, word + 1, MAX_WORD_LENGTH - 2);
            word_counts[num_words].word[MAX_WORD_LENGTH - 1] = '\0';
            word_counts[num_words].count = 1;
            num_words++;
            word = strtok(NULL, ",.!?;:");
        }
    }

    fclose(file);

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    free(word_counts);

    return 0;
}