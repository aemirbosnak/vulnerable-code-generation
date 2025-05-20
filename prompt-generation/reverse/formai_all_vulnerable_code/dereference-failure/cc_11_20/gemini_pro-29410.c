//GEMINI-pro DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[255];
    char buffer[255];
    int choice;

    // Menu
    do {
        printf("\n\nFile Handling Operations Menu\n");
        printf("----------------------------\n");
        printf("1. Create a New File\n");
        printf("2. Open an Existing File\n");
        printf("3. Write to a File\n");
        printf("4. Read from a File\n");
        printf("5. Append to a File\n");
        printf("6. Close a File\n");
        printf("7. Exit\n");
        printf("\nYour choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the filename to create: ");
                scanf("%s", filename);
                fp = fopen(filename, "w");  // "w" opens a file for writing
                if (fp == NULL) {
                    printf("Error opening file %s!\n", filename);
                } else {
                    printf("File %s created successfully!\n", filename);
                    fclose(fp);          // Always close a file after using it
                }
                break;

            case 2:
                printf("Enter the filename to open: ");
                scanf("%s", filename);
                fp = fopen(filename, "r");  // "r" opens a file for reading
                if (fp == NULL) {
                    printf("Error opening file %s!\n", filename);
                } else {
                    printf("File %s opened successfully!\n", filename);
                }
                break;

            case 3:
                printf("Enter the filename to open for writing: ");
                scanf("%s", filename);
                fp = fopen(filename, "w");  // "w" opens a file for writing
                if (fp == NULL) {
                    printf("Error opening file %s!\n", filename);
                } else {
                    printf("Enter the text to write to the file: ");
                    fgets(buffer, 255, stdin);  // Read a line of text from the standard input
                    fputs(buffer, fp);          // Write the line to the file
                    printf("Text written to file %s successfully!\n", filename);
                }
                break;

            case 4:
                printf("Enter the filename to open for reading: ");
                scanf("%s", filename);
                fp = fopen(filename, "r");  // "r" opens a file for reading
                if (fp == NULL) {
                    printf("Error opening file %s!\n", filename);
                } else {
                    printf("Contents of file %s:\n", filename);
                    while (fgets(buffer, 255, fp)) {  // Read a line of text from the file
                        printf("%s", buffer);         // Print the line
                    }
                }
                break;

            case 5:
                printf("Enter the filename to open for appending: ");
                scanf("%s", filename);
                fp = fopen(filename, "a");  // "a" opens a file for appending
                if (fp == NULL) {
                    printf("Error opening file %s!\n", filename);
                } else {
                    printf("Enter the text to append to the file: ");
                    fgets(buffer, 255, stdin);  // Read a line of text from the standard input
                    fputs(buffer, fp);          // Write the line to the file
                    printf("Text appended to file %s successfully!\n", filename);
                }
                break;

            case 6:
                printf("Enter the filename to close: ");
                scanf("%s", filename);
                if (fclose(fp)) {
                    printf("File %s closed successfully!\n", filename);
                } else {
                    printf("Error closing file %s!\n", filename);
                }
                break;

            case 7:
                printf("Exiting the program...\n");
                return 0;
        }
    } while (choice != 7);

    return 0;
}