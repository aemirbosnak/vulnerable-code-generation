//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LEN 20

struct word {
    char word[WORD_LEN];
    int count;
};

int compare_words(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void read_words(char *filename, struct word *words, int *num_words) {
    FILE *file;
    char line[1000];
    char *word;
    int i = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (i >= MAX_WORDS) {
                printf("Too many words in file\n");
                exit(1);
            }
            strcpy(words[i].word, word);
            words[i].count = 1;
            i++;
            word = strtok(NULL, ",.?!;:");
        }
    }
    fclose(file);

    *num_words = i;
    qsort(words, *num_words, sizeof(struct word), compare_words);
}

void write_words(struct word *words, int num_words, char *filename) {
    FILE *file;
    int i;

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    for (i = 0; i < num_words; i++) {
        fprintf(file, "%s %d\n", words[i].word, words[i].count);
    }

    fclose(file);
}

int main() {
    char input_filename[100], output_filename[100];
    struct word words[MAX_WORDS];
    int num_words;

    printf("Enter input filename: ");
    scanf("%s", input_filename);
    printf("Enter output filename: ");
    scanf("%s", output_filename);

    read_words(input_filename, words, &num_words);

    printf("Enter alien language to translate to:\n");
    scanf("%s", &words[0].word);

    for (int i = 1; i < num_words; i++) {
        words[i].word[0] = toupper(words[i].word[0]);
    }

    write_words(words, num_words, output_filename);

    printf("Translation complete!\n");

    return 0;
}