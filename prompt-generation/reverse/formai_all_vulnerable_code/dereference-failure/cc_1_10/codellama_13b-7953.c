//Code Llama-13B DATASET v1.0 Category: File handling ; Style: inquisitive
/*
 * File Handling Example Program
 *
 * This program demonstrates the basic operations of file handling in C.
 *
 * Author: [Your Name]
 * Date:   [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare variables
    FILE *fp;
    char filename[100], buffer[100];
    int choice, i;

    // Prompt user for input
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    // Open file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return 1;
    }

    // Prompt user for choice
    printf("Enter the choice (1-4):\n");
    printf("1. Read from file\n");
    printf("2. Write to file\n");
    printf("3. Append to file\n");
    printf("4. Close file\n");
    scanf("%d", &choice);

    // Perform operation based on user choice
    switch (choice) {
        case 1:
            // Read from file
            fgets(buffer, 100, fp);
            printf("File contents: %s", buffer);
            break;
        case 2:
            // Write to file
            printf("Enter the string to write to file: ");
            scanf("%s", buffer);
            fprintf(fp, "%s", buffer);
            break;
        case 3:
            // Append to file
            printf("Enter the string to append to file: ");
            scanf("%s", buffer);
            fprintf(fp, "%s", buffer);
            break;
        case 4:
            // Close file
            fclose(fp);
            break;
        default:
            printf("Invalid choice\n");
    }

    // Close file
    fclose(fp);

    return 0;
}