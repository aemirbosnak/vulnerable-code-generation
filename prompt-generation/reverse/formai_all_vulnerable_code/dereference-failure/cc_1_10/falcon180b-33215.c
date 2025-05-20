//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *input_file;
    char line[MAX_WORD_LENGTH];
    char *word;
    WordCount *word_counts = (WordCount *)malloc(MAX_WORDS * sizeof(WordCount));
    int num_words = 0;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, input_file)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            num_words++;
            for (int i = 0; i < num_words; i++) {
                if (strcmp(word_counts[i].word, word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (num_words == MAX_WORDS) {
                printf("Error: Maximum number of words reached.\n");
                exit(1);
            }
            WordCount new_word_count;
            strcpy(new_word_count.word, word);
            new_word_count.count = 1;
            word_counts[num_words] = new_word_count;
            num_words++;
        }
        word = strtok(NULL, ",.?!;:");
    }

    fclose(input_file);

    printf("Word Counts:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    free(word_counts);
    return 0;
}