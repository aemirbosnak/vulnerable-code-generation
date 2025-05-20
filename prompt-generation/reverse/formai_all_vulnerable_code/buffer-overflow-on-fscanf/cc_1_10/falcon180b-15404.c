//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 10000

struct DictionaryEntry {
    char word[MAX_WORD_LENGTH];
    int isSpam;
};

int isSpam(char* message) {
    FILE* dictionaryFile = fopen("dictionary.txt", "r");
    struct DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];
    int numEntries = 0;

    while (fscanf(dictionaryFile, "%s %d\n", dictionary[numEntries].word, &dictionary[numEntries].isSpam)!= EOF) {
        numEntries++;
    }

    fclose(dictionaryFile);

    int numSpamWords = 0;
    int numWords = 0;

    char* token = strtok(message, " ");
    while (token!= NULL) {
        numWords++;

        struct DictionaryEntry* entry = NULL;
        for (int i = 0; i < numEntries; i++) {
            if (strcmp(token, dictionary[i].word) == 0) {
                entry = &dictionary[i];
                break;
            }
        }

        if (entry!= NULL && entry->isSpam == 1) {
            numSpamWords++;
        }

        token = strtok(NULL, " ");
    }

    if (numSpamWords >= numWords / 2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char message[1000];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    if (isSpam(message)) {
        printf("Message is spam.\n");
    } else {
        printf("Message is not spam.\n");
    }

    return 0;
}