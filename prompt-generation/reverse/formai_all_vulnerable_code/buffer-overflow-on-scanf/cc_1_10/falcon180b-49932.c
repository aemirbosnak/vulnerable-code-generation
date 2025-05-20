//Falcon-180B DATASET v1.0 Category: File handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_FILE_SIZE 1000000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare_words(const void *a, const void *b) {
    WordCount *word_a = (WordCount *)a;
    WordCount *word_b = (WordCount *)b;

    return strcmp(word_a->word, word_b->word);
}

int main() {
    FILE *input_file;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    char *word;
    WordCount words[MAX_FILE_SIZE];
    int num_words = 0;
    int i;

    printf("Enter the filename: ");
    scanf("%s", filename);

    input_file = fopen(filename, "r");

    if (input_file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        num_words = 0;

        word = strtok(line, ",.!?;:\"'()[]{}<>");

        while (word!= NULL) {
            if (num_words >= MAX_FILE_SIZE) {
                printf("Maximum number of words exceeded\n");
                exit(1);
            }

            strcpy(words[num_words].word, word);
            words[num_words].count = 1;

            num_words++;

            word = strtok(NULL, ",.!?;:\"'()[]{}<>");
        }
    }

    fclose(input_file);

    qsort(words, num_words, sizeof(WordCount), compare_words);

    printf("Word\tCount\n");

    for (i = 0; i < num_words; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}