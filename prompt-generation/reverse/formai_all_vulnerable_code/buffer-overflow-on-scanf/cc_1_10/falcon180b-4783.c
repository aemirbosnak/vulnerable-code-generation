//Falcon-180B DATASET v1.0 Category: File handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_SIZE 1000000

// Struct to hold file information
typedef struct {
    char filename[100];
    int num_lines;
    int num_words;
    int num_chars;
} FileInfo;

// Function to count lines, words, and characters in a file
void countFileStats(FILE *file, FileInfo *info) {
    char line[MAX_LINE_LENGTH];
    char word[100];
    int chars = 0;
    int words = 0;
    int lines = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        lines++;
        chars += strlen(line);
        memset(word, '\0', sizeof(word));
        strtok(line, " ");
        while (strtok(NULL, " ")!= NULL) {
            words++;
        }
    }

    info->num_lines = lines;
    info->num_words = words;
    info->num_chars = chars;
}

// Function to read a file and print its contents
void printFileContents(FILE *file) {
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        printf("%s", line);
    }
}

// Function to write a file
void writeToFile(FILE *file, char *data) {
    fprintf(file, "%s", data);
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found.\n");
        return 1;
    }

    FileInfo info;
    countFileStats(file, &info);
    printf("Number of lines: %d\n", info.num_lines);
    printf("Number of words: %d\n", info.num_words);
    printf("Number of characters: %d\n", info.num_chars);

    printFileContents(file);

    fclose(file);

    return 0;
}