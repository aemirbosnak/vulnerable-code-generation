//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    FILE *file;
    char filename[MAX_LENGTH];
    char userInput[MAX_LENGTH];
    char savedData[MAX_LENGTH];
    int numLines = 0;

    printf("Enter file name: ");
    scanf("%s", filename);

    // Open the file for writing
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open file.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter some text to save to the file (type 'quit' to stop):\n");

    while (1) {
        printf("> ");
        scanf("%s", userInput);

        if (strcmp(userInput, "quit") == 0) {
            break;
        }

        fprintf(file, "%s\n", userInput);
        numLines++;
    }

    // Close the file after writing
    fclose(file);

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        exit(EXIT_FAILURE);
    }

    printf("\nData saved to file:\n");

    while (fscanf(file, "%s", savedData) != EOF) {
        printf("%s\n", savedData);
    }

    // Close the file after reading
    fclose(file);

    printf("\nNumber of lines saved: %d", numLines);

    return EXIT_SUCCESS;
}