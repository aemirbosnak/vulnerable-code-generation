//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

struct word_t {
    char word[MAX_WORD_LENGTH];
    int count;
};

void load_words(char *filename, struct word_t *words) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open %s\n", filename);
        exit(1);
    }

    int word_count = 0;
    while (fscanf(file, "%s", words[word_count].word)!= EOF) {
        word_count++;
    }
    fclose(file);
}

int is_spam(char *text, struct word_t *words) {
    int spam_score = 0;
    int word_count = 0;

    char *word = strtok(text, " ");
    while (word!= NULL) {
        word_count++;
        struct word_t *w = NULL;
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(words[i].word, word) == 0) {
                w = &words[i];
                break;
            }
        }
        if (w!= NULL) {
            w->count++;
        }
        spam_score += w->count;
        word = strtok(NULL, " ");
    }

    return spam_score > 0? 1 : 0;
}

int main() {
    struct word_t words[MAX_WORDS];
    load_words("words.txt", words);

    char text[MAX_WORD_LENGTH];
    while (fgets(text, MAX_WORD_LENGTH, stdin)!= NULL) {
        int spam = is_spam(text, words);
        if (spam) {
            printf("Spam\n");
        } else {
            printf("Not spam\n");
        }
    }

    return 0;
}