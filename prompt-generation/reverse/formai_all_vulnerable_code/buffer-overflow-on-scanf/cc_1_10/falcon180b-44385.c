//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, char *filename) {
    char line[MAX_WORD_LENGTH];
    fseek(file, 0, SEEK_SET);
    while (fscanf(file, "%s", line)!= EOF) {
        printf("%s", line);
    }
}

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    int i, j, n;
    char input[MAX_WORD_LENGTH];
    WordCount words[MAX_WORDS];
    int num_words = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    read_file(file, filename);

    printf("\nEnter words to count:\n");
    while (scanf("%s", input)!= EOF) {
        for (i = 0; i < num_words; i++) {
            if (strcmp(words[i].word, input) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == num_words) {
            strcpy(words[num_words].word, input);
            words[num_words].count = 1;
            num_words++;
        }
    }

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    fclose(file);
    return 0;
}