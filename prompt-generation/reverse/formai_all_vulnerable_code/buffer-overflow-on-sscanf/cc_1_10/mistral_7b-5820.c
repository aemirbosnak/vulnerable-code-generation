//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_ALIEN_WORDS 100
#define MAX_WORD_LENGTH 20
#define MAX_COMMAND_LENGTH 30

typedef struct AlienWord {
    char word[MAX_WORD_LENGTH];
    char *translation;
} AlienWord;

AlienWord alienDictionary[MAX_ALIEN_WORDS];
int numAlienWords = 0;

void addWord(char *alienWord, char *englishTranslation) {
    if (numAlienWords >= MAX_ALIEN_WORDS) {
        printf("Error: Maximum number of alien words reached.\n");
        return;
    }

    strcpy(alienDictionary[numAlienWords].word, alienWord);
    alienDictionary[numAlienWords].translation = malloc(strlen(englishTranslation) + 1);
    strcpy(alienDictionary[numAlienWords].translation, englishTranslation);
    numAlienWords++;
}

void translateAlienSentence(char *alienSentence) {
    char *token, *word;
    int i;

    token = strtok(alienSentence, " ");
    while (token != NULL) {
        for (i = 0; i < numAlienWords; i++) {
            word = alienDictionary[i].word;
            if (strcasecmp(token, word) == 0) {
                printf("%s: %s\n", token, alienDictionary[i].translation);
                break;
            }
        }
        if (i >= numAlienWords) {
            printf("Error: Unknown alien word '%s'.\n", token);
        }

        token = strtok(NULL, " ");
    }
}

void processCommand(char *command) {
    char *token, *alienWord, *englishTranslation;
    int i;

    token = strtok(command, ":");
    if (strcmp(token, "add") != 0) {
        printf("Error: Invalid command. Use 'add <alien_word>:<english_translation>' to add a new word.\n");
        return;
    }

    token = strtok(NULL, ":");
    alienWord = strtok(NULL, " ");
    englishTranslation = strtok(NULL, "\0");

    addWord(alienWord, englishTranslation);
    printf("Alien word '%s' added successfully.\n", alienWord);
}

int main(int argc, char *argv[]) {
    char command[MAX_COMMAND_LENGTH];
    char alienSentence[MAX_WORD_LENGTH];

    if (argc < 2) {
        printf("Usage: %s <commands>\n", argv[0]);
        return 1;
    }

    while (fgets(command, MAX_COMMAND_LENGTH, stdin) != NULL) {
        command[strcspn(command, "\n")] = '\0';
        sscanf(command, "%s", command);
        processCommand(command);
    }

    while (fgets(alienSentence, MAX_WORD_LENGTH, stdin) != NULL) {
        alienSentence[strcspn(alienSentence, "\n")] = '\0';
        translateAlienSentence(alienSentence);
    }

    return 0;
}