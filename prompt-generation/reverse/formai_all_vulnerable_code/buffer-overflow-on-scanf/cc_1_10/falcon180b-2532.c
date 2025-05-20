//Falcon-180B DATASET v1.0 Category: Text processing ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 100

typedef struct {
    char *word;
    int count;
} WordCount;

void read_file(FILE *fp, char *filename) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            ungetc(ch, fp);
            break;
        }
        i++;
    }
    rewind(fp);
    char line[1000];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        int j = 0;
        while (line[j]!= '\n') {
            if (isalpha(line[j])) {
                line[j] = tolower(line[j]);
            }
            j++;
        }
        line[j] = '\0';
        printf("%s", line);
    }
}

void count_words(char *filename, WordCount *word_counts, int num_words) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    read_file(fp, filename);
    int i = 0;
    while (i < num_words) {
        char word[100];
        fgets(word, sizeof(word), stdin);
        strcpy(word_counts[i].word, word);
        i++;
    }
    fclose(fp);
}

void display_word_counts(WordCount *word_counts, int num_words) {
    printf("\nWord Counts:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    WordCount word_counts[MAX_WORDS];
    int num_words = 0;
    while (num_words < MAX_WORDS && num_words < 10) {
        printf("Enter word to count (or press enter to finish): ");
        char word[100];
        fgets(word, sizeof(word), stdin);
        if (strlen(word) > 0) {
            strcpy(word_counts[num_words].word, word);
            num_words++;
        }
    }
    count_words(filename, word_counts, num_words);
    display_word_counts(word_counts, num_words);
    return 0;
}