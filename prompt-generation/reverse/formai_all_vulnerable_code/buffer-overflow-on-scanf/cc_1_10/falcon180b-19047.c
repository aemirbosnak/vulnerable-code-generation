//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64

typedef struct {
    char *word;
    int count;
} WordCount;

int main(int argc, char **argv) {
    char filename[MAX_LINE_SIZE];
    char line[MAX_LINE_SIZE];
    char *word;
    WordCount *word_counts = NULL;
    int num_word_counts = 0;
    int i, j;

    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *token = strtok(line, ",.?!;:");

        while (token!= NULL) {
            for (i = 0; i < num_word_counts; i++) {
                if (strcmp(token, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }

            if (i == num_word_counts) {
                word_counts = realloc(word_counts, sizeof(WordCount) * (num_word_counts + 1));
                word_counts[num_word_counts].word = strdup(token);
                word_counts[num_word_counts].count = 1;
                num_word_counts++;
            }

            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);

    printf("Word Counts:\n");
    for (i = 0; i < num_word_counts; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    for (i = 0; i < num_word_counts; i++) {
        free(word_counts[i].word);
    }
    free(word_counts);

    return 0;
}