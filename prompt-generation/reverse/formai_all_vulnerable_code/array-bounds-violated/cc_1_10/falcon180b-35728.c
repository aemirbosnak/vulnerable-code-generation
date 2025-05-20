//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_words(const void *a, const void *b) {
    const struct word_count *word_a = a;
    const struct word_count *word_b = b;

    return strcmp(word_a->word, word_b->word);
}

void count_words(char *text) {
    int i, j, k;
    char word[MAX_WORD_LENGTH];
    struct word_count words[MAX_WORDS];
    int num_words = 0;

    for (i = 0; text[i]!= '\0'; i++) {
        if (isspace(text[i])) {
            if (j > 0) {
                word[j] = '\0';
                for (k = 0; k < num_words; k++) {
                    if (strcmp(word, words[k].word) == 0) {
                        words[k].count++;
                        break;
                    }
                }
                if (k == num_words) {
                    strcpy(words[num_words].word, word);
                    words[num_words].count = 1;
                    num_words++;
                }
            }
            j = 0;
        } else {
            if (j >= MAX_WORD_LENGTH - 1) {
                break;
            }
            word[j++] = tolower(text[i]);
        }
    }

    if (j > 0) {
        word[j] = '\0';
        for (k = 0; k < num_words; k++) {
            if (strcmp(word, words[k].word) == 0) {
                words[k].count++;
                break;
            }
        }
        if (k == num_words) {
            strcpy(words[num_words].word, word);
            words[num_words].count = 1;
            num_words++;
        }
    }

    qsort(words, num_words, sizeof(struct word_count), compare_words);

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char text[1000000];

    printf("Enter text:\n");
    fgets(text, sizeof(text), stdin);

    count_words(text);

    return 0;
}