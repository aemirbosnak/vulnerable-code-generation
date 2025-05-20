//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 64
#define MAX_NUM_WORDS 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    char line[MAX_WORD_LENGTH];
    char *word;
    WordCount word_counts[MAX_NUM_WORDS];
    int num_words = 0;
    int i;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        word = strtok(line, ",.?!;:");

        while (word!= NULL) {
            for (i = 0; i < num_words; i++) {
                if (strcmp(word_counts[i].word, word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }

            if (i == num_words) {
                if (num_words == MAX_NUM_WORDS) {
                    printf("Error: too many words.\n");
                    return 1;
                }

                strcpy(word_counts[num_words].word, word);
                word_counts[num_words].count = 1;
                num_words++;
            }

            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);

    printf("Word Counts:\n");

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}