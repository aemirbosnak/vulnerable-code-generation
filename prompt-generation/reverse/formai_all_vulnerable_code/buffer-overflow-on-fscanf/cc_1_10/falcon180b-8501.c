//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 100000
#define MIN_WORD_LENGTH 3
#define TRAINING_SET_SIZE 5000
#define SPAM_THRESHOLD 0.8

typedef struct {
    char word[100];
    int is_spam;
} Word;

void load_words(Word words[], int num_words) {
    FILE *fp;
    int i = 0;

    if ((fp = fopen("words.txt", "r")) == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", words[i].word)!= EOF && i < num_words) {
        i++;
    }

    fclose(fp);
}

int is_spam(Word words[], int num_words, char *message) {
    int i, j;
    int num_spam_words = 0;

    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            for (j = 0; j < num_words; j++) {
                if (strcasecmp(message + i, words[j].word) == 0) {
                    if (words[j].is_spam) {
                        num_spam_words++;
                    }
                    break;
                }
            }
        }
    }

    if (num_spam_words >= (int)((float)strlen(message) * SPAM_THRESHOLD)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Word words[MAX_WORDS];
    int num_words = 0;
    char message[1000];

    load_words(words, MAX_WORDS);

    printf("Enter a message to check for spam:\n");
    fgets(message, 1000, stdin);

    if (is_spam(words, num_words, message)) {
        printf("Message is spam.\n");
    } else {
        printf("Message is not spam.\n");
    }

    return 0;
}