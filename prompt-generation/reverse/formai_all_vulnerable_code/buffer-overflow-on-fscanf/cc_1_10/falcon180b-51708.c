//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

Word words[MAX_WORDS];
int num_words = 0;

void load_dictionary(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: dictionary is full.\n");
            exit(1);
        }

        Word* w = &words[num_words];
        strcpy(w->word, word);
        w->count = 0;

        num_words++;
    }

    fclose(fp);
}

void check_spelling(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    char line[1000];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char* word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }

            if (i == num_words) {
                printf("Unknown word: %s\n", word);
            }

            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(fp);
}

void print_results() {
    printf("Spelling results:\n");
    for (int i = 0; i < num_words; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }

    load_dictionary(argv[1]);
    check_spelling(argv[2]);
    print_results();

    return 0;
}