//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 80
#define MAX_ASCII_ART_LINES 1000

typedef struct {
    char *line;
    int length;
} ASCIIArtLine;

ASCIIArtLine asciiArtLines[MAX_ASCII_ART_LINES];
int numAsciiArtLines;

void addAsciiArtLine(char *line) {
    if (numAsciiArtLines >= MAX_ASCII_ART_LINES) {
        printf("Error: Too many ASCII art lines.\n");
        exit(1);
    }
    asciiArtLines[numAsciiArtLines].line = line;
    asciiArtLines[numAsciiArtLines].length = strlen(line);
    numAsciiArtLines++;
}

void printAsciiArt() {
    if (numAsciiArtLines == 0) {
        printf("No ASCII art lines to print.\n");
        return;
    }
    int maxLineLength = 0;
    for (int i = 0; i < numAsciiArtLines; i++) {
        if (asciiArtLines[i].length > maxLineLength) {
            maxLineLength = asciiArtLines[i].length;
        }
    }
    for (int i = 0; i < numAsciiArtLines; i++) {
        printf("%s", asciiArtLines[i].line);
        for (int j = asciiArtLines[i].length; j < maxLineLength; j++) {
            printf(" ");
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text file>\n", argv[0]);
        exit(1);
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int lineLength = strlen(line);
        if (lineLength > MAX_LINE_LENGTH) {
            printf("Error: Line too long.\n");
            exit(1);
        }
        line[lineLength - 1] = '\0'; // Remove newline character
        addAsciiArtLine(line);
    }
    fclose(file);
    printAsciiArt();
    return 0;
}