//Falcon-180B DATASET v1.0 Category: Data mining ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

void read_file(char* filename, struct WordFrequency words[MAX_WORDS]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    int word_length = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (word_length >= MAX_WORD_LENGTH) {
            printf("Warning: word '%s' is too long and will be truncated.\n", word);
        }
        strcpy(words[word_length].word, word);
        words[word_length].frequency = 1;
        word_length++;
    }

    fclose(file);
}

void count_frequencies(struct WordFrequency words[MAX_WORDS]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strlen(words[i].word) > 0) {
            int j;
            for (j = i + 1; j < MAX_WORDS; j++) {
                if (strcmp(words[i].word, words[j].word) == 0) {
                    words[i].frequency += words[j].frequency;
                    memset(words[j].word, '\0', strlen(words[j].word));
                    words[j].frequency = 0;
                }
            }
        }
    }
}

void print_frequencies(struct WordFrequency words[MAX_WORDS]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strlen(words[i].word) > 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct WordFrequency words[MAX_WORDS];

    read_file(argv[1], words);
    count_frequencies(words);
    print_frequencies(words);

    return 0;
}