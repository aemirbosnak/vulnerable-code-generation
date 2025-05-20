//FormAI DATASET v1.0 Category: File handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    FILE *fp;
    char filename[MAX_SIZE];
    char text[MAX_SIZE];

    printf("Enter the filename to read from: ");
    scanf("%s", filename);
    printf("\n");

    // Open the file for reading
    fp = fopen(filename, "r");

    // If file does not exist, prompt error message and exit
    if (fp == NULL) {
        printf("Error: File '%s' does not exist or unable to open!\n", filename);
        return 1;
    }

    // Read the file line by line and print to console
    printf("Contents of file:\n\n");
    while (fgets(text, MAX_SIZE, fp) != NULL) {
        printf("%s", text);
    }

    // Close the file
    fclose(fp);

    // Prompt user for new filename to create or write to
    printf("\nEnter the filename to create or write to: ");
    scanf("%s", filename);
    printf("\n");

    // Open the file for writing
    fp = fopen(filename, "w");

    // If file does not exist, prompt error message and exit
    if (fp == NULL) {
        printf("Error: Unable to create or open file '%s'!\n", filename);
        return 1;
    }

    // Prompt user for input text to write to file
    printf("Enter your text. Press Ctrl+D to save and exit.\n\n");
    while (fgets(text, MAX_SIZE, stdin) != NULL) {
        fprintf(fp, "%s", text);
    }

    // Close the file
    fclose(fp);

    printf("Operation successful: Data written to file '%s'!\n\n", filename);

    return 0;
}