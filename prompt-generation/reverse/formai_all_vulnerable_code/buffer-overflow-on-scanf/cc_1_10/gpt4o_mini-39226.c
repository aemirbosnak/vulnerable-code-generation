//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 100

// Function prototypes
void readCSV(const char *filename);
void parseLine(char *line);
void printData(char fields[MAX_FIELDS][MAX_FIELD_LENGTH], int fieldCount);

int main() {
    char filename[MAX_FIELD_LENGTH];

    printf("Welcome to the CSV Reader!\n");
    printf("Please enter the CSV filename you want to read (e.g., data.csv): ");
    scanf("%s", filename);

    readCSV(filename);

    return 0;
}

void readCSV(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    printf("Reading data from %s...\n", filename);
    printf("Here’s what we found:\n");

    while (fgets(line, sizeof(line), file)) {
        parseLine(line);
    }

    fclose(file);
    printf("Finished reading the file. Thank you for using the CSV Reader!\n");
}

void parseLine(char *line) {
    char fields[MAX_FIELDS][MAX_FIELD_LENGTH];
    int fieldCount = 0;
    char *token = strtok(line, ",");

    while (token != NULL && fieldCount < MAX_FIELDS) {
        strncpy(fields[fieldCount], token, MAX_FIELD_LENGTH - 1);
        fields[fieldCount][MAX_FIELD_LENGTH - 1] = '\0'; // Ensure null termination
        fieldCount++;
        token = strtok(NULL, ",");
    }

    // Print the parsed data
    printData(fields, fieldCount);
}

void printData(char fields[MAX_FIELDS][MAX_FIELD_LENGTH], int fieldCount) {
    for (int i = 0; i < fieldCount; i++) {
        printf("Field %d: %s\n", i + 1, fields[i]);
    }
    printf("\n");
}