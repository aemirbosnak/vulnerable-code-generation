//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void loadWords(char *filename, WordFrequency words[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    int numWords = 0;
    while (fscanf(file, "%s", words[numWords].word)!= EOF) {
        numWords++;
        if (numWords >= MAX_WORDS) {
            printf("Error: too many words in file '%s'\n", filename);
            exit(1);
        }
    }

    fclose(file);
}

void generateSentence(WordFrequency words[], int numWords, int maxSentenceLength) {
    srand(time(NULL));

    char sentence[maxSentenceLength + 1];
    sentence[0] = '\0';

    int currentWordIndex = rand() % numWords;
    strcat(sentence, words[currentWordIndex].word);

    int numWordsInSentence = 1;
    while (numWordsInSentence < maxSentenceLength && currentWordIndex < numWords - 1) {
        currentWordIndex = (currentWordIndex + rand() % (numWords - currentWordIndex - 1)) % numWords;
        if (isspace(words[currentWordIndex].word[0])) {
            strcat(sentence, " ");
        } else {
            strcat(sentence, words[currentWordIndex].word);
        }
        numWordsInSentence++;
    }

    printf("%s\n", sentence);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <word_frequency_file> <max_sentence_length>\n", argv[0]);
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    loadWords(argv[1], words);

    int maxSentenceLength = atoi(argv[2]);

    while (1) {
        generateSentence(words, MAX_WORDS, maxSentenceLength);
    }

    return 0;
}