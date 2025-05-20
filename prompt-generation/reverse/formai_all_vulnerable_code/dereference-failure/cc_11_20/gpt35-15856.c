//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: curious
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORD_LEN 100

struct word_freq {
    char *word;
    int freq;
};

int main() {
    char c, *word;
    int i, j, k, len = 0, word_count = 0, word_freq_count = 0, word_index, found;
    struct word_freq *word_freqs = malloc(sizeof(struct word_freq));

    printf("Enter text (press Ctrl-D to quit):\n");

    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            if (++len > MAX_WORD_LEN) {
                printf("Error: Word too long\n");
                return 1;
            }

            if (word_count == 0) {
                word = malloc(sizeof(char) * len);
            } else {
                word = realloc(word, sizeof(char) * len);
            }

            word[len - 1] = tolower(c);
        } else {
            if (len > 0) {
                word[len] = '\0';

                found = 0;
                for (i = 0; i < word_freq_count; i++) {
                    if (strcmp(word, word_freqs[i].word) == 0) {
                        word_freqs[i].freq++;
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    if (word_freq_count == 0) {
                        word_freqs[0].word = malloc(sizeof(char) * len);
                        strcpy(word_freqs[0].word, word);
                        word_freqs[0].freq = 1;
                    } else {
                        // Check if word fits in the last frequency struct
                        if (len <= strlen(word_freqs[word_freq_count - 1].word)) {
                            strcpy(word_freqs[word_freq_count - 1].word, word);
                            word_freqs[word_freq_count - 1].freq = 1;
                        } else {
                            word_freq_count++;
                            word_freqs = realloc(word_freqs, sizeof(struct word_freq) * word_freq_count);
                            word_freqs[word_freq_count - 1].word = malloc(sizeof(char) * len);
                            strcpy(word_freqs[word_freq_count - 1].word, word);
                            word_freqs[word_freq_count - 1].freq = 1;
                        }
                    }
                }

                len = 0;
                word_count++;
            }
        }
    }

    if (len > 0) {
        word[len] = '\0';

        found = 0;
        for (i = 0; i < word_freq_count; i++) {
            if (strcmp(word, word_freqs[i].word) == 0) {
                word_freqs[i].freq++;
                found = 1;
                break;
            }
        }

        if (!found) {
            if (word_freq_count == 0) {
                word_freqs[0].word = malloc(sizeof(char) * len);
                strcpy(word_freqs[0].word, word);
                word_freqs[0].freq = 1;
            } else {
                if (len <= strlen(word_freqs[word_freq_count - 1].word)) {
                    strcpy(word_freqs[word_freq_count - 1].word, word);
                    word_freqs[word_freq_count - 1].freq = 1;
                } else {
                    word_freq_count++;
                    word_freqs = realloc(word_freqs, sizeof(struct word_freq) * word_freq_count);
                    word_freqs[word_freq_count - 1].word = malloc(sizeof(char) * len);
                    strcpy(word_freqs[word_freq_count - 1].word, word);
                    word_freqs[word_freq_count - 1].freq = 1;
                }
            }
        }
    }

    printf("\nWord frequency count:\n");
    for (i = 0; i < word_freq_count; i++) {
        printf("%s: %d\n", word_freqs[i].word, word_freqs[i].freq);
        free(word_freqs[i].word);
    }
    free(word_freqs);

    return 0;
}