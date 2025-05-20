//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void countWordsAndLines(const char *filename);
void toUpperCase(char *str);
void toLowerCase(char *str);
void replaceWord(char *str, const char *oldWord, const char *newWord);
void printFileContents(const char *filename);

int main() {
    const char *filename = "example.txt";

    // Print file contents
    printf("Contents of the file %s:\n", filename);
    printFileContents(filename);

    // Count words and lines
    countWordsAndLines(filename);

    // Read a sample string
    char sampleStr[256];
    printf("\nEnter a string to convert to upper case: ");
    fgets(sampleStr, sizeof(sampleStr), stdin);
    toUpperCase(sampleStr);
    printf("Upper case: %s", sampleStr);

    printf("\nEnter a string to convert to lower case: ");
    fgets(sampleStr, sizeof(sampleStr), stdin);
    toLowerCase(sampleStr);
    printf("Lower case: %s", sampleStr);

    char replaceStr[256];
    printf("\nEnter a string to perform word replacement: ");
    fgets(replaceStr, sizeof(replaceStr), stdin);
    replaceWord(replaceStr, "hello", "hi");
    printf("After replacement: %s", replaceStr);

    return 0;
}

void printFileContents(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    
    fclose(file);
}

void countWordsAndLines(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    int wordCount = 0, lineCount = 0;
    char word[100];

    while (fscanf(file, "%s", word) != EOF) {
        wordCount++;
    }

    // Reset the file pointer to start again for line counting
    rewind(file);
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        lineCount++;
    }

    printf("Total words: %d\n", wordCount);
    printf("Total lines: %d\n", lineCount);

    fclose(file);
}

void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = (str[i] >= 'a' && str[i] <= 'z') ? str[i] - 32 : str[i];
    }
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + 32 : str[i];
    }
}

void replaceWord(char *str, const char *oldWord, const char *newWord) {
    char buffer[256];
    char *pos;

    // Check if old word is present
    if ((pos = strstr(str, oldWord)) != NULL) {
        // Replace the old word with the new one
        strncpy(buffer, str, pos - str);
        buffer[pos - str] = '\0';
        sprintf(buffer + (pos - str), "%s%s", newWord, pos + strlen(oldWord));
        strcpy(str, buffer);
    }
}