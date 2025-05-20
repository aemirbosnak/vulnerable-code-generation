//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 10000
#define MIN_WORD_LEN 3
#define MAX_WORD_LEN 20

struct word {
    char *word;
    int count;
};

int compare_words(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int is_spam(const char *message) {
    int num_spam_words = 0;
    struct word *spam_words = malloc(MAX_WORDS * sizeof(struct word));
    int num_words = 0;
    char *word = strtok(message, " ");

    while (word!= NULL) {
        if (strlen(word) >= MIN_WORD_LEN && strlen(word) <= MAX_WORD_LEN) {
            num_words++;
            struct word *existing_word = bsearch(word, spam_words, num_spam_words, sizeof(struct word), compare_words);

            if (existing_word == NULL) {
                spam_words[num_spam_words++] = (struct word){.word = word,.count = 1};
            } else {
                existing_word->count++;
            }
        }

        word = strtok(NULL, " ");
    }

    qsort(spam_words, num_spam_words, sizeof(struct word), compare_words);

    for (int i = 0; i < num_spam_words; i++) {
        if (spam_words[i].count >= 3) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char message[1000];
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    if (is_spam(message)) {
        printf("Message is spam.\n");
    } else {
        printf("Message is not spam.\n");
    }

    return 0;
}