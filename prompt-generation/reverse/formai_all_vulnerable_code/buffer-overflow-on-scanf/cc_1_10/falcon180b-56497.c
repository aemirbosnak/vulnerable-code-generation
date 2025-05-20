//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 100

// Define a structure to store word frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

// Function to read a text file and count word frequencies
void readFile(FILE *file, WordFrequency *wordFrequencies, int numWords) {
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int i, j, k;

    for (i = 0; i < numWords; i++) {
        wordFrequencies[i].frequency = 0;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        for (j = 0; j < strlen(line); j++) {
            if (isspace(line[j])) {
                k = 0;
                while (j < strlen(line) &&!isspace(line[j])) {
                    word[k++] = tolower(line[j++]);
                }
                word[k] = '\0';

                for (int l = 0; l < numWords; l++) {
                    if (strcmp(word, wordFrequencies[l].word) == 0) {
                        wordFrequencies[l].frequency++;
                        break;
                    }
                }
            }
        }
    }
}

// Function to display word frequencies
void displayFrequencies(WordFrequency *wordFrequencies, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
}

int main() {
    FILE *file;
    char filename[100];
    WordFrequency wordFrequencies[10];
    int numWords;

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");

    // Check if file was opened successfully
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Read file and count word frequencies
    readFile(file, wordFrequencies, 10);

    // Display word frequencies
    printf("\nWord frequencies:\n");
    displayFrequencies(wordFrequencies, 10);

    // Close file
    fclose(file);

    return 0;
}