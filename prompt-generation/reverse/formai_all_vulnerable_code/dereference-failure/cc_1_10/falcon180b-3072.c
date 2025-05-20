//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: calm
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_FILE_SIZE 1000000

// Function to count the number of words in a line
int count_words(char *line) {
    int count = 0;
    char *word = strtok(line, ",.?!;:");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, ",.?!;:");
    }
    return count;
}

// Function to read a line from the file
char *read_line(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        printf("Error: File read failed.\n");
        exit(1);
    }
    return line;
}

// Function to write the word count to the output file
void write_count(FILE *output, int count) {
    fprintf(output, "%d\n", count);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    // Open input and output files
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Error: Input file not found.\n");
        exit(1);
    }
    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        printf("Error: Output file creation failed.\n");
        exit(1);
    }

    // Loop through each line in the input file
    int total_count = 0;
    char *line = read_line(input);
    while (line!= NULL) {
        int count = count_words(line);
        total_count += count;
        write_count(output, count);
        line = read_line(input);
    }

    // Close input and output files
    fclose(input);
    fclose(output);

    // Print total word count
    printf("Total word count: %d\n", total_count);

    return 0;
}