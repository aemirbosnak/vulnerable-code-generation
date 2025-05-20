//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 32

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void process_line(char* line, WordCount* word_counts) {
    char* word = strtok(line, " ");
    while (word!= NULL) {
        int len = strlen(word);
        if (len > MAX_WORD_LENGTH) {
            len = MAX_WORD_LENGTH;
        }
        strncpy(word_counts->word, word, len);
        word_counts->count++;
        word = strtok(NULL, " ");
    }
}

void print_word_counts(WordCount* word_counts, int num_words) {
    printf("Word Counts:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    char filename[MAX_LINE_LENGTH];
    printf("Enter the name of the log file: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        return 1;
    }

    WordCount word_counts[1000]; // Assume at most 1000 unique words
    int num_words = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        process_line(line, word_counts);
        num_words++;
    }

    fclose(file);

    printf("\nTotal number of words: %d\n", num_words);
    print_word_counts(word_counts, num_words);

    return 0;
}