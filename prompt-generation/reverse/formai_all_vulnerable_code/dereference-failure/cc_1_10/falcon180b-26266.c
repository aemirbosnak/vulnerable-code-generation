//Falcon-180B DATASET v1.0 Category: File handling ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_LINE_LENGTH 1000

// Function to remove leading and trailing spaces from a string
void removeSpaces(char* str) {
    int i = 0;
    while(isspace(str[i])) {
        i++;
    }
    int j = strlen(str) - 1;
    while(isspace(str[j])) {
        str[j] = '\0';
        j--;
    }
}

// Function to read a line from a file
char* readLine(FILE* file) {
    char* line = (char*) malloc(MAX_LINE_LENGTH * sizeof(char));
    char ch;
    int i = 0;
    while((ch = fgetc(file))!= EOF && ch!= '\n') {
        line[i++] = ch;
    }
    line[i] = '\0';
    return line;
}

// Function to count the number of words in a line
int countWords(char* line) {
    int count = 0;
    while(*line!= '\0') {
        if(isspace(*line)) {
            count++;
        }
        line++;
    }
    return count;
}

// Function to count the number of lines in a file
int countLines(FILE* file) {
    int count = 0;
    char* line = readLine(file);
    while(line!= NULL) {
        count++;
        free(line);
        line = readLine(file);
    }
    return count;
}

// Function to count the number of characters in a line
int countChars(char* line) {
    int count = 0;
    while(*line!= '\0') {
        if(!isspace(*line)) {
            count++;
        }
        line++;
    }
    return count;
}

// Function to print the statistics of a file
void printStats(FILE* file) {
    int numWords = 0;
    int numLines = countLines(file);
    int numChars = 0;
    char* line = readLine(file);
    while(line!= NULL) {
        numWords += countWords(line);
        numChars += countChars(line);
        free(line);
        line = readLine(file);
    }
    printf("Number of lines: %d\n", numLines);
    printf("Number of words: %d\n", numWords);
    printf("Number of characters: %d\n", numChars);
}

int main() {
    FILE* file;
    char* filename = "example.txt";
    file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    printStats(file);
    fclose(file);
    return 0;
}