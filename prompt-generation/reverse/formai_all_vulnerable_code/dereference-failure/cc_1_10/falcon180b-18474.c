//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

char *words[MAX_WORDS];
int num_words = 0;

void add_word(char *word) {
    if (num_words >= MAX_WORDS) {
        printf("Error: Too many words.\n");
        exit(1);
    }
    words[num_words++] = strdup(word);
}

int is_spam(char *message) {
    char *word;
    int i, j, score = 0;

    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            word = &message[i];
            while (isalpha(word[j])) {
                j++;
            }
            word[j] = '\0';
            for (int k = 0; k < num_words; k++) {
                if (strcmp(word, words[k]) == 0) {
                    score++;
                    break;
                }
            }
        }
    }

    return score;
}

int main() {
    char message[1000];
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    add_word("viagra");
    add_word("cialis");
    add_word("spam");
    add_word("scam");
    add_word("free");

    int score = is_spam(message);

    if (score >= 3) {
        printf("SPAM!\n");
    } else {
        printf("Not spam.\n");
    }

    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }

    return 0;
}