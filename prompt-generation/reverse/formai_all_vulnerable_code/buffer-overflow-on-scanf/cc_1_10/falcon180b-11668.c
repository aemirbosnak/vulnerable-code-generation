//Falcon-180B DATASET v1.0 Category: File handling ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_FILE_NAME_SIZE 100

typedef struct {
    FILE *file;
    char filename[MAX_FILE_NAME_SIZE];
} File;

int main() {
    File file;
    char line[MAX_LINE_SIZE];
    char input[MAX_LINE_SIZE];
    char *token;
    int i = 0;

    // Open the file for reading
    printf("Enter the filename: ");
    scanf("%s", file.filename);
    file.file = fopen(file.filename, "r");

    if (file.file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    // Read the file line by line
    while (fgets(line, MAX_LINE_SIZE, file.file)!= NULL) {
        // Remove the newline character from the end of the line
        line[strcspn(line, "\n")] = '\0';

        // Count the number of words in the line
        int num_words = 0;
        token = strtok(line, " ");
        while (token!= NULL) {
            num_words++;
            token = strtok(NULL, " ");
        }

        // Print the line and its word count
        printf("%d: %s\n", i++, line);
        printf("Number of words: %d\n", num_words);
        printf("\n");
    }

    // Close the file
    fclose(file.file);

    return 0;
}