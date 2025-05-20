//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_LENGTH 20

char *words[MAX_WORDS];
int num_words = 0;

void add_word(char *word) {
    if (num_words < MAX_WORDS) {
        words[num_words++] = word;
    }
}

void generate_theory() {
    srand(time(NULL));
    char theory[MAX_LENGTH];
    theory[0] = '\0';
    int i = 0;
    while (i < 5) {
        int word_index = rand() % num_words;
        strcat(theory, words[word_index]);
        strcat(theory, " ");
        i++;
    }
    printf("Theory: %s\n", theory);
}

void load_words(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    char word[MAX_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        add_word(word);
    }
    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <word_file>\n", argv[0]);
        exit(1);
    }
    load_words(argv[1]);
    while (1) {
        generate_theory();
    }
    return 0;
}