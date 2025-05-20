//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1000

// Function to read a line of text from the input file
void readLine(FILE *fp, char *buffer) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF && ch!= '\n') {
        buffer[i++] = ch;
    }
    buffer[i] = '\0';
}

// Function to write a line of text to the output file
void writeLine(FILE *fp, char *buffer) {
    fprintf(fp, "%s", buffer);
}

// Function to reverse the order of words in a line of text
void reverseWords(char *buffer) {
    char *start = buffer;
    char *end = buffer + strlen(buffer) - 1;
    while (start < end) {
        char *wordStart = start;
        while (isspace(*(start++))) {}
        char *wordEnd = start - 1;
        while (!isspace(*(end--))) {}
        char *temp = wordStart;
        while (temp < wordEnd) {
            char tempChar = *temp;
            *temp = *end;
            *end-- = tempChar;
            temp++;
        }
        start = wordEnd + 1;
    }
}

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_LINE];

    // Open input file for reading
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Open output file for writing
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(inputFile);
        exit(2);
    }

    // Loop through input file and reverse order of words
    while (fgets(line, MAX_LINE, inputFile)!= NULL) {
        reverseWords(line);
        writeLine(outputFile, line);
    }

    // Close input and output files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}