//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

// Function to read words from input file and store in array
void readWords(char *filename, char words[MAX_WORDS][MAX_WORD_LENGTH]) {
    FILE *fp;
    char word[MAX_WORD_LENGTH];
    int count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(words[count], word);
        count++;
    }

    fclose(fp);
}

// Function to translate English words to Alien language
void translateWords(char words[MAX_WORDS][MAX_WORD_LENGTH], char translated[MAX_WORDS][MAX_WORD_LENGTH]) {
    int i, j;
    for (i = 0; i < MAX_WORDS; i++) {
        if (strlen(words[i]) > 0) {
            // Convert first letter to uppercase and append "ay"
            translated[i][0] = toupper(words[i][0]);
            strcpy(&translated[i][1], "ay");
        } else {
            // Empty word, set to "way"
            strcpy(translated[i], "way");
        }
    }
}

// Function to write translated words to output file
void writeTranslatedWords(char translated[MAX_WORDS][MAX_WORD_LENGTH], char filename) {
    FILE *fp;
    int i;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    for (i = 0; i < MAX_WORDS; i++) {
        fprintf(fp, "%s\n", translated[i]);
    }

    fclose(fp);
}

int main() {
    char inputFilename[100], outputFilename[100];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    char translated[MAX_WORDS][MAX_WORD_LENGTH];

    // Prompt user for input and output filenames
    printf("Enter input filename: ");
    scanf("%s", inputFilename);
    printf("Enter output filename: ");
    scanf("%s", outputFilename);

    // Read words from input file
    readWords(inputFilename, words);

    // Translate words to Alien language
    translateWords(words, translated);

    // Write translated words to output file
    writeTranslatedWords(translated, outputFilename);

    printf("Translation complete!\n");
    return 0;
}