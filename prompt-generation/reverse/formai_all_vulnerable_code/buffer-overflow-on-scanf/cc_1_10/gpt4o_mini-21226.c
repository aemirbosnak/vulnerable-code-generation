//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_LINES 1000

void to_uppercase(char *line) {
    for (int i = 0; line[i]; i++) {
        line[i] = toupper(line[i]);
    }
}

void to_lowercase(char *line) {
    for (int i = 0; line[i]; i++) {
        line[i] = tolower(line[i]);
    }
}

void reverse_line(char *line) {
    int len = strlen(line);
    for (int i = 0; i < len / 2; i++) {
        char temp = line[i];
        line[i] = line[len - i - 1];
        line[len - i - 1] = temp;
    }
}

void count_words_and_characters(char *line, int *word_count, int *char_count) {
    char *token;
    *char_count += strlen(line);
    
    token = strtok(line, " \n\t");
    while (token != NULL) {
        (*word_count)++;
        token = strtok(NULL, " \n\t");
    }
}

void operate_on_lines(char lines[MAX_LINES][MAX_LINE_LENGTH], int line_count) {
    for (int i = 0; i < line_count; i++) {
        // Remove new line character if present
        lines[i][strcspn(lines[i], "\n")] = 0;

        // Example operations on the lines
        printf("Original Line: %s\n", lines[i]);

        // Uppercase conversion
        char upper_line[MAX_LINE_LENGTH];
        strcpy(upper_line, lines[i]);
        to_uppercase(upper_line);
        printf("Uppercase Line: %s\n", upper_line);

        // Lowercase conversion
        char lower_line[MAX_LINE_LENGTH];
        strcpy(lower_line, lines[i]);
        to_lowercase(lower_line);
        printf("Lowercase Line: %s\n", lower_line);

        // Reversed line
        char reversed_line[MAX_LINE_LENGTH];
        strcpy(reversed_line, lines[i]);
        reverse_line(reversed_line);
        printf("Reversed Line: %s\n", reversed_line);

        // Word and character counting
        int word_count = 0, char_count = 0;
        count_words_and_characters(lines[i], &word_count, &char_count);
        printf("Word Count: %d, Character Count: %d\n", word_count, char_count);
        
        printf("------------------------------------\n");
    }
}

int main() {
    FILE *file;
    char filename[100];
    char lines[MAX_LINES][MAX_LINE_LENGTH];
    int line_count = 0;
    
    printf("Enter the filename to read: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (fgets(lines[line_count], MAX_LINE_LENGTH, file) != NULL) {
        line_count++;
        if (line_count >= MAX_LINES) {
            printf("Maximum line count reached. Only reading first %d lines.\n", MAX_LINES);
            break;
        }
    }
    
    fclose(file);

    printf("Processing %d lines from %s:\n", line_count, filename);
    operate_on_lines(lines, line_count);
    
    return EXIT_SUCCESS;
}