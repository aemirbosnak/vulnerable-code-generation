//Falcon-180B DATASET v1.0 Category: Text processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024 // Maximum length of a line in the input file
#define MAX_WORD_LENGTH 32 // Maximum length of a word to be counted

// Function to remove trailing white space from a string
void remove_trailing_space(char *str) {
    int i;
    for (i = strlen(str) - 1; i >= 0; i--) {
        if (isspace(str[i])) {
            str[i] = '\0';
        } else {
            break;
        }
    }
}

// Function to count the number of words in a line
int count_words(char *line) {
    int count = 0;
    char *word = strtok(line, " \t\n\r\f\v.,:;!?()[]{}<>");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " \t\n\r\f\v.,:;!?()[]{}<>");
    }
    return count;
}

// Function to count the number of lines in the input file
int count_lines(FILE *fp) {
    int count = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        count++;
    }
    return count;
}

// Function to count the number of words in the input file
int count_words_in_file(FILE *fp) {
    int count = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        count += count_words(line);
    }
    return count;
}

int main() {
    FILE *fp;
    char filename[256];

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open input file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    // Count number of lines and words in the input file
    int num_lines = count_lines(fp);
    int num_words = count_words_in_file(fp);

    // Close input file
    fclose(fp);

    // Print results
    printf("Number of lines: %d\n", num_lines);
    printf("Number of words: %d\n", num_words);
    printf("Average words per line: %.2f\n", (float)num_words / num_lines);

    return 0;
}