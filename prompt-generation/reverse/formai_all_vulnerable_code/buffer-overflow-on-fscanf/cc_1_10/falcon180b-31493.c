//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words = 0;

void read_words_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: too many words in file %s\n", filename);
            exit(1);
        }

        strcpy(words[num_words], word);
        num_words++;
    }

    fclose(fp);
}

int main() {
    srand(time(NULL));

    char *filename = "words.txt";
    read_words_file(filename);

    int num_conspiracies = rand() % 5 + 1;

    for (int i = 0; i < num_conspiracies; i++) {
        int num_words_in_conspiracy = rand() % 10 + 1;
        char conspiracy[num_words_in_conspiracy][MAX_WORD_LENGTH];

        for (int j = 0; j < num_words_in_conspiracy; j++) {
            int word_index = rand() % num_words;
            strcpy(conspiracy[j], words[word_index]);
        }

        printf("Conspiracy theory #%d:\n", i + 1);
        for (int j = 0; j < num_words_in_conspiracy; j++) {
            printf("%s ", conspiracy[j]);
        }
        printf("\n");
    }

    return 0;
}