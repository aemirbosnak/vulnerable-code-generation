//Falcon-180B DATASET v1.0 Category: Data mining ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_file(FILE *fp, char *filename) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            if (i >= MAX_WORD_LENGTH) {
                printf("Error: Word is too long.\n");
                exit(1);
            }
            strncat(filename, &ch, 1);
            i++;
        } else {
            filename[i] = '\0';
            i = 0;
        }
    }
    if (i > 0) {
        filename[i] = '\0';
    }
}

void count_words(char *filename, WordFrequency *word_frequency, int num_words) {
    FILE *fp;
    char ch;
    int i, j;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    for (i = 0; i < num_words; i++) {
        word_frequency[i].frequency = 0;
    }
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            for (j = 0; j < num_words; j++) {
                if (strcmp(word_frequency[j].word, filename) == 0) {
                    word_frequency[j].frequency++;
                    break;
                }
            }
        }
    }
    fclose(fp);
}

void display_word_frequency(WordFrequency *word_frequency, int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_frequency[i].word, word_frequency[i].frequency);
    }
}

int main() {
    char filename[MAX_WORD_LENGTH];
    WordFrequency word_frequency[MAX_WORDS];
    int num_words;

    printf("Enter the name of the text file: ");
    read_file(stdin, filename);

    printf("Enter the number of words to count: ");
    scanf("%d", &num_words);

    count_words(filename, word_frequency, num_words);

    printf("Word frequencies:\n");
    display_word_frequency(word_frequency, num_words);

    return 0;
}