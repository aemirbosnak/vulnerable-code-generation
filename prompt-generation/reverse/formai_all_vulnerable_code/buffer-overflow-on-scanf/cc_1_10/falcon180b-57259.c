//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20
#define HASH_TABLE_SIZE 1000

typedef struct {
    char *word;
    int count;
} WordCount;

WordCount hashTable[HASH_TABLE_SIZE];

int hash(char *word) {
    int sum = 0;
    while (*word) {
        sum += *word;
        word++;
    }
    return sum % HASH_TABLE_SIZE;
}

void addWord(char *word) {
    int index = hash(word);
    WordCount *entry = &hashTable[index];

    while (entry->word!= NULL) {
        if (strcmp(entry->word, word) == 0) {
            entry->count++;
            return;
        }
        entry++;
    }

    entry->word = strdup(word);
    entry->count = 1;
}

int isSpam(char *message) {
    char *word = strtok(message, " ");
    while (word!= NULL) {
        int index = hash(word);
        WordCount *entry = &hashTable[index];

        while (entry->word!= NULL) {
            if (strcmp(entry->word, word) == 0) {
                if (entry->count >= 3) {
                    return 1;
                }
                entry->count++;
            }
            entry++;
        }

        word = strtok(NULL, " ");
    }

    return 0;
}

int main() {
    int numMessages;
    scanf("%d", &numMessages);

    for (int i = 0; i < numMessages; i++) {
        char message[MAX_WORD_LEN * MAX_WORDS];
        fgets(message, MAX_WORD_LEN * MAX_WORDS, stdin);

        int isSpamResult = isSpam(message);
        if (isSpamResult == 1) {
            printf("Spam\n");
        } else {
            printf("Not spam\n");
        }
    }

    return 0;
}