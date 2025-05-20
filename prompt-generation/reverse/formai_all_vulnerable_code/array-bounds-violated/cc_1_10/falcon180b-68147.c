//Falcon-180B DATASET v1.0 Category: File handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

int main() {
    FILE *file;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    int total_words = 0;
    int total_letters = 0;
    int total_sentences = 0;
    int current_sentence_words = 0;
    int in_word = 0;

    printf("Enter filename: ");
    fgets(filename, MAX_LINE_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_number++;
        total_letters += strlen(line);

        if (line[strlen(line) - 1] == '.') {
            total_sentences++;
        }

        current_sentence_words = 0;
        in_word = 0;

        for (int i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                in_word = 1;
            } else if (in_word &&!isspace(line[i])) {
                continue;
            } else if (in_word) {
                in_word = 0;
                current_sentence_words++;
            }
        }

        total_words += current_sentence_words;
    }

    printf("Total lines: %d\n", line_number);
    printf("Total words: %d\n", total_words);
    printf("Total letters: %d\n", total_letters);
    printf("Total sentences: %d\n", total_sentences);

    fclose(file);
    return 0;
}