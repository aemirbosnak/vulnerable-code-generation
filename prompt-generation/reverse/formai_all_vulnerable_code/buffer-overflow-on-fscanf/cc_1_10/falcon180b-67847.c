//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int is_spam;
} Word;

void load_words(Word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    int count = 0;
    while (count < MAX_WORDS && fscanf(file, "%s %d", words[count].word, &words[count].is_spam) == 2) {
        count++;
    }

    fclose(file);
}

int is_spam(const char *text, Word words[]) {
    int spam_count = 0;

    char *tokens = strtok(text, " ");
    while (tokens!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(tokens, words[i].word) == 0) {
                if (words[i].is_spam) {
                    spam_count++;
                }
            }
        }
        tokens = strtok(NULL, " ");
    }

    return spam_count > 0;
}

int main() {
    Word words[MAX_WORDS];
    load_words(words);

    char input_text[1000];
    printf("Enter text to check for spam:\n");
    fgets(input_text, sizeof(input_text), stdin);

    if (is_spam(input_text, words)) {
        printf("Spam detected!\n");
    } else {
        printf("No spam detected.\n");
    }

    return 0;
}