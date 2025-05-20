//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

void read_file(char *filename, struct WordFrequency *words, int *num_words) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[1000];
    while (fgets(line, sizeof(line), file)!= NULL) {
        int len = strlen(line);
        for (int i = 0; i < len; i++) {
            if (isalpha(line[i])) {
                char word[MAX_WORD_LENGTH];
                int j = 0;
                while (isalpha(line[i])) {
                    word[j++] = tolower(line[i++]);
                }
                word[j] = '\0';

                for (int k = 0; k < *num_words; k++) {
                    if (strcmp(words[k].word, word) == 0) {
                        words[k].frequency++;
                        break;
                    }
                }
            }
        }
    }

    fclose(file);
}

void sort_words(struct WordFrequency *words, int num_words) {
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (words[j].frequency > words[i].frequency) {
                struct WordFrequency temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_word_frequencies(struct WordFrequency *words, int num_words) {
    printf("Word\tFrequency\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    struct WordFrequency words[MAX_WORDS];
    int num_words = 0;

    read_file(filename, words, &num_words);
    sort_words(words, num_words);
    print_word_frequencies(words, num_words);

    return 0;
}