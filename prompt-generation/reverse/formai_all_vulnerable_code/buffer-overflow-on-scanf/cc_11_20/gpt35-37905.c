//FormAI DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000 // Maximum string length

int main() {
    FILE *file; // Pointer to file
    char filename[MAX_LEN], mode[4], text[MAX_LEN]; // File name, mode of operation and text to be written or read
    int choice, num_chars;

    // Ask user for file name and mode of operation
    printf("Enter file name: ");
    fgets(filename, MAX_LEN, stdin);

    // Remove newline character from filename
    filename[strcspn(filename, "\n")] = '\0';

    printf("Enter mode (r for reading, w for writing, a for appending): ");
    scanf("%s", mode);

    // Open file in specified mode
    if(strcmp(mode, "r") == 0) {
        file = fopen(filename, "r");

        if(file == NULL) {
            printf("File not found.\n");
            exit(1);
        }

        // Read and print the contents of file
        printf("\nFile contents:\n\n");

        while(fgets(text, MAX_LEN, file)) {
            printf("%s", text);
        }

        fclose(file);
    } else if(strcmp(mode, "w") == 0) {
        file = fopen(filename, "w");

        if(file == NULL) {
            printf("Unable to create file.\n");
            exit(1);
        }

        // Ask user for text to be written to file
        printf("\nEnter text to be written to file:\n");
        scanf(" %[^\n]s", text);

        // Write text to file
        fprintf(file, "%s", text);
        printf("\nText written to file successfully.\n");

        fclose(file);
    } else if(strcmp(mode, "a") == 0) {
        file = fopen(filename, "a");

        if(file == NULL) {
            printf("Unable to open file.\n");
            exit(1);
        }

        // Ask user for text to be appended to file
        printf("\nEnter text to be appended to file:\n");
        scanf(" %[^\n]s", text);

        // Append text to file
        fprintf(file, "%s", text);
        printf("\nText appended to file successfully.\n");

        fclose(file);
    } else {
        printf("Invalid mode.\n");
        exit(1);
    }

    // Ask user if they want to count number of characters in file
    printf("\nDo you want to count the number of characters in the file (0 for no, 1 for yes)? ");
    scanf("%d", &choice);

    if(choice == 1) {
        file = fopen(filename, "r");

        if(file == NULL) {
            printf("File not found.\n");
            exit(1);
        }

        // Count number of characters in file
        num_chars = 0;

        while(fgets(text, MAX_LEN, file)) {
            num_chars += strlen(text);
        }

        printf("\nNumber of characters in file: %d\n", num_chars);

        fclose(file);
    }

    return 0;
}