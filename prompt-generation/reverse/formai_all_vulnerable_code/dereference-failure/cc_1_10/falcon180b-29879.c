//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 64

struct word_t {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int compare_words(const void *a, const void *b) {
    const struct word_t *w1 = a;
    const struct word_t *w2 = b;
    return strcmp(w1->word, w2->word);
}

int main() {
    FILE *file;
    char line[1024];
    char word[MAX_WORD_LENGTH];
    int word_count = 0;
    struct word_t *words = malloc(MAX_WORDS * sizeof(struct word_t));
    int i = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            strcpy(word, token);
            for (int j = 0; j < strlen(word); j++) {
                word[j] = tolower(word[j]);
            }
            if (strlen(word) > 0 && strcmp(word, "a")!= 0 && strcmp(word, "an")!= 0 && strcmp(word, "the")!= 0) {
                int found = 0;
                for (int k = 0; k < i; k++) {
                    if (strcmp(words[k].word, word) == 0) {
                        words[k].frequency++;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    strcpy(words[i].word, word);
                    words[i].frequency = 1;
                    i++;
                }
            }
            token = strtok(NULL, ",.?!;:");
        }
        word_count += i;
    }

    qsort(words, i, sizeof(struct word_t), compare_words);

    printf("Total words: %d\n", word_count);

    for (int j = 0; j < i; j++) {
        printf("%s: %d\n", words[j].word, words[j].frequency);
    }

    return 0;
}