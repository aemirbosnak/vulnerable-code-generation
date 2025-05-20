//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void read_file(FILE *fp, char *filename) {
    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            ungetc(ch, fp);
            fscanf(fp, "%s", filename);
        }
    }
}

void count_words(char *text, int word_count[], int max_words) {
    char word[MAX_WORD_LENGTH];
    int i = 0;
    while (i < max_words && fscanf(text, "%s", word)!= EOF) {
        word[strcspn(word, "\n")] = '\0';
        word_count[i]++;
        i++;
    }
}

void display_frequencies(WordFrequency freq[], int n) {
    printf("Word\tFrequency\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\n", freq[i].word, freq[i].count);
    }
}

int main() {
    FILE *fp;
    char filename[MAX_WORD_LENGTH];
    char text[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count[MAX_WORDS] = { 0 };
    WordFrequency freq[MAX_WORDS];

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    read_file(fp, filename);
    fclose(fp);

    count_words(text, word_count, MAX_WORDS);

    for (int i = 0; i < MAX_WORDS; i++) {
        if (word_count[i] > 0) {
            strcpy(freq[i].word, text[i]);
            freq[i].count = word_count[i];
        }
    }

    display_frequencies(freq, MAX_WORDS);

    return 0;
}