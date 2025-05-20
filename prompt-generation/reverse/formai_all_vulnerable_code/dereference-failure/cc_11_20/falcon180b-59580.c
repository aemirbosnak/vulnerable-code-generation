//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 32
#define MAX_WORD_COUNT 1000

typedef struct {
    char *word;
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    WordCount *word_counts = malloc(MAX_WORD_COUNT * sizeof(WordCount));
    int num_words = 0;
    int i;
    int j;
    int k;
    int found;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        i = 0;
        while (i < strlen(line)) {
            j = 0;
            while (j < MAX_WORD_LENGTH && isalnum(line[i])) {
                word[j] = tolower(line[i]);
                i++;
                j++;
            }
            word[j] = '\0';

            found = 0;
            for (k = 0; k < num_words; k++) {
                if (strcmp(word, word_counts[k].word) == 0) {
                    word_counts[k].count++;
                    found = 1;
                    break;
                }
            }

            if (found == 0) {
                if (num_words >= MAX_WORD_COUNT) {
                    printf("Error: too many unique words in file\n");
                    exit(1);
                }
                strcpy(word_counts[num_words].word, word);
                word_counts[num_words].count = 1;
                num_words++;
            }
        }
    }

    fclose(file);

    printf("Word counts:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    free(word_counts);

    return 0;
}