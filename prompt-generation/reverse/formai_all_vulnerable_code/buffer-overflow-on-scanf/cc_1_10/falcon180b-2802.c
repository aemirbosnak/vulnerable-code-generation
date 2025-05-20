//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LEN 50

typedef struct {
    char word[WORD_LEN];
    int count;
} Word;

void read_file(char *filename, Word *words) {
    FILE *fp;
    char line[1000];
    char *token;
    Word *current_word = words;

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            if (strlen(token) <= WORD_LEN) {
                strcpy(current_word->word, token);
                current_word->count++;
            }
            current_word++;
            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(fp);
}

void sort_words(Word *words) {
    int i, j;
    Word temp;

    for (i = 0; i < MAX_WORDS - 1; i++) {
        for (j = i + 1; j < MAX_WORDS; j++) {
            if (words[j].count > words[i].count) {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_words(Word *words) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    Word words[MAX_WORDS];
    char filename[100];

    printf("Enter the filename: ");
    scanf("%s", filename);

    read_file(filename, words);
    sort_words(words);
    print_words(words);

    return 0;
}