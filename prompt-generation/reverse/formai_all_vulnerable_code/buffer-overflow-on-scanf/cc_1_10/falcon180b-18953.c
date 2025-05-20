//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compare_words(const void *a, const void *b) {
    const Word *w1 = a;
    const Word *w2 = b;

    return strcmp(w1->word, w2->word);
}

int is_spam(char *email) {
    int spam_count = 0;
    Word words[MAX_WORDS];
    int num_words = 0;

    // Tokenize email into words
    char *token = strtok(email, " ");
    while (token!= NULL) {
        if (num_words >= MAX_WORDS) {
            break;
        }

        int len = strlen(token);
        if (len > MAX_WORD_LENGTH) {
            len = MAX_WORD_LENGTH;
        }

        strncpy(words[num_words].word, token, len);
        words[num_words].count = 0;
        num_words++;

        token = strtok(NULL, " ");
    }

    // Count occurrences of known spam words
    for (int i = 0; i < num_words; i++) {
        qsort(words, num_words, sizeof(Word), compare_words);
        for (int j = 0; j < num_words; j++) {
            if (strcmp(words[j].word, "viagra") == 0) {
                words[j].count++;
                spam_count++;
            } else if (strcmp(words[j].word, "cialis") == 0) {
                words[j].count++;
                spam_count++;
            } else if (strcmp(words[j].word, "make") == 0) {
                words[j].count++;
                spam_count++;
            } else if (strcmp(words[j].word, "money") == 0) {
                words[j].count++;
                spam_count++;
            }
        }
    }

    return spam_count > 0;
}

int main() {
    char email[1000];

    printf("Enter an email:\n");
    scanf("%s", email);

    if (is_spam(email)) {
        printf("SPAM\n");
    } else {
        printf("NOT SPAM\n");
    }

    return 0;
}