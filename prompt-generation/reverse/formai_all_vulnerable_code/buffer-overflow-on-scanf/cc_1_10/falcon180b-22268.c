//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 100

typedef struct {
    char *word;
    int count;
} WordCount;

void read_file(char *filename, WordCount *word_counts, int num_word_counts) {
    FILE *file;
    char line[MAX_WORD_SIZE];
    char *word;
    int i;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    i = 0;
    while (fgets(line, MAX_WORD_SIZE, file)!= NULL) {
        word = strtok(line, ",.!?;:");
        while (word!= NULL) {
            if (i >= num_word_counts) {
                printf("Error: too many unique words in file\n");
                exit(1);
            }
            word_counts[i].word = strdup(word);
            word_counts[i].count = 1;
            i++;
            word = strtok(NULL, ",.!?;:");
        }
    }

    fclose(file);
}

void print_word_counts(WordCount *word_counts, int num_word_counts) {
    int i;

    for (i = 0; i < num_word_counts; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    char filename[MAX_WORD_SIZE];
    WordCount word_counts[100];
    int num_word_counts;

    printf("Enter filename: ");
    scanf("%s", filename);

    read_file(filename, word_counts, 100);
    print_word_counts(word_counts, num_word_counts);

    return 0;
}