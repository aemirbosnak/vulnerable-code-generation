//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE *file, char *filename) {
    char line[MAX_WORD_LENGTH];
    fseek(file, 0, SEEK_SET);
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        printf("%s", line);
    }
}

void count_words(char *filename, WordCount *word_counts, int num_word_counts) {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int i = 0;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File %s not found.\n", filename);
        exit(1);
    }
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            if (strlen(token) > 0) {
                int j;
                for (j = 0; j < i; j++) {
                    if (strcmp(word_counts[j].word, token) == 0) {
                        word_counts[j].count++;
                        break;
                    }
                }
                if (j == i) {
                    strcpy(word_counts[i].word, token);
                    word_counts[i].count = 1;
                    i++;
                }
            }
            token = strtok(NULL, ",.?!;:");
        }
    }
    fclose(file);
}

void print_word_counts(WordCount *word_counts, int num_word_counts) {
    int i;
    for (i = 0; i < num_word_counts; i++) {
        printf("%-20s %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    char filename[MAX_WORD_LENGTH];
    WordCount word_counts[MAX_WORDS];
    int num_word_counts = 0;
    int i;
    printf("Enter filename: ");
    scanf("%s", filename);
    read_file(stdin, filename);
    count_words(filename, word_counts, MAX_WORDS);
    printf("Word counts:\n");
    print_word_counts(word_counts, num_word_counts);
    return 0;
}