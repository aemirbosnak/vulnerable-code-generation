//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_FILE_NAME_SIZE 20
#define MAX_ROW_SIZE 1024

typedef struct CsvParser {
    char *fileName;
    char row[MAX_ROW_SIZE];
} CsvParser;

int getCsvColumnCount(const char *csvRow) {
    int count = 0;
    for (int i = 0; i < strlen(csvRow); i++) {
        if (csvRow[i] == ',') count++;
    }
    return count + 1;
}

void parseCsvRow(char *csvRow, char **row) {
    int i, j;
    i = 0;
    j = 0;

    while (csvRow[i] != '\0') {
        if (csvRow[i] == ',') {
            row[j][i % MAX_ROW_SIZE] = '\0';
            j++;
            i++;
        }
        row[j][i % MAX_ROW_SIZE] = csvRow[i];
        i++;
    }
    row[j][i % MAX_ROW_SIZE] = '\0';
}

int readCsvFile(CsvParser *csvParser) {
    FILE *file = fopen(csvParser->fileName, "r");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return -1;
    }
    while (fgets(csvParser->row, MAX_ROW_SIZE, file)) {
        char *csvRow[MAX_COLS];
        for (int i = 0; i < MAX_COLS; i++) {
            csvRow[i] = (char *) malloc(MAX_ROW_SIZE * sizeof(char));
        }
        
        int columnCount = getCsvColumnCount(csvParser->row);
        parseCsvRow(csvParser->row, csvRow);
        
        for (int i = 0; i < columnCount; i++) {
            printf("%s ", csvRow[i]);
        }
        
        printf("\n");
 
        for (int i = 0; i < MAX_COLS; i++) {
            free(csvRow[i]);
        }
    }
    fclose(file);
    return 0;
}

int main() {
    CsvParser csvParser;
    printf("Enter CSV file name: ");
    scanf("%s", csvParser.fileName);
    readCsvFile(&csvParser);
    return 0;
}