//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_WORDS 100000
#define WORD_LENGTH 15

struct word {
    char word[WORD_LENGTH];
    bool is_correct;
};

void load_words(struct word words[], int n) {
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open words.txt\n");
        exit(1);
    }

    int i = 0;
    char word[WORD_LENGTH];

    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(words[i].word, word);
        words[i].is_correct = true;
        i++;
    }

    fclose(fp);
}

void save_words(struct word words[], int n) {
    FILE *fp = fopen("words.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not open words.txt\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        if (words[i].is_correct) {
            fprintf(fp, "%s\n", words[i].word);
        }
    }

    fclose(fp);
}

void spell_check(char *text) {
    struct word words[MAX_WORDS];
    int n = 0;

    load_words(words, n);

    char *word = strtok(text, " ");
    while (word!= NULL) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (strcmp(word, words[i].word) == 0) {
                found = true;
                break;
            }
        }

        if (!found) {
            printf("Possible spelling mistake: %s\n", word);
        }

        word = strtok(NULL, " ");
    }
}

int main() {
    char text[1000];

    printf("Enter text to spell check:\n");
    fgets(text, sizeof(text), stdin);

    spell_check(text);

    return 0;
}