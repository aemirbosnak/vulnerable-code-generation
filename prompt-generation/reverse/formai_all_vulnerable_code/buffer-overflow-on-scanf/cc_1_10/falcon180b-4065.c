//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

struct word_frequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

void read_file(FILE *file, struct word_frequency words[], int *num_words) {
    char line[100];
    char *token;
    while (fgets(line, sizeof(line), file)!= NULL) {
        token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            int word_length = strlen(token);
            if (word_length <= MAX_WORD_LENGTH) {
                strcpy(words[*num_words].word, token);
                words[*num_words].frequency++;
                (*num_words)++;
            }
            token = strtok(NULL, ",.?!;:");
        }
    }
}

void sort_words(struct word_frequency words[], int num_words) {
    int i, j;
    char temp[MAX_WORD_LENGTH];
    for (i = 0; i < num_words - 1; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (words[i].frequency < words[j].frequency) {
                strcpy(temp, words[i].word);
                strcpy(words[i].word, words[j].word);
                strcpy(words[j].word, temp);
                words[i].frequency ^= words[j].frequency;
                words[j].frequency ^= words[i].frequency;
                words[i].frequency ^= words[j].frequency;
            }
        }
    }
}

void print_word_frequency(struct word_frequency words[], int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    FILE *file;
    char filename[100];
    struct word_frequency words[MAX_WORDS];
    int num_words = 0;
    printf("Enter the name of the input file: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    read_file(file, words, &num_words);
    fclose(file);
    sort_words(words, num_words);
    printf("Word frequency:\n");
    print_word_frequency(words, num_words);
    return 0;
}