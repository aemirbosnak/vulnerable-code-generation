//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_frequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int compare_words(const void *a, const void *b) {
    struct word_frequency *word1 = (struct word_frequency *)a;
    struct word_frequency *word2 = (struct word_frequency *)b;

    return strcmp(word1->word, word2->word);
}

int main() {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];
    char line[1000];
    char word[MAX_WORD_LENGTH];
    int word_count = 0;
    int total_words = 0;
    struct word_frequency *word_frequency_table = NULL;

    printf("Enter the input file name: ");
    scanf("%s", input_filename);

    printf("Enter the output file name: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        exit(1);
    }

    while (fgets(line, sizeof(line), input_file)!= NULL) {
        total_words += count_words(line, word_frequency_table);
    }

    qsort(word_frequency_table, word_count, sizeof(struct word_frequency), compare_words);

    for (int i = 0; i < word_count; i++) {
        fprintf(output_file, "%s: %d\n", word_frequency_table[i].word, word_frequency_table[i].frequency);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}

int count_words(char *line, struct word_frequency *word_frequency_table) {
    char *token;
    int word_count = 0;

    token = strtok(line, ",.!?;:\"'");
    while (token!= NULL) {
        if (word_count >= MAX_WORDS) {
            break;
        }

        strcpy(word_frequency_table[word_count].word, token);
        word_frequency_table[word_count].frequency++;
        word_count++;

        token = strtok(NULL, ",.!?;:\"'");
    }

    return word_count;
}