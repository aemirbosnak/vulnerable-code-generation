//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to count words in a string
int countWords(char* str) {
    int count = 0;
    char* token = strtok(str, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Function to count lines in a file
int countLines(FILE* file) {
    int count = 0;
    char ch = fgetc(file);
    while (ch!= EOF) {
        if (ch == '\n') {
            count++;
        }
        ch = fgetc(file);
    }
    count++; // Count the last line
    return count;
}

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int lines = countLines(file);
    int words = countWords(NULL); // Initialize to 0

    rewind(file);
    char line[1000];
    while (fgets(line, sizeof(line), file)!= NULL) {
        words += countWords(line);
    }

    printf("Total number of lines: %d\n", lines);
    printf("Total number of words: %d\n", words);

    fclose(file);
    return 0;
}