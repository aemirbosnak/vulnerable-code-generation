//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(FILE *file, struct word_count words[]) {
    char line[MAX_WORD_LENGTH];
    char *token;
    int i = 0;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        token = strtok(line, ",.!?;:");
        while (token!= NULL) {
            strcpy(words[i].word, token);
            words[i].count++;
            i++;
            if (i >= MAX_WORDS) {
                break;
            }
            token = strtok(NULL, ",.!?;:");
        }
    }
}

void print_word_counts(struct word_count words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    struct word_count words[MAX_WORDS];

    printf("Enter a filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    read_file(file, words);

    print_word_counts(words, MAX_WORDS);

    fclose(file);
    return 0;
}