//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Structure to store file information
typedef struct {
    char filename[50];  // File name
    int fileSize;      // File size in bytes
    int numLines;     // Number of lines in the file
    int avgLineLen;  // Average line length
    int maxLineLen;  // Maximum line length
} FileInfo;

// Function to open a file and read its information
FileInfo readFileInfo(char *filename) {
    FileInfo fi;
    int fp;

    // Open the file in read mode
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return fi;
    }

    // Get the file size
    fi.fileSize = ftell(fp);
    if (fi.fileSize < 0) {
        perror("Error getting file size");
        fclose(fp);
        return fi;
    }

    // Read the file into a buffer
    char *buffer = (char *)malloc(fi.fileSize + 1);
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return fi;
    }
    fread(buffer, 1, fi.fileSize, fp);
    buffer[fi.fileSize] = '\0';

    // Count the number of lines and compute the average line length
    fi.numLines = countLines(buffer);
    fi.avgLineLen = computeAvgLineLen(buffer);
    fi.maxLineLen = computeMaxLineLen(buffer);

    // Close the file
    fclose(fp);

    return fi;
}

// Function to count the number of lines in a buffer
int countLines(char *buffer) {
    int lineCount = 0;
    for (int i = 0; i < strlen(buffer); i++) {
        if (buffer[i] == '\n') {
            lineCount++;
        }
    }
    return lineCount;
}

// Function to compute the average line length
int computeAvgLineLen(char *buffer) {
    int sum = 0;
    for (int i = 0; i < strlen(buffer); i++) {
        if (buffer[i] != '\n') {
            sum++;
            sum += (int)buffer[i];
        }
    }
    return sum / (strlen(buffer) - 1);
}

// Function to compute the maximum line length
int computeMaxLineLen(char *buffer) {
    int maxLen = 0;
    for (int i = 0; i < strlen(buffer); i++) {
        if (buffer[i] != '\n') {
            if (maxLen < (int)buffer[i]) {
                maxLen = (int)buffer[i];
            }
        }
    }
    return maxLen;
}

int main() {
    char filename[] = "example.txt";
    FileInfo fi = readFileInfo(filename);
    printf("File Information:\n");
    printf("Filename: %s\n", fi.filename);
    printf("File size: %d bytes\n", fi.fileSize);
    printf("Number of lines: %d\n", fi.numLines);
    printf("Average line length: %d\n", fi.avgLineLen);
    printf("Maximum line length: %d\n", fi.maxLineLen);
    return 0;
}