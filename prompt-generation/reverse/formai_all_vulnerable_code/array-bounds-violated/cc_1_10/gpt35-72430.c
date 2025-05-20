//FormAI DATASET v1.0 Category: Spell checking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_DICT_SIZE 50000

// Define a struct for each word in the dictionary
typedef struct DictWord {
    char word[MAX_WORD_LEN];
} DictWord;

// Declare global variables
DictWord dictionary[MAX_DICT_SIZE];
int dictSize = 0;

// Function to read in the dictionary file
void readDictionary() {
    FILE *fp;
    char line[MAX_WORD_LEN];

    fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open dictionary file\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LEN, fp) != NULL) {
        // Remove newline character from end of line
        int lineLen = strlen(line);
        if (line[lineLen-1] == '\n') {
            line[lineLen-1] = '\0';
        }

        // Copy word into dictionary
        strcpy(dictionary[dictSize].word, line);
        dictSize++;
    }

    fclose(fp);
}

// Function to check if a given word is in the dictionary
int checkWord(char *word) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check a given file for spelling errors and output them to a separate file
void checkFile(char *filename) {
    FILE *fp;
    FILE *outFp;
    char line[MAX_WORD_LEN];
    int lineNum = 1;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    // Create output file with name "[filename]_checked.txt"
    char outFilename[MAX_WORD_LEN+13];
    strcpy(outFilename, filename);
    strcat(outFilename, "_checked.txt");
    outFp = fopen(outFilename, "w");
    if (outFp == NULL) {
        printf("Error: Could not create output file\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LEN, fp) != NULL) {
        // Remove newline character from end of line
        int lineLen = strlen(line);
        if (line[lineLen-1] == '\n') {
            line[lineLen-1] = '\0';
        }

        char *token = strtok(line, " ");
        while (token != NULL) {
            // Remove any punctuation from the token
            int tokenLen = strlen(token);
            if (token[tokenLen-1] == '.' || token[tokenLen-1] == ',' || token[tokenLen-1] == ':' || token[tokenLen-1] == ';') {
                token[tokenLen-1] = '\0';
            }
            tokenLen = strlen(token);
            if (token[0] == '(' || token[0] == '[' || token[0] == '{') {
                for (int i = 0; i < tokenLen; i++) {
                    token[i] = token[i+1];
                }
            }
            if (token[tokenLen-1] == ')' || token[tokenLen-1] == ']' || token[tokenLen-1] == '}') {
                token[tokenLen-1] = '\0';
            }

            if (!checkWord(token)) {
                fprintf(outFp, "Line %d: %s\n", lineNum, token);
            }

            token = strtok(NULL, " ");
        }

        lineNum++;
    }

    fclose(fp);
    fclose(outFp);

    // Print message indicating completion
    printf("File %s has been checked and the errors have been written to %s\n", filename, outFilename);
}

int main() {
    // Read in dictionary
    readDictionary();

    // Check a sample file for spelling errors
    checkFile("sample.txt");

    return 0;
}