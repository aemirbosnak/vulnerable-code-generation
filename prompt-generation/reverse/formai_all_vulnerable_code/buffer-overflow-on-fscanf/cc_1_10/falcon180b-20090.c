//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 50

struct word_t {
    char word[MAX_WORD_LEN];
    int count;
};

void load_words(struct word_t *words, FILE *fp) {
    int i = 0;
    while (fscanf(fp, "%s", words[i].word)!= EOF) {
        words[i].count = 0;
        i++;
    }
}

int is_spam(char *message, struct word_t *words) {
    int i, j, len, count = 0;
    char *word;

    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            len = 0;
            word = (char *)malloc(MAX_WORD_LEN * sizeof(char));
            while (isalpha(message[i])) {
                word[len] = tolower(message[i]);
                i++;
                len++;
            }
            word[len] = '\0';

            for (j = 0; j < MAX_WORD_LEN; j++) {
                if (strcmp(word, words[j].word) == 0) {
                    words[j].count++;
                    count++;
                    break;
                }
            }

            free(word);
        }
    }

    return count;
}

int main() {
    FILE *fp;
    char message[1000];
    struct word_t words[MAX_WORDS];

    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    load_words(words, fp);
    fclose(fp);

    printf("Enter message: ");
    scanf("%[^\n]", message);

    int spam_count = is_spam(message, words);

    if (spam_count > 0) {
        printf("Message is spam\n");
    } else {
        printf("Message is not spam\n");
    }

    return 0;
}