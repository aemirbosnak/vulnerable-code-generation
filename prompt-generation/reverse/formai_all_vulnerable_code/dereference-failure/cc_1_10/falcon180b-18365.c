//Falcon-180B DATASET v1.0 Category: Text processing ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 100

char *read_line(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH * sizeof(char));
    if (line == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for line.\n");
        exit(1);
    }
    fgets(line, MAX_LINE_LENGTH, file);
    return line;
}

void process_line(char *line, int (*callback)(char *)) {
    char *word = strtok(line, " ");
    while (word!= NULL) {
        callback(word);
        word = strtok(NULL, " ");
    }
}

int count_words(char *word) {
    int count = 0;
    if (strlen(word) > MAX_WORD_LENGTH) {
        fprintf(stderr, "Error: Word is too long.\n");
        return -1;
    }
    count++;
    return count;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file.\n");
        return 1;
    }
    int total_words = 0;
    process_line(read_line(file), &count_words);
    printf("Total words: %d\n", total_words);
    fclose(file);
    return 0;
}