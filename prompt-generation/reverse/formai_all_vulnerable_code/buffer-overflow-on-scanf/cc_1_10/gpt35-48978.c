//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_SIZE 256

// Function to check if a given string is a digit
int isDigit(char* str) {
    for (int i=0; i<strlen(str); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

// Function to read a line from a CSV file
int readLine(FILE* file, char* line) {
    int index = 0;
    char c;
    while ((c = fgetc(file)) != EOF && c != '\n' && index < MAX_LINE_SIZE-1) {
        line[index++] = c;
    }
    line[index] = '\0';
    return index;
}

// Function to read a field from a line in a CSV file
int readField(char* line, int index, char* field) {
    int fieldIndex = 0;
    char c = line[index];
    while (c != ',' && c != '\0' && fieldIndex < MAX_FIELD_SIZE-1) {
        field[fieldIndex++] = c;
        c = line[++index];
    }
    field[fieldIndex] = '\0';
    return index;
}

// Main function to parse and read CSV file
int main() {
    char fileName[MAX_FIELD_SIZE];
    printf("Enter the CSV file name: ");
    scanf("%s", fileName);
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Could not read file %s\n", fileName);
        return 1;
    }
    char line[MAX_LINE_SIZE];
    while (readLine(file, line) > 0) {
        int index = 0;
        char field[MAX_FIELD_SIZE];
        while (readField(line, index, field) > 0) {
            if (isDigit(field)) {
                printf("%d,", atoi(field));
            } else {
                printf("'%s',", field);
            }
            index += strlen(field) + 1;
        }
        printf("\n");
    }
    fclose(file);
    return 0;
}