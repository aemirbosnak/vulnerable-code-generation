//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 80

struct word_t {
    char *word;
    int freq;
};

int cmp_word_t(const void *a, const void *b) {
    const struct word_t *w1 = (const struct word_t *) a;
    const struct word_t *w2 = (const struct word_t *) b;
    return w2->freq - w1->freq;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp;
    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("Unable to open file %s\n", argv[1]);
        return 1;
    }

    struct word_t words[MAX_WORD_LEN];
    int num_words = 0;
    char curr_word[MAX_WORD_LEN];

    // read file word by word
    while (fscanf(fp, "%s", curr_word) == 1) {
        // remove punctuation and convert to lowercase
        int i;
        for (i = 0; curr_word[i]; i++) {
            if (ispunct(curr_word[i])) {
                curr_word[i] = ' ';
            } else {
                curr_word[i] = tolower(curr_word[i]);
            }
        }
        // check if word is in array
        int j;
        for (j = 0; j < num_words; j++) {
            if (strcmp(words[j].word, curr_word) == 0) {
                // increment frequency if found
                words[j].freq++;
                break;
            }
        }
        // add new word if not found
        if (j == num_words) {
            words[num_words].word = strdup(curr_word);
            words[num_words].freq = 1;
            num_words++;
        }
    }

    // sort array by frequency
    qsort(words, num_words, sizeof(struct word_t), cmp_word_t);

    // print top 10 words and frequencies
    int i;
    for (i = 0; i < 10 && i < num_words; i++) {
        printf("%s %d\n", words[i].word, words[i].freq);
    }

    // free memory
    for (i = 0; i < num_words; i++) {
        free(words[i].word);
    }

    fclose(fp);
    return 0;
}