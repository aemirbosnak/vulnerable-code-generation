//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_file(FILE* file, WordFrequency words[MAX_WORDS]) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i == MAX_WORDS) {
            printf("Error: Maximum number of words reached.\n");
            exit(1);
        }

        for (int j = 0; j < strlen(word); j++) {
            if (!isalpha(word[j])) {
                word[j] = '\0';
            }
        }

        int found = 0;
        for (int k = 0; k < i; k++) {
            if (strcmp(word, words[k].word) == 0) {
                words[k].frequency++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(words[i].word, word);
            words[i].frequency = 1;
            i++;
        }
    }
}

void print_frequencies(WordFrequency words[MAX_WORDS], int num_words) {
    printf("Word\tFrequency\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    read_file(file, words);

    int num_words = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].frequency > 0) {
            num_words++;
        }
    }

    print_frequencies(words, num_words);

    fclose(file);
    return 0;
}