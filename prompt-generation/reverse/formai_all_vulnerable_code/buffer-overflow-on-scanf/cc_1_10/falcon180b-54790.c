//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define MAX_LINE_LEN 1000

int count_words(char *line) {
    int num_words = 0;
    char *word = strtok(line, " \t\n\r\f\v");
    while (word!= NULL) {
        // check if the word is valid (not too long)
        if (strlen(word) <= MAX_WORD_LEN) {
            num_words++;
        }
        word = strtok(NULL, " \t\n\r\f\v");
    }
    return num_words;
}

int count_lines(FILE *file) {
    char line[MAX_LINE_LEN];
    int num_lines = 0;
    while (fgets(line, MAX_LINE_LEN, file)!= NULL) {
        num_lines++;
    }
    return num_lines;
}

int count_chars(FILE *file) {
    char line[MAX_LINE_LEN];
    int num_chars = 0;
    while (fgets(line, MAX_LINE_LEN, file)!= NULL) {
        num_chars += strlen(line);
    }
    return num_chars;
}

int main() {
    char filename[MAX_LINE_LEN];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    int num_words = count_words(fgets(filename, MAX_LINE_LEN, file));
    int num_lines = count_lines(file);
    int num_chars = count_chars(file);

    fclose(file);

    printf("Number of words: %d\n", num_words);
    printf("Number of lines: %d\n", num_lines);
    printf("Number of characters: %d\n", num_chars);

    return 0;
}