//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000000
#define MAX_WORDS 100
#define MAX_CHARS 100

typedef struct {
    char word[MAX_CHARS];
    int count;
} WordCount;

void read_file(FILE* fp, char* line, int max_chars) {
    char c;
    int i = 0;

    while ((c = fgetc(fp))!= EOF && i < max_chars - 1) {
        line[i++] = c;
    }

    line[i] = '\0';
}

void tokenize(char* line, char* words[], int max_words) {
    char* token = strtok(line, ",.?!;:");
    int i = 0;

    while (token!= NULL && i < max_words - 1) {
        strcpy(words[i], token);
        i++;
        token = strtok(NULL, ",.?!;:");
    }

    words[i] = "\0";
}

void count_words(char* words[], int num_words, WordCount* counts, int max_counts) {
    for (int i = 0; i < num_words; i++) {
        int found = 0;

        for (int j = 0; j < max_counts &&!found; j++) {
            if (strcmp(counts[j].word, words[i]) == 0) {
                counts[j].count++;
                found = 1;
            }
        }

        if (!found) {
            strcpy(counts[max_counts - 1].word, words[i]);
            counts[max_counts - 1].count = 1;
            max_counts++;
        }
    }
}

void print_counts(WordCount* counts, int num_counts) {
    for (int i = 0; i < num_counts; i++) {
        printf("%s: %d\n", counts[i].word, counts[i].count);
    }
}

int main() {
    FILE* fp;
    char line[MAX_CHARS];
    char words[MAX_WORDS][MAX_CHARS];
    WordCount counts[MAX_WORDS];
    int num_words, num_counts = 0;

    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while (fgets(line, MAX_CHARS, fp)!= NULL) {
        read_file(fp, line, MAX_CHARS);
        tokenize(line, words, MAX_WORDS);
        count_words(words, num_words, counts, MAX_WORDS);
        num_counts += num_words;
    }

    fclose(fp);

    printf("Total words: %d\n", num_counts);
    print_counts(counts, num_counts);

    return 0;
}