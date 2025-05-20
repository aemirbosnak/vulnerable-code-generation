//Falcon-180B DATASET v1.0 Category: File handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

// Function to open and read a file
void read_file(FILE *file, char *buffer) {
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        strcat(buffer, line);
    }
}

// Function to write to a file
void write_file(FILE *file, char *buffer) {
    fprintf(file, "%s", buffer);
}

// Function to count words in a string
int count_words(char *str) {
    int count = 0;
    char *token = strtok(str, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

int main() {
    char input_file[50], output_file[50];
    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    FILE *input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char *buffer = (char *) malloc(MAX_LINE_SIZE * sizeof(char));
    read_file(input, buffer);
    fclose(input);

    int word_count = count_words(buffer);

    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    sprintf(buffer, "Word count: %d\n", word_count);
    write_file(output, buffer);

    fclose(output);

    printf("Word count written to %s.\n", output_file);

    return 0;
}