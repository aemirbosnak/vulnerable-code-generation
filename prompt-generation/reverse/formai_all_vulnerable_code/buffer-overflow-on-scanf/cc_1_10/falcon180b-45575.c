//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 32
#define MAX_HISTORY_LENGTH 100

// function prototypes
void read_file(char *filename);
void tokenize_line(char *line);
void process_word(char *word);
void add_to_history(char *word);
void print_history();

char *history[MAX_HISTORY_LENGTH];
int history_length = 0;

int main() {
    char filename[MAX_LINE_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    read_file(filename);
    return 0;
}

void read_file(char *filename) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *word;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        tokenize_line(line);
    }

    fclose(file);
}

void tokenize_line(char *line) {
    char *word;
    char *delimiters = " \t\n\r\f.?!;:\"'()[]{}<>";

    word = strtok(line, delimiters);
    while (word!= NULL) {
        process_word(word);
        word = strtok(NULL, delimiters);
    }
}

void process_word(char *word) {
    int length = strlen(word);

    if (length > MAX_WORD_LENGTH) {
        printf("Error: word is too long.\n");
        return;
    }

    add_to_history(word);
}

void add_to_history(char *word) {
    if (history_length >= MAX_HISTORY_LENGTH) {
        printf("Error: history is full.\n");
        return;
    }

    strcpy(history[history_length++], word);
}

void print_history() {
    int i;

    for (i = 0; i < history_length; i++) {
        printf("%s ", history[i]);
    }
    printf("\n");
}