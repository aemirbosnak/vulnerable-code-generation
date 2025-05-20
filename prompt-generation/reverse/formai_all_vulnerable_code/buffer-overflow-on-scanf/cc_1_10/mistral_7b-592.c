//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORDS 100
#define WORD_LENGTH 50
#define BASE_SIZE 10

struct Word {
    char word[WORD_LENGTH];
    int sentiment;
};

char *base[BASE_SIZE] = {
    "happy", "joyful", "merry", "pleased", "content",
    "sad", "miserable", "sorrowful", "unhappy", "displeased"
};

int hashFunction(char *word) {
    int hash = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash += tolower(word[i]);
    }
    return hash % BASE_SIZE;
}

int getSentiment(char *word) {
    int index = hashFunction(word);
    int i;
    for (i = 0; i < BASE_SIZE; i++) {
        if (strcmp(base[i], word) == 0) {
            return i;
        }
    }
    return -1;
}

void processSentence(char *sentence) {
    char words[MAX_WORDS][WORD_LENGTH];
    int numWords = 0;
    char *token = strtok(sentence, " ,.!?");
    while (token != NULL) {
        strcpy(words[numWords++], token);
        token = strtok(NULL, " ,.!?");
    }

    int sentimentSum = 0;
    for (int i = 0; i < numWords; i++) {
        int sentiment = getSentiment(words[i]);
        if (sentiment >= 0) {
            sentimentSum += sentiment;
        }
    }

    double averageSentiment = (double)sentimentSum / numWords;

    if (averageSentiment > 4.5) {
        printf("Thou art a joyful knight!\n");
    } else if (averageSentiment > 2.5) {
        printf("Thou art in good spirits.\n");
    } else {
        printf("Thou art in a melancholic mood.\n");
    }
}

int main() {
    char sentence[100];
    printf("Enter a sentence to analyze its sentiment: ");
    scanf("%s", sentence);
    processSentence(sentence);
    return 0;
}