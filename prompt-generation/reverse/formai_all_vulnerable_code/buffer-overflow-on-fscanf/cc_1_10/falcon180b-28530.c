//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: cheerful
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAX_WORD_SIZE 100
#define MAX_SENTENCE_SIZE 1000
#define MAX_TRANSLATION_SIZE 2000

typedef struct {
    char word[MAX_WORD_SIZE];
    char translation[MAX_TRANSLATION_SIZE];
} WordTranslation;

typedef struct {
    WordTranslation *words;
    int numWords;
} SentenceTranslation;

void loadDictionary(WordTranslation *dictionary, int numWords) {
    FILE *file;
    char line[MAX_WORD_SIZE];
    int i = 0;

    file = fopen("dictionary.txt", "r");

    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    while (fscanf(file, "%s %s", line, dictionary[i].translation)!= EOF) {
        strcpy(dictionary[i].word, line);
        i++;
    }

    fclose(file);

    if (i!= numWords) {
        printf("Error: dictionary file contains incorrect number of words.\n");
        exit(1);
    }
}

void translateSentence(SentenceTranslation *sentence, WordTranslation *dictionary, int numWords) {
    char word[MAX_WORD_SIZE];
    int i, j;

    for (i = 0; i < sentence->numWords; i++) {
        strcpy(word, sentence->words[i].word);

        for (j = 0; j < numWords; j++) {
            if (strcmp(word, dictionary[j].word) == 0) {
                strcpy(sentence->words[i].translation, dictionary[j].translation);
                break;
            }
        }

        if (j == numWords) {
            strcpy(sentence->words[i].translation, "UNKNOWN");
        }
    }
}

int main() {
    SentenceTranslation input, output;
    WordTranslation dictionary[1000];

    loadDictionary(dictionary, 1000);

    printf("Enter a sentence to translate: ");
    scanf("%[^\n]", input.words[0].word);
    input.numWords = 1;
    input.words[0].translation[0] = '\0';

    translateSentence(&output, dictionary, 1000);

    printf("Translated sentence: %s\n", output.words[0].translation);

    return 0;
}