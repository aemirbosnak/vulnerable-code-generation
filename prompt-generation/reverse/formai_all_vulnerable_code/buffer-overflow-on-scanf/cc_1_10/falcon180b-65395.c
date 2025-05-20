//Falcon-180B DATASET v1.0 Category: Error handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main() {
    FILE *input_file;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    char delimiter;
    int count = 0;
    int total_words = 0;
    int max_word_length = 0;
    int longest_word_length = 0;
    char longest_word[MAX_LINE_LENGTH];

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    input_file = fopen(filename, "r");

    if (input_file == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }

    printf("Enter the delimiter character: ");
    scanf(" %c", &delimiter);

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        char *word = strtok(line, delimiter);
        while (word!= NULL) {
            count++;
            total_words++;

            int word_length = strlen(word);
            if (word_length > max_word_length) {
                max_word_length = word_length;
            }

            if (word_length > longest_word_length) {
                strcpy(longest_word, word);
                longest_word_length = word_length;
            }

            word = strtok(NULL, delimiter);
        }
    }

    fclose(input_file);

    printf("Total number of words: %d\n", total_words);
    printf("Average word length: %.2f\n", (float)total_words / count);
    printf("Longest word: %s\n", longest_word);
    printf("Longest word length: %d\n", longest_word_length);

    return 0;
}