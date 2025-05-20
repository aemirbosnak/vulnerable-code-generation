//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct word {
    char *word;
    int count;
} Word;

int is_word(char *word) {
    int i = 0;
    while (word[i]!= '\0') {
        if (!isalpha(word[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int compare_words(const void *a, const void *b) {
    Word *word1 = (Word *)a;
    Word *word2 = (Word *)b;
    return strcmp(word1->word, word2->word);
}

void load_words(Word *words, int *num_words, FILE *file) {
    char line[MAX_WORD_LENGTH];
    char *word = NULL;
    int i = 0;
    *num_words = 0;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (is_word(word)) {
                Word *new_word = realloc(words, sizeof(Word) * (*num_words + 1));
                if (new_word == NULL) {
                    printf("Error: Out of memory\n");
                    exit(1);
                }
                words = new_word;
                words[*num_words].word = strdup(word);
                words[*num_words].count = 0;
                (*num_words)++;
            }
            word = strtok(NULL, ",.?!;:");
        }
    }

    qsort(words, *num_words, sizeof(Word), compare_words);
}

void save_words(Word *words, int num_words, FILE *file) {
    for (int i = 0; i < num_words; i++) {
        fprintf(file, "%s %d\n", words[i].word, words[i].count);
    }
}

void update_word_count(Word *words, int num_words, char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return;
        }
    }
}

int main() {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];
    Word words[MAX_WORDS];
    int num_words = 0;

    printf("Enter input filename: ");
    scanf("%s", input_filename);
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file\n");
        exit(1);
    }

    printf("Enter output filename: ");
    scanf("%s", output_filename);
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file\n");
        exit(1);
    }

    load_words(words, &num_words, input_file);

    while (fscanf(input_file, "%s", words[num_words].word)!= EOF) {
        update_word_count(words, num_words, words[num_words].word);
        num_words++;
    }

    qsort(words, num_words, sizeof(Word), compare_words);

    for (int i = 0; i < num_words; i++) {
        fprintf(output_file, "%s %d\n", words[i].word, words[i].count);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}