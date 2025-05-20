//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void read_file(FILE* file, WordFrequency* frequencies) {
    char word[MAX_WORD_LENGTH];
    int count = 0;
    while (fscanf(file, "%s", word) == 1) {
        if (strlen(word) > 0) {
            int i;
            for (i = 0; i < strlen(word); i++) {
                if (!isalpha(word[i])) {
                    word[i] = '\0';
                }
            }
            if (strlen(word) > 0) {
                int j;
                for (j = 0; j < MAX_WORDS; j++) {
                    if (strcmp(word, frequencies[j].word) == 0) {
                        frequencies[j].count++;
                        break;
                    }
                }
                if (j == MAX_WORDS) {
                    strcpy(frequencies[count].word, word);
                    frequencies[count].count = 1;
                    count++;
                }
            }
        }
    }
}

void print_frequencies(WordFrequency* frequencies, int count) {
    printf("Word\tCount\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\n", frequencies[i].word, frequencies[i].count);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    WordFrequency frequencies[MAX_WORDS];
    memset(frequencies, 0, sizeof(frequencies));

    read_file(file, frequencies);

    fclose(file);

    int count = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (frequencies[i].count > 0) {
            count++;
        }
    }

    print_frequencies(frequencies, count);

    return 0;
}