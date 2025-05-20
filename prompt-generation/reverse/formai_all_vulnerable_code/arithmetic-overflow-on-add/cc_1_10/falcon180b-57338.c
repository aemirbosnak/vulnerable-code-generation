//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_file(FILE *file, WordFrequency *words) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[words[i].frequency] = tolower(ch);
            words[i].frequency++;
        } else if (isspace(ch)) {
            words[i].word[words[i].frequency] = '\0';
            i++;
        }
    }
}

void count_frequency(WordFrequency *words, int num_words) {
    int i, j;
    for (i = 0; i < num_words - 1; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].frequency += words[j].frequency;
                words[j].frequency = 0;
            }
        }
    }
}

void print_frequencies(WordFrequency *words, int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (words[i].frequency > 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    WordFrequency words[MAX_WORDS];
    int num_words = 0;

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    read_file(file, words);
    fclose(file);

    count_frequency(words, num_words);
    print_frequencies(words, num_words);

    return 0;
}