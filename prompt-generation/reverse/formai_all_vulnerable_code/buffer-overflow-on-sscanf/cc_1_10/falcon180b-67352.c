//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100

typedef struct {
    char *word;
    char *translation;
} WordTranslation;

void loadDictionary(WordTranslation *dictionary) {
    FILE *file = fopen("dictionary.txt", "r");
    char line[MAX_SENTENCE_LENGTH];
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
    
    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }
    
    while (fgets(line, MAX_SENTENCE_LENGTH, file)!= NULL) {
        sscanf(line, "%s %s", word, translation);
        dictionary[atoi(word)].word = strdup(word);
        dictionary[atoi(word)].translation = strdup(translation);
    }
    
    fclose(file);
}

void translateSentence(char *sentence, WordTranslation *dictionary) {
    int i, j, wordCount = 0;
    char *word = strtok(sentence, " ");
    char translatedSentence[MAX_SENTENCE_LENGTH];

    while (word!= NULL) {
        for (i = 0; i < MAX_WORD_LENGTH; i++) {
            if (isalpha(word[i])) {
                word[i] = tolower(word[i]);
            }
        }

        for (i = 0; i < MAX_WORD_LENGTH; i++) {
            if (isalpha(word[i])) {
                break;
            }
        }

        for (j = 0; j < i; j++) {
            if (!isalpha(word[j])) {
                word[j] = '\0';
            }
        }

        int wordIndex = atoi(word);
        if (dictionary[wordIndex].word!= NULL) {
            strcat(translatedSentence, dictionary[wordIndex].translation);
            strcat(translatedSentence, " ");
        } else {
            strcat(translatedSentence, word);
            strcat(translatedSentence, " ");
        }

        wordCount++;
        word = strtok(NULL, " ");
    }

    printf("%s\n", translatedSentence);
}

int main() {
    WordTranslation dictionary[MAX_WORD_LENGTH];
    loadDictionary(dictionary);

    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence to translate: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    translateSentence(sentence, dictionary);

    return 0;
}