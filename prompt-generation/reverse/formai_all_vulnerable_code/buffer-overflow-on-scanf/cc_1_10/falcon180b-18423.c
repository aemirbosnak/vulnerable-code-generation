//Falcon-180B DATASET v1.0 Category: File handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_FILE_NAME_SIZE 50

typedef struct {
    char name[MAX_FILE_NAME_SIZE];
    FILE *file;
} File;

int main() {
    char line[MAX_LINE_SIZE];
    File file;
    char file_name[MAX_FILE_NAME_SIZE];
    int i = 0;
    int line_count = 0;
    int char_count = 0;
    int word_count = 0;

    // Open the file for reading
    printf("Enter the name of the file to read: ");
    scanf("%s", file_name);
    file.file = fopen(file_name, "r");
    if (file.file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read the file line by line
    while (fgets(line, MAX_LINE_SIZE, file.file)!= NULL) {
        line_count++;
        char_count += strlen(line);
        word_count += count_words(line);
    }

    // Close the file
    fclose(file.file);

    // Print the results
    printf("Line count: %d\n", line_count);
    printf("Character count: %d\n", char_count);
    printf("Word count: %d\n", word_count);

    return 0;
}

// Function to count the number of words in a line
int count_words(char *line) {
    int count = 0;
    char *word = strtok(line, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}