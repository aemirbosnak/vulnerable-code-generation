//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int frequency;
} WordFrequency;

void read_file(FILE *file, WordFrequency *word_frequencies) {
    char word[MAX_WORD_LEN];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
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
            if (strcmp(word_frequencies[k].word, word) == 0) {
                word_frequencies[k].frequency++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(word_frequencies[i].word, word);
            word_frequencies[i].frequency = 1;
            i++;
        }
    }
}

void print_frequencies(WordFrequency *word_frequencies, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].frequency);
    }
}

int main() {
    FILE *file;
    char filename[100];
    WordFrequency word_frequencies[MAX_WORDS];

    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    read_file(file, word_frequencies);

    fclose(file);

    int num_words = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (word_frequencies[i].frequency!= 0) {
            num_words++;
        }
    }

    printf("\nWord frequencies:\n");
    print_frequencies(word_frequencies, num_words);

    return 0;
}