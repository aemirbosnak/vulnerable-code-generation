//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    bool is_correct;
} Word;

Word words[MAX_WORDS];
int num_words = 0;

void load_dictionary(char* dict_file) {
    FILE* fp = fopen(dict_file, "r");
    if (fp == NULL) {
        printf("Error loading dictionary file.\n");
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Dictionary too large.\n");
            exit(1);
        }
        strcpy(words[num_words].word, word);
        words[num_words].is_correct = true;
        num_words++;
    }

    fclose(fp);
}

void check_spelling(char* text_file) {
    FILE* fp = fopen(text_file, "r");
    if (fp == NULL) {
        printf("Error opening text file.\n");
        exit(1);
    }

    char line[1000];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char word[MAX_WORD_LEN];
        char* token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            strcpy(word, token);
            bool is_correct = false;
            for (int i = 0; i < num_words; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    is_correct = true;
                    break;
                }
            }

            if (!is_correct) {
                printf("%s is not in the dictionary.\n", word);
            }

            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(fp);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s dict.txt text.txt\n", argv[0]);
        exit(1);
    }

    load_dictionary(argv[1]);
    check_spelling(argv[2]);

    return 0;
}