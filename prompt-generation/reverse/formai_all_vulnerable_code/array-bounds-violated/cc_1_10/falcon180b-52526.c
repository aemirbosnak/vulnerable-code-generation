//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_NUM_LINES 100000

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LEN];
    char *logFilePath = "log.txt";
    char *delimiter = " ";
    char *token;
    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;

    // Open the log file
    fp = fopen(logFilePath, "r");
    if (fp == NULL) {
        printf("Error: unable to open log file.\n");
        exit(1);
    }

    // Read the log file line by line
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        lineCount++;

        // Remove newline character from the end of the line
        if (line[strlen(line)-1] == '\n') {
            line[strlen(line)-1] = '\0';
        }

        // Split the line into words
        token = strtok(line, delimiter);
        while (token!= NULL) {
            wordCount++;
            charCount += strlen(token);
            token = strtok(NULL, delimiter);
        }
    }

    // Close the log file
    fclose(fp);

    // Print the summary
    printf("Log file analysis summary:\n");
    printf("Number of lines: %d\n", lineCount);
    printf("Number of words: %d\n", wordCount);
    printf("Number of characters: %d\n", charCount);

    return 0;
}