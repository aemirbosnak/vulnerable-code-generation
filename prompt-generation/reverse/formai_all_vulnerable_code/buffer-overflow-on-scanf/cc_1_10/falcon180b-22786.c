//Falcon-180B DATASET v1.0 Category: File handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1000
#define MAX_WORD_SIZE 50

// Function prototypes
void read_file(char *filename);
void display_file(char *filename);
void count_words(char *filename);

int main() {
    char filename[MAX_LINE_SIZE];
    char input[MAX_LINE_SIZE];

    printf("Enter filename: ");
    scanf("%s", filename);

    read_file(filename);
    display_file(filename);
    count_words(filename);

    return 0;
}

// Function to read file
void read_file(char *filename) {
    FILE *file;
    char line[MAX_LINE_SIZE];
    int line_count = 0;

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        line_count++;
        printf("%d: %s", line_count, line);
    }

    fclose(file);
}

// Function to display file
void display_file(char *filename) {
    FILE *file;
    char line[MAX_LINE_SIZE];
    int line_count = 0;

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        line_count++;
        printf("%d: %s", line_count, line);
    }

    fclose(file);
}

// Function to count words
void count_words(char *filename) {
    FILE *file;
    char line[MAX_LINE_SIZE];
    int word_count = 0;

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        word_count += count_words_in_line(line);
    }

    printf("Total word count: %d\n", word_count);

    fclose(file);
}

// Function to count words in a line
int count_words_in_line(char *line) {
    int word_count = 0;
    char *word;

    word = strtok(line, " ");
    while (word!= NULL) {
        word_count++;
        word = strtok(NULL, " ");
    }

    return word_count;
}