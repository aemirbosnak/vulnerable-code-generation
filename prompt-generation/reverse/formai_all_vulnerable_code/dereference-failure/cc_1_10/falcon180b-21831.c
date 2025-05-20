//Falcon-180B DATASET v1.0 Category: Text processing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define MAX_WORD_COUNT 1024

// Function to count words in a line
int countWords(char *line) {
    int count = 0;
    char *word;
    char *context = line;
    while ((word = strtok_r(context, " ", &context))!= NULL) {
        if (strlen(word) > 0) {
            count++;
        }
    }
    return count;
}

// Function to print word count for each line
void printWordCount(char *line) {
    int count = countWords(line);
    printf("Word count for line '%s': %d\n", line, count);
}

// Function to print total word count
void printTotalWordCount(int count) {
    printf("Total word count: %d\n", count);
}

// Function to read file and count words
int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int total_word_count = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        total_word_count += countWords(line);
        printWordCount(line);
    }

    fclose(file);
    printTotalWordCount(total_word_count);

    return 0;
}