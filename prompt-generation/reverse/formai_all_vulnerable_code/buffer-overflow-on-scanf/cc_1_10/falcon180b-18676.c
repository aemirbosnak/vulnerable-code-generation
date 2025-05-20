//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_FILE_SIZE 1000000

// Function to count words in a string
int count_words(char *str) {
    int count = 0;
    char *word = strtok(str, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// Function to read a file and count the words
int read_file(char *filename, int *word_count, int *line_count, int *char_count) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int in_word = 0;
    int c;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    *word_count = 0;
    *line_count = 0;
    *char_count = 0;

    while ((c = fgetc(fp))!= EOF) {
        if (c == '\n') {
            (*line_count)++;
        }
        if (isspace(c)) {
            in_word = 0;
        } else {
            in_word = 1;
        }
        if (in_word) {
            (*char_count)++;
            if (*char_count > MAX_FILE_SIZE) {
                printf("Error: File is too large.\n");
                fclose(fp);
                exit(1);
            }
        }
    }
    if (in_word) {
        (*word_count)++;
    }
    fclose(fp);
    return 0;
}

int main() {
    char filename[MAX_LINE_LENGTH];
    int word_count, line_count, char_count;

    printf("Enter the name of the file to count words: ");
    scanf("%s", filename);

    read_file(filename, &word_count, &line_count, &char_count);

    printf("Number of words: %d\n", word_count);
    printf("Number of lines: %d\n", line_count);
    printf("Number of characters: %d\n", char_count);

    return 0;
}