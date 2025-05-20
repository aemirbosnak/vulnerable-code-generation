//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define DELIMITER ','

void readCSV(const char *filename);
void processLine(char *line);

int main() {
    char filename[100];

    // Let’s begin our journey by asking for a filename
    printf("Welcome to the CSV Reader! Please enter the CSV filename (including .csv extension): ");
    scanf("%s", filename);

    // Time to read the CSV file
    readCSV(filename);

    return 0;
}

void readCSV(const char *filename) {
    FILE *file = fopen(filename, "r");
    
    // Oh no! What if the file fails to open?
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];

    // Reading the file line by line
    while (fgets(line, sizeof(line), file)) {
        processLine(line); // Let’s process what we’ve just read!
    }

    // Always a good idea to close the file when done
    fclose(file);
    printf("Finished reading the CSV file.\n");
}

void processLine(char *line) {
    char *token;
    int columnNumber = 0;

    // We’ll start processing each line using the delimiter we defined
    token = strtok(line, ",\n");
    
    while (token != NULL) {
        // What if we want to do something with each token?
        printf("Column %d: %s\n", columnNumber, token);
        
        // Seek the next token
        token = strtok(NULL, ",\n");
        columnNumber++;
    } 
}