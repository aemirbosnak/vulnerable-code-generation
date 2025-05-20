//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Function to remove whitespace from a string
void removeWhitespace(char* str) {
    int i = 0;
    while (str[i]!= '\0') {
        if (!isspace(str[i])) {
            str[i] = tolower(str[i]);
            i++;
        } else {
            str[i] = '\0';
        }
    }
}

// Function to count the frequency of a word in a string
int countFrequency(char* str, char* word) {
    int count = 0;
    char* token;
    token = strtok(str, " ");
    while (token!= NULL) {
        if (strcmp(token, word) == 0) {
            count++;
        }
        token = strtok(NULL, " ");
    }
    return count;
}

// Function to print the frequency of a word in a string
void printFrequency(char* word, int freq) {
    printf("%s: %d\n", word, freq);
}

// Function to analyze a log file
void analyzeLogFile(FILE* fp) {
    char line[1024];
    char* word;
    int freq;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        removeWhitespace(line);
        word = strtok(line, " ");
        while (word!= NULL) {
            freq = countFrequency(line, word);
            printFrequency(word, freq);
            word = strtok(NULL, " ");
        }
    }
}

int main() {
    char filename[100];
    printf("Enter the name of the log file: ");
    scanf("%s", filename);

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    analyzeLogFile(fp);

    fclose(fp);
    return 0;
}