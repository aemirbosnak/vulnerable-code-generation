//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000
#define MAX_SPAM_WORDS 100
#define MIN_SPAM_SCORE 1

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} SpamWord;

void loadSpamWords(SpamWord words[], int numWords) {
    FILE *file = fopen("spam_words.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open spam_words.txt\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s %d", words[i].word, &words[i].count)!= EOF) {
        i++;
    }

    fclose(file);
}

int isSpam(char message[], int messageLength, SpamWord words[], int numWords) {
    int spamScore = 0;

    for (int i = 0; i < numWords; i++) {
        char *word = strtok(message, " ");
        while (word!= NULL) {
            if (strcmp(word, words[i].word) == 0) {
                spamScore += words[i].count;
            }
            word = strtok(NULL, " ");
        }
    }

    if (spamScore >= MIN_SPAM_SCORE) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    SpamWord words[MAX_SPAM_WORDS];
    loadSpamWords(words, MAX_SPAM_WORDS);

    char message[MAX_MESSAGE_LENGTH];
    printf("Enter a message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    int messageLength = strlen(message);
    if (messageLength > MAX_MESSAGE_LENGTH) {
        printf("Error: Message is too long\n");
        exit(1);
    }

    int isSpamResult = isSpam(message, messageLength, words, MAX_SPAM_WORDS);

    if (isSpamResult == 1) {
        printf("Message is spam\n");
    } else {
        printf("Message is not spam\n");
    }

    return 0;
}