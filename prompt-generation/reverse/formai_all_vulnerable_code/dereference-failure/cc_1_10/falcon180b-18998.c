//Falcon-180B DATASET v1.0 Category: File handling ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024

// Function to remove leading and trailing white spaces from a string
void trim(char* str) {
    char* end;
    if (str == NULL)
        return;
    end = str + strlen(str) - 1;
    while (isspace(*end))
        end--;
    *(end + 1) = '\0';
    while (isspace(*str))
        str++;
}

// Function to split a string into words
char* split(char* str, char delimiter) {
    char* token = strtok(str, delimiter);
    return token;
}

// Function to count the number of words in a string
int countWords(char* str) {
    int count = 0;
    char* token = strtok(str, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Function to read a file and count the number of words in it
void countWordsInFile(FILE* file, char* filename) {
    char line[MAX_LINE_SIZE];
    int numWords = 0;
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        trim(line);
        if (strlen(line) > 0) {
            numWords += countWords(line);
        }
    }
    printf("Total number of words in %s: %d\n", filename, numWords);
}

int main() {
    char filename[MAX_LINE_SIZE];
    printf("Enter the name of the file to count words: ");
    fgets(filename, MAX_LINE_SIZE, stdin);
    trim(filename);
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    countWordsInFile(file, filename);
    fclose(file);
    return 0;
}