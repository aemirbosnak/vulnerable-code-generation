//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word_struct {
    char word[MAX_WORD_LENGTH];
    int count;
};

void load_words(struct word_struct *words, int num_words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file\n");
        exit(1);
    }

    int i = 0;
    while (i < num_words && fscanf(file, "%s", words[i].word)!= EOF) {
        i++;
    }

    for (int j = 0; j < i; j++) {
        words[j].count = 0;
    }

    fclose(file);
}

void save_word_counts(struct word_struct *words, int num_words) {
    FILE *file = fopen("word_counts.txt", "w");
    if (file == NULL) {
        printf("Error saving word counts file\n");
        exit(1);
    }

    for (int i = 0; i < num_words; i++) {
        fprintf(file, "%s %d\n", words[i].word, words[i].count);
    }

    fclose(file);
}

void count_words(char *text, struct word_struct *words, int num_words) {
    int len = strlen(text);
    char *word = (char *) malloc(len + 1);
    strcpy(word, text);

    char *token = strtok(word, ",.?!;:");
    while (token!= NULL) {
        int word_len = strlen(token);
        if (word_len > 0 && word_len <= MAX_WORD_LENGTH) {
            for (int i = 0; i < num_words; i++) {
                if (strcmp(token, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
        }

        token = strtok(NULL, ",.?!;:");
    }

    free(word);
}

int main() {
    struct word_struct words[MAX_WORDS];
    int num_words = 0;

    load_words(words, MAX_WORDS);

    char input_text[1000];
    while (fgets(input_text, sizeof(input_text), stdin)!= NULL) {
        count_words(input_text, words, num_words);
    }

    save_word_counts(words, num_words);

    return 0;
}