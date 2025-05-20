//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_words(const void *a, const void *b) {
    struct word *word_a = (struct word *) a;
    struct word *word_b = (struct word *) b;

    return strcmp(word_a->word, word_b->word);
}

void count_words(char *message, struct word *words) {
    char *token = strtok(message, " ");

    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }

        if (i == MAX_WORDS) {
            strcpy(words[i].word, token);
            words[i].count = 1;
        }

        token = strtok(NULL, " ");
    }
}

int is_spam(char *message, struct word *words) {
    int i, spam_count = 0;

    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            if (strcmp(words[i].word, "viagra") == 0 ||
                strcmp(words[i].word, "cialis") == 0 ||
                strcmp(words[i].word, "free") == 0 ||
                strcmp(words[i].word, "money") == 0) {
                spam_count++;
            }
        }
    }

    if (spam_count >= 2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char message[1000];
    struct word words[MAX_WORDS];

    printf("Enter a message to check for spam: ");
    fgets(message, sizeof(message), stdin);

    count_words(message, words);

    qsort(words, MAX_WORDS, sizeof(struct word), compare_words);

    if (is_spam(message, words)) {
        printf("Spam detected!\n");
    } else {
        printf("No spam detected.\n");
    }

    return 0;
}