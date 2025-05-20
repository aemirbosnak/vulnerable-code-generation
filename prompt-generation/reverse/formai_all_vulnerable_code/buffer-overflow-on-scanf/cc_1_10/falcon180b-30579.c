//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compare_words(const void *a, const void *b) {
    const WordFrequency *w1 = a;
    const WordFrequency *w2 = b;
    return strcmp(w1->word, w2->word);
}

void process_word(char *word) {
    int length = strlen(word);
    if (length > MAX_WORD_LENGTH) {
        length = MAX_WORD_LENGTH;
    }
    for (int i = 0; i < length; i++) {
        word[i] = tolower(word[i]);
    }
    word[length] = '\0';
}

int main() {
    char input_file[100];
    char output_file[100];
    printf("Enter the name of the input file: ");
    scanf("%s", input_file);
    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    FILE *input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    WordFrequency *word_frequencies = malloc(MAX_WORD_COUNT * sizeof(WordFrequency));
    int word_count = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(input, "%s", word)!= EOF) {
        process_word(word);
        for (int i = 0; i < word_count; i++) {
            if (strcmp(word, word_frequencies[i].word) == 0) {
                word_frequencies[i].count++;
                break;
            }
        }
        if (word_count >= MAX_WORD_COUNT) {
            printf("Maximum number of words reached.\n");
            break;
        }
        strcpy(word_frequencies[word_count].word, word);
        word_frequencies[word_count].count = 1;
        word_count++;
    }

    qsort(word_frequencies, word_count, sizeof(WordFrequency), compare_words);

    for (int i = 0; i < word_count; i++) {
        fprintf(output, "%s: %d\n", word_frequencies[i].word, word_frequencies[i].count);
    }

    fclose(input);
    fclose(output);

    return 0;
}