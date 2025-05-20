//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LEN 100

struct word_t {
    char word[MAX_WORD_LEN + 1];
    int count;
};

void load_words(struct word_t words[], int num_words) {
    FILE *fp = fopen("words.txt", "r");
    if (!fp) {
        printf("Error loading words\n");
        exit(1);
    }
    int i = 0;
    char word[MAX_WORD_LEN + 1];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (i >= num_words) {
            printf("Too many words\n");
            exit(1);
        }
        strcpy(words[i].word, word);
        words[i].count = 0;
        i++;
    }
    fclose(fp);
}

void spell_check(char *text, int text_len, struct word_t words[], int num_words) {
    int i = 0;
    while (i < text_len) {
        char word[MAX_WORD_LEN + 1];
        int j = 0;
        while (isalnum(text[i])) {
            if (j >= MAX_WORD_LEN) {
                printf("Word too long\n");
                exit(1);
            }
            word[j] = tolower(text[i]);
            i++;
            j++;
        }
        word[j] = '\0';
        int found = 0;
        for (int k = 0; k < num_words; k++) {
            if (strcmp(word, words[k].word) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Misspelled word: %s\n", word);
        }
        i += j - 1;
    }
}

int main() {
    struct word_t words[MAX_WORDS];
    int num_words = 0;
    load_words(words, MAX_WORDS);
    char text[MAX_WORD_LEN * 100];
    printf("Enter text:\n");
    fgets(text, MAX_WORD_LEN * 100, stdin);
    int text_len = strlen(text);
    spell_check(text, text_len, words, num_words);
    return 0;
}