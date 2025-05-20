//Falcon-180B DATASET v1.0 Category: File handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE* file, char* line, int max_length) {
    int length = 0;
    while (fgets(line, max_length, file)!= NULL) {
        length += strlen(line);
        if (length >= MAX_LINE_LENGTH) {
            break;
        }
    }
    line[length] = '\0';
}

void tokenize(char* line, char* words[], int max_words) {
    char* token = strtok(line, ",.!?;:\"'`-");
    int count = 0;
    while (token!= NULL && count < max_words) {
        strcpy(words[count], token);
        count++;
        token = strtok(NULL, ",.!?;:\"'`-");
    }
}

void count_words(char* words[], int num_words, WordCount counts[], int max_counts) {
    int count = 0;
    for (int i = 0; i < num_words; i++) {
        for (int j = 0; j < count; j++) {
            if (strcmp(words[i], counts[j].word) == 0) {
                counts[j].count++;
                break;
            }
        }
        if (count == max_counts) {
            break;
        }
        strcpy(counts[count].word, words[i]);
        counts[count].count = 1;
        count++;
    }
}

void print_counts(WordCount counts[], int num_counts) {
    for (int i = 0; i < num_counts; i++) {
        printf("%s: %d\n", counts[i].word, counts[i].count);
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    read_file(file, line, MAX_LINE_LENGTH);

    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int num_words = 0;
    tokenize(line, words, MAX_WORDS);
    num_words = strlen(line);

    WordCount counts[MAX_WORDS];
    int num_counts = 0;
    count_words(words, num_words, counts, MAX_WORDS);

    print_counts(counts, num_counts);

    fclose(file);
    return 0;
}