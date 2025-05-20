//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000

char *read_line(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        printf("Error reading file\n");
        exit(1);
    }
    return line;
}

int is_word(char *word) {
    int length = strlen(word);
    if (length == 0 || length > MAX_WORD_LENGTH) {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (!isalnum(word[i])) {
            return 0;
        }
    }
    return 1;
}

void count_words(FILE *file) {
    char *line = read_line(file);
    int word_count = 0;
    while (line!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            if (is_word(word)) {
                word_count++;
            }
            word = strtok(NULL, " ");
        }
        line = read_line(file);
    }
    printf("Total word count: %d\n", word_count);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    count_words(file);
    fclose(file);
    return 0;
}