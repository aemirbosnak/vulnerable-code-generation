//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void loveLetter() {
    printf("Ah, my dearest reader,\n");
    printf("Beneath the canvas of this mortal world, I present you with a humble creation,\n");
    printf("An ode to the beauty of words, a frequency counter, to unveil hidden truths.\n\n");
}

void whisperGoodbye() {
    printf("As we part ways, remember, my cherished companion,\n");
    printf("The power of words can sway the heart, \n");
    printf("Count them wisely, for in their essence lies romance.\n");
}

int findWordIndex(WordFrequency *words, char *word, int totalWords) {
    for (int i = 0; i < totalWords; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void addWord(WordFrequency *words, char *word, int *totalWords) {
    int index = findWordIndex(words, word, *totalWords);
    if (index != -1) {
        words[index].count++;
    } else {
        strcpy(words[*totalWords].word, word);
        words[*totalWords].count = 1;
        (*totalWords)++;
    }
}

void displayFrequencies(WordFrequency *words, int totalWords) {
    printf("\nOh, the sweet melody of words, their frequency unveiled:\n");
    for (int i = 0; i < totalWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

void romanceInWords(FILE *file, WordFrequency *words, int *totalWords) {
    char buffer[MAX_WORD_LENGTH];
    
    while (fscanf(file, "%s", buffer) != EOF) {
        // Remove punctuation from the end of the word
        char *cleaned = strtok(buffer, ".,!?;:\"\n");
        if (cleaned) {
            addWord(words, cleaned, totalWords);
        }
    }
}

int main() {
    loveLetter();
    
    WordFrequency words[MAX_WORDS];
    int totalWords = 0;

    char filename[] = "love_poem.txt";
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Oh no, my love! The pages of our tale are lost...\n");
        return 1;
    }

    romanceInWords(file, words, &totalWords);
    fclose(file);

    displayFrequencies(words, totalWords);
    whisperGoodbye();

    return 0;
}