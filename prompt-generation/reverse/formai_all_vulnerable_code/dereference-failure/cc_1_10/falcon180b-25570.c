//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_LINE_LENGTH 1000

char *extract_word(char *line, int word_index) {
    char *word = malloc(MAX_WORD_LENGTH * sizeof(char));
    int i = 0;
    int word_length = 0;

    while (i < strlen(line) && word_index > 0) {
        if (isalnum(line[i])) {
            word[word_length] = tolower(line[i]);
            word_length++;
            word_index--;
        }
        i++;
    }

    word[word_length] = '\0';
    return word;
}

void print_line_numbers(FILE *file) {
    int line_number = 1;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        printf("%d: %s", line_number, line);
        line_number++;
    }
}

void print_words(char *word, int word_count) {
    printf("%s: %d\n", word, word_count);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage:./program file.txt\n");
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char *word;
    int word_count = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        word_count = 0;
        while ((word = extract_word(line, word_count))!= NULL) {
            printf("%s\n", word);
            word_count++;
        }
    }

    fclose(file);
    return 0;
}