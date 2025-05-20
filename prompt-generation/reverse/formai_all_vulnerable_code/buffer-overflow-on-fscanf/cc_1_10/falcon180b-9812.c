//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int is_spam;
} Word;

void load_words(Word words[], int num_words) {
    FILE *file = fopen("words.txt", "r");

    int i = 0;
    while (fscanf(file, "%s", words[i].word)!= EOF && i < num_words) {
        i++;
    }

    fclose(file);
}

int is_spam(char *message, Word words[], int num_words) {
    int num_spam_words = 0;

    char *token = strtok(message, " ");
    while (token!= NULL) {
        int j;
        for (j = 0; j < num_words; j++) {
            if (strcmp(token, words[j].word) == 0) {
                num_spam_words++;
                break;
            }
        }

        token = strtok(NULL, " ");
    }

    return num_spam_words > 0;
}

int main() {
    Word words[MAX_WORDS];
    load_words(words, MAX_WORDS);

    char message[1000];
    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    if (is_spam(message, words, MAX_WORDS)) {
        printf("Message is spam.\n");
    } else {
        printf("Message is not spam.\n");
    }

    return 0;
}