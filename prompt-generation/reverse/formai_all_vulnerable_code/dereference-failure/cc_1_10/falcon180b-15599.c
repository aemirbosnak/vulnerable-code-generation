//Falcon-180B DATASET v1.0 Category: File handling ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_LENGTH 100

// Function to read a line from the file
char *readLine(FILE *fp) {
    char *line = NULL;
    char ch;
    int len = 0;

    // Read the first character
    ch = fgetc(fp);
    if (ch == EOF) {
        line = malloc(1);
        line[0] = '\0';
        return line;
    }

    // Read the rest of the line
    while (ch!= EOF && ch!= '\n') {
        if (len >= MAX_LINE_LENGTH) {
            printf("Error: Line too long\n");
            exit(1);
        }
        line = realloc(line, len + 2);
        line[len++] = ch;
        ch = fgetc(fp);
    }

    // Add the null terminator
    line = realloc(line, len + 1);
    line[len] = '\0';

    return line;
}

// Function to write a line to the file
void writeLine(FILE *fp, char *line) {
    fputs(line, fp);
    fputc('\n', fp);
}

// Function to reverse a line
void reverseLine(char *line) {
    char *start = line;
    char *end = line + strlen(line) - 1;
    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

int main() {
    FILE *inputFile, *outputFile;
    char *line;

    // Open the input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file\n");
        return 1;
    }

    // Open the output file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file\n");
        fclose(inputFile);
        return 2;
    }

    // Read each line from the input file and write it to the output file
    while ((line = readLine(inputFile))!= NULL) {
        reverseLine(line);
        writeLine(outputFile, line);
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}