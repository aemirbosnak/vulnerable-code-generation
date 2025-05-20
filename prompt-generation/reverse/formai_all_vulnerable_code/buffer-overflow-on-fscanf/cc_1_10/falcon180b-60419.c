//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: grateful
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

void load_dictionary(Word words[]) {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    int word_count = 0;
    while (fscanf(fp, "%s", words[word_count].word)!= EOF) {
        words[word_count].is_correct = true;
        word_count++;
    }

    fclose(fp);
}

void check_spelling(const char *text, Word words[], int *error_count) {
    int word_count = 0;
    char word[MAX_WORD_LENGTH];
    bool in_word = false;

    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (!in_word) {
                strcpy(word, "");
                in_word = true;
            }
            strcat(word, text[i]);
        } else {
            in_word = false;
            if (strlen(word) > 0) {
                bool found = false;
                for (int j = 0; j < word_count; j++) {
                    if (strcmp(word, words[j].word) == 0) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    (*error_count)++;
                    printf("Possible spelling mistake: %s\n", word);
                }
            }
        }
    }
}

int main() {
    Word words[MAX_WORDS];
    load_dictionary(words);

    char text[100000];
    printf("Enter text to check spelling:\n");
    fgets(text, sizeof(text), stdin);

    int error_count = 0;
    check_spelling(text, words, &error_count);

    if (error_count == 0) {
        printf("No spelling mistakes found.\n");
    } else {
        printf("%d possible spelling mistakes found.\n", error_count);
    }

    return 0;
}