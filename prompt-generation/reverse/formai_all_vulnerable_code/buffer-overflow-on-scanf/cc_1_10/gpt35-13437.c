//FormAI DATASET v1.0 Category: Spell checking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum dictionary size
#define MAX_DICTIONARY_SIZE 10000

// Define maximum word length
#define MAX_WORD_LENGTH 100

// Define struct for dictionary word
typedef struct Word {
    char word[MAX_WORD_LENGTH];
} Word;

// Define function to read words from dictionary file into array
int readDictionary(Word dictionary[]) {
    int wordCount = 0;
    char filename[] = "dictionary.txt";
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Could not open file %s", filename);
        return 0;
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        // Remove newline character from end of line
        line[strcspn(line, "\r\n")] = 0;

        // Copy word from line into dictionary array
        strcpy(dictionary[wordCount].word, line);
        wordCount++;
    }

    fclose(file);
    return wordCount;
}

// Define function to check if a given word is in the dictionary
int checkWord(char word[], Word dictionary[], int dictionarySize) {
    for (int i = 0; i < dictionarySize; i++) {
        // If a match is found, return true
        if (strcmp(word, dictionary[i].word) == 0) {
            return 1;
        }
    }
    // If no match is found, return false
    return 0;
}

// Define function to check spelling of user input
void spellCheck() {
    Word dictionary[MAX_DICTIONARY_SIZE];
    int dictionarySize = readDictionary(dictionary);

    printf("Spell Checker\n");
    printf("------------------------------\n");

    char input[MAX_WORD_LENGTH];
    while (1) {
        printf("Enter a word (or 'q' to quit): ");
        scanf("%s", input);

        // If user enters 'q', exit the loop
        if (strcmp(input, "q") == 0) {
            break;
        }

        // Convert input to lowercase for case-insensitive comparison
        for (size_t i = 0; i < strlen(input); i++) {
            input[i] = tolower(input[i]);
        }

        // Check if word is in the dictionary
        if (checkWord(input, dictionary, dictionarySize)) {
            printf("%s is spelled correctly!\n", input);
        } else {
            printf("%s is not in the dictionary. Did you mean?\n", input);

            // Check for possible corrections
            for (int i = 0; i < dictionarySize; i++) {
                // Check if the first letter of the dictionary word matches the input word
                if (dictionary[i].word[0] == input[0]) {
                    // Calculate edit distance between dictionary word and input word
                    int distance = editDistance(input, dictionary[i].word);

                    // If edit distance is less than or equal to 2, suggest correction
                    if (distance <= 2) {
                        printf(" - %s\n", dictionary[i].word);
                    }
                }
            }
        }
    }
}

// Define function to calculate Levenshtein distance (edit distance) between two strings
int editDistance(char s1[], char s2[]) {
    int n1 = strlen(s1);
    int n2 = strlen(s2);

    int matrix[n1+1][n2+1];

    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            // If one of the strings is empty, distance is length of other string
            if (i == 0) {
                matrix[i][j] = j;
            } else if (j == 0) {
                matrix[i][j] = i;
            } else {
                // Otherwise, calculate min of three values
                int cost = 0;
                if (s1[i-1] != s2[j-1]) {
                    cost = 1;
                }
                matrix[i][j] = min(
                    matrix[i-1][j] + 1,
                    matrix[i][j-1] + 1,
                    matrix[i-1][j-1] + cost);
            }
        }
    }

    return matrix[n1][n2];
}

// Define function to calculate the min of three integer values
int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

// Define main function to run spell checking program
int main() {
    spellCheck();
    return 0;
}