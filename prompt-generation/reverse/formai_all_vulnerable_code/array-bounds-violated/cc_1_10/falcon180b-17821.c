//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define struct for CSV data
typedef struct {
    char *data;
    int row;
    int col;
} CSVData;

// Function to split a string by delimiter
char **split(char *str, char delimiter) {
    int len = strlen(str);
    int count = 0;
    char **result = malloc(sizeof(char *) * (len + 1));
    char *token = strtok(str, delimiter);
    while (token!= NULL) {
        result[count++] = token;
        token = strtok(NULL, delimiter);
    }
    result[count] = NULL;
    return result;
}

// Function to read CSV file
CSVData *readCSV(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    CSVData *data = malloc(sizeof(CSVData));
    data->data = NULL;
    data->row = 0;
    data->col = 0;
    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }
        char **tokens = split(line, ',');
        int numTokens = countTokens(tokens);
        if (data->data == NULL) {
            data->data = malloc(sizeof(char *) * numTokens);
            data->row = numTokens;
        } else if (numTokens!= data->row) {
            printf("Error: inconsistent number of columns\n");
            exit(1);
        }
        for (int i = 0; i < numTokens; i++) {
            data->data[i] = tokens[i];
        }
        free(tokens);
        data->col++;
    }
    if (data->data == NULL) {
        printf("Error: empty file\n");
        exit(1);
    }
    fclose(file);
    return data;
}

// Function to count number of tokens
int countTokens(char **tokens) {
    int count = 0;
    while (tokens[count]!= NULL) {
        count++;
    }
    return count;
}

// Function to print CSV data
void printCSV(CSVData *data) {
    for (int i = 0; i < data->row; i++) {
        for (int j = 0; j < data->col; j++) {
            printf("%s ", data->data[i * data->col + j]);
        }
        printf("\n");
    }
}

// Function to free CSV data
void freeCSV(CSVData *data) {
    for (int i = 0; i < data->row; i++) {
        free(data->data[i * data->col]);
    }
    free(data->data);
    free(data);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    CSVData *data = readCSV(argv[1]);
    printCSV(data);
    freeCSV(data);
    return 0;
}