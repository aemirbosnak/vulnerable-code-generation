//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

struct word_data {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

void read_file(FILE *file, struct word_data *words, int *num_words) {
    char line[MAX_WORD_LENGTH];
    char *word;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        word = strtok(line, ",.!?;:");
        while (word!= NULL) {
            if (strlen(word) <= MAX_WORD_LENGTH) {
                int i;
                for (i = 0; i < *num_words; i++) {
                    if (strcmp(words[i].word, word) == 0) {
                        words[i].frequency++;
                        break;
                    }
                }
                if (i == *num_words) {
                    strcpy(words[*num_words].word, word);
                    words[*num_words].frequency = 1;
                    (*num_words)++;
                }
            }
            word = strtok(NULL, ",.!?;:");
        }
    }
}

void print_word_data(struct word_data *words, int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    FILE *file;
    char filename[100];
    struct word_data words[MAX_WORDS];
    int num_words = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    read_file(file, words, &num_words);

    fclose(file);

    printf("Word frequency:\n");
    print_word_data(words, num_words);

    return 0;
}