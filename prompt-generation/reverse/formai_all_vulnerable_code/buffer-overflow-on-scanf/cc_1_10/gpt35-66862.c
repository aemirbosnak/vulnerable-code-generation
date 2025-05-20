//FormAI DATASET v1.0 Category: HTML beautifier ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Function to check if a character is a whitespace character
int isWhitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

// Function to copy a string up until a specific character
void copyUntil(char* src, char* dest, char ch) {
    int i = 0;
    while (src[i] != ch && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Function to remove leading whitespace from a string
void removeLeadingWhitespace(char* line) {
    int j = 0;
    while (isWhitespace(line[j])) {
        j++;
    }
    int i = 0;
    while (line[j] != '\0') {
        line[i] = line[j];
        i++;
        j++;
    }
    line[i] = '\0';
}

// Function to remove trailing whitespace from a string
void removeTrailingWhitespace(char *line) {
    int i = 0;
    while (line[i] != '\0') {
        i++;
    }
    i--;
    while (isWhitespace(line[i])) {
        i--;
    }
    line[i+1] = '\0';
}

int main() {
    char inputFilename[100];
    printf("Enter filename with html code: ");
    scanf("%s", inputFilename);
    FILE* inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        printf("Error: Unable to open file %s", inputFilename);
        return 1;
    }
    char outputFilename[100];
    printf("Enter filename to save formatted code: ");
    scanf("%s", outputFilename);
    FILE* outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        printf("Error: Unable to open file %s", outputFilename);
        return 1;
    }

    // Read from file line by line
    char line[1000];
    int inTag = 0;
    int indentation = 0;
    while (fgets(line, sizeof(line), inputFile)) {
        removeLeadingWhitespace(line);
        removeTrailingWhitespace(line);
        if (line[0] == '<') {
            inTag = 1;
            if (line[1] == '/') {
                indentation--;
            }
            for (int i = 0; i < indentation; i++) {
                fprintf(outputFile, "    ");
            }
            fprintf(outputFile, "%s", line);
            if (line[strlen(line) - 2] != '/') {
                indentation++;
            }
        }
        else if (inTag && line[0] != '<') {
            for (int i = 0; i < indentation; i++) {
                fprintf(outputFile, "    ");
            }
            fprintf(outputFile, "%s", line);
        }
        else {
            fprintf(outputFile, "%s", line);
        }
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("Code has been formatted and saved to %s", outputFilename);

    return 0;
}