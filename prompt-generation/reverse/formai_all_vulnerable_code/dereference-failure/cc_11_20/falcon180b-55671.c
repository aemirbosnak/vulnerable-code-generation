//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define MAX_WORD_COUNT 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *word;
    WordCount *word_counts = (WordCount *)malloc(MAX_WORD_COUNT * sizeof(WordCount));
    int num_words = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", argv[1]);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (strlen(word) > 0 && strlen(word) <= MAX_WORD_LENGTH) {
                for (int i = 0; i < num_words; i++) {
                    if (strcmp(word, word_counts[i].word) == 0) {
                        word_counts[i].count++;
                        break;
                    }
                }
                if (num_words == MAX_WORD_COUNT) {
                    fprintf(stderr, "Error: too many unique words in file\n");
                    exit(1);
                }
                strcpy(word_counts[num_words].word, word);
                word_counts[num_words].count = 1;
                num_words++;
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);

    printf("Word counts:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    free(word_counts);
    return 0;
}