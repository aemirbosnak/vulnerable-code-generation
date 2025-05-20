//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordFrequency;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int compare(const void *a, const void *b) {
    WordFrequency *wf1 = (WordFrequency *)a;
    WordFrequency *wf2 = (WordFrequency *)b;
    return wf2->count - wf1->count; // Sort by descending frequency
}

int main() {
    FILE *file;
    char filename[100];
    char text[10000];
    WordFrequency frequencies[MAX_WORDS];
    int wordCount = 0;

    printf("Enter the text file name (with extension) to summarize: ");
    scanf("%s", filename);
    
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the whole file into text buffer
    fread(text, sizeof(char), sizeof(text), file);
    fclose(file);

    // Tokenize the text and count word frequencies
    char *token = strtok(text, " \n\t.,;:!?\"()[]{}<>");
    while (token != NULL) {
        toLowerCase(token);
        
        int found = 0;

        // Check if word already exists in frequencies
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(frequencies[i].word, token) == 0) {
                frequencies[i].count++;
                found = 1;
                break;
            }
        }

        // If not found, add new word
        if (!found && wordCount < MAX_WORDS) {
            strncpy(frequencies[wordCount].word, token, MAX_WORD_LEN);
            frequencies[wordCount].count = 1;
            wordCount++;
        }

        token = strtok(NULL, " \n\t.,;:!?\"()[]{}<>");
    }

    // Sort frequencies by count
    qsort(frequencies, wordCount, sizeof(WordFrequency), compare);
    
    // Display the summary
    printf("\n---- Text Summary ----\n");
    printf("Word\tFrequency\n");
    printf("----------------------\n");
    
    for (int i = 0; i < wordCount && i < 10; i++) { // Display top 10 words
        printf("%s\t%d\n", frequencies[i].word, frequencies[i].count);
    }

    return EXIT_SUCCESS;
}