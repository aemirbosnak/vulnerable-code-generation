//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_words(const void *a, const void *b) {
    const struct word *word1 = a;
    const struct word *word2 = b;

    return strcmp(word1->word, word2->word);
}

void count_words(char *text, struct word *words) {
    char *word = strtok(text, ",.!?;:");
    while (word!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS && words[i].word[0]!= '\0'; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == MAX_WORDS) {
            strncpy(words[i].word, word, MAX_WORD_LENGTH - 1);
            words[i].word[MAX_WORD_LENGTH - 1] = '\0';
            words[i].count = 1;
        }
        word = strtok(NULL, ",.!?;:");
    }
}

int main() {
    FILE *file;
    char line[1024];
    char *text = NULL;
    size_t text_size = 0;
    struct word words[MAX_WORDS];

    file = fopen("spam.txt", "r");
    if (file == NULL) {
        printf("Error: could not open spam.txt\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        text_size += strlen(line);
        if (text_size > 0 && text == NULL) {
            text = malloc(text_size + 1);
            strcpy(text, line);
        } else {
            text = realloc(text, text_size + strlen(line) + 1);
            strcat(text, line);
        }
    }

    fclose(file);

    count_words(text, words);

    qsort(words, MAX_WORDS, sizeof(struct word), compare_words);

    printf("Spam words:\n");
    for (int i = 0; i < MAX_WORDS && words[i].word[0]!= '\0'; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    free(text);
    return 0;
}