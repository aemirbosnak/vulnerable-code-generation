//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000
#define FILE_NAME "love_poem.txt"

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

// A function to compare two words for qsort
int compare(const void *a, const void *b) {
    WordCount *word1 = (WordCount *)a;
    WordCount *word2 = (WordCount *)b;
    return strcmp(word1->word, word2->word);
}

// A love letter in the form of a poem
void writeLovePoem() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file) {
        fprintf(file, 
            "Oh, love, like the sun, bright and warm,\n"
            "In your gaze, I find shelter from the storm.\n"
            "Each whispered word, a tender embrace,\n"
            "In the dance of souls, we find our grace.\n\n"
            "Together we soar like birds on the wing,\n"
            "In laughter and joy, our hearts gently sing.\n"
            "Through the trials and the dreams that we weave,\n"
            "In the tapestry of life, it’s love that we believe.\n\n"
            "So let us write our story in stars above,\n"
            "With words like petals, blooming in love.\n"
            "For every heart that beats in time,\n"
            "Is a fleeting moment, a perfect rhyme.\n");
        fclose(file);
    } else {
        printf("Could not write the love poem...\n");
    }
}

// A function to count frequency of each word in a text file
void countWordFrequencies() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("Could not open the love poem for reading...\n");
        return;
    }

    WordCount words[MAX_WORDS];
    int numWords = 0;

    char buffer[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", buffer) != EOF) {
        // Convert the word to lowercase for uniformity
        for (int i = 0; buffer[i]; i++) {
            buffer[i] = tolower(buffer[i]);
        }

        // Check if the word already exists
        int found = 0;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(words[i].word, buffer) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        
        // If it is a new word, add it to the list
        if (!found && numWords < MAX_WORDS) {
            strcpy(words[numWords].word, buffer);
            words[numWords].count = 1;
            numWords++;
        }
    }

    fclose(file);

    // Sort the words in alphabetical order
    qsort(words, numWords, sizeof(WordCount), compare);

    // Display the word frequencies with romantic flair
    printf("Oh sweet words of love, let us count your whispers:\n\n");
    for (int i = 0; i < numWords; i++) {
        printf("  '%s' : %d times\n", words[i].word, words[i].count);
    }
}

int main() {
    // Create a romantic love poem
    writeLovePoem();
    
    // Count the words and display their frequencies
    countWordFrequencies();

    printf("\nIn every word, there lies a heartbeat...\n");
    printf("Forever entwined in the dance of love.\n");

    return 0;
}