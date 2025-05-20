//FormAI DATASET v1.0 Category: Word Count Tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILE_NAME 100
#define MAX_WORD_SIZE 50
#define MAX_LINE_SIZE 1024

// Function to read a line from a file and return it as a string
char* read_line(FILE* fp) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read = 0;
    read = getline(&line, &len, fp);
    if (read == -1) {
        free(line);
        return NULL;
    }
    return line;
}

// Function to count words in a line and add it to the total word count
int count_words(char* line, int* total_words) {
    int count = 0;
    char* word = strtok(line, " \t\n\r\f\v");
    while (word != NULL) {
        count++;
        word = strtok(NULL, " \t\n\r\f\v");
    }
    *total_words += count;
    return count;
}

int main() {
    char file_name[MAX_FILE_NAME];
    char* line;
    int total_words = 0;

    printf("Enter file name: ");
    scanf("%s", file_name);

    // Open file for reading
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        return 1;
    }

    // Read the file line by line and count the words
    while ((line = read_line(fp)) != NULL) {
        count_words(line, &total_words);
        free(line);
    }

    // Close the file and print the total word count
    fclose(fp);
    printf("Total words in file: %d\n", total_words);
    return 0;
}