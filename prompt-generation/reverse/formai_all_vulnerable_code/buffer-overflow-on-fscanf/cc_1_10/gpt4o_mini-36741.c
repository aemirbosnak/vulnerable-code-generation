//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// A structure to hold words and their frequencies
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

// A function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// A function to search for a word in the array of word frequencies
int findWord(WordFrequency *wordFreqs, int numWords, const char *word) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(wordFreqs[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

// The main function where the magic begins
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Could not open file");
        return 1;
    }
    
    WordFrequency wordFreqs[MAX_WORDS];
    int numWords = 0;
    char word[MAX_WORD_LENGTH];

    // The enchanting journey through the text
    while (fscanf(file, "%s", word) == 1) {
        toLowerCase(word); // Transform to lowercase
        
        // Remove punctuation from the word
        char *ptr = word;
        while (*ptr) {
            if (ispunct((unsigned char)*ptr)) {
                *ptr = '\0'; // Replace punctuation with a string terminator
                break;
            }
            ptr++;
        }

        // Avoid counting empty strings
        if(strlen(word) > 0) {
            int index = findWord(wordFreqs, numWords, word);
            if (index == -1) {
                strcpy(wordFreqs[numWords].word, word);
                wordFreqs[numWords].count = 1;
                numWords++;
            } else {
                wordFreqs[index].count++;
            }
        }
    }
    
    fclose(file);

    // The list of words and their frequency to share with the world
    printf("Word Frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFreqs[i].word, wordFreqs[i].count);
    }

    // An invitation to disseminate the knowledge!
    printf("\nDo you wish to save this data into a file? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        FILE *outputFile = fopen("word_frequencies.txt", "w");
        if (outputFile == NULL) {
            perror("Could not open output file");
            return 1;
        }
        for (int i = 0; i < numWords; i++) {
            fprintf(outputFile, "%s: %d\n", wordFreqs[i].word, wordFreqs[i].count);
        }
        fclose(outputFile);
        printf("Words have been saved to 'word_frequencies.txt'.\n");
    } else {
        printf("The data remains transient, much like a whisper in the wind...\n");
    }

    return 0;
}