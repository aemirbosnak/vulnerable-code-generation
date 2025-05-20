//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 80
#define MAX_LINE_LENGTH 1024

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int word_count = 0;
    int line_count = 0;
    int letter_count = 0;
    int word_length_count = 0;
    int longest_word_length = 0;
    int shortest_word_length = MAX_WORD_LENGTH;

    printf("Enter the filename: ");
    scanf("%s", line);

    file = fopen(line, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_count++;
        letter_count += strlen(line);

        char *token = strtok(line, " ");
        while (token!= NULL) {
            word_count++;

            int word_length = strlen(token);
            if (word_length > longest_word_length) {
                longest_word_length = word_length;
            }
            if (word_length < shortest_word_length) {
                shortest_word_length = word_length;
            }

            word_length_count += word_length;
            token = strtok(NULL, " ");
        }
    }

    fclose(file);

    printf("Number of lines: %d\n", line_count);
    printf("Number of words: %d\n", word_count);
    printf("Number of letters: %d\n", letter_count);
    printf("Average word length: %.2f\n", (double)word_length_count / word_count);
    printf("Shortest word length: %d\n", shortest_word_length);
    printf("Longest word length: %d\n", longest_word_length);

    return 0;
}