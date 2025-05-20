//FormAI DATASET v1.0 Category: File handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100 // Define maximum string length

int main() {
    char filename[20], str[MAX_LENGTH], ch, choice;
    FILE *fp; // Declare file pointer

    printf("\nEnter the name of file: ");
    scanf("%s", filename); // Get file name

    // Check if file exists
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("\nFile \"%s\" does not exist. Would you like to create it? (y/n): ", filename);
        scanf(" %c", &choice);
        if (tolower(choice) == 'y') {
            fp = fopen(filename, "w"); // Create new file
            if (fp == NULL) {
                printf("\nError creating file \"%s\".", filename);
                exit(1);
            }
            else {
                printf("\nFile \"%s\" created successfully.", filename);
            }
        }
        else {
            printf("\nExiting program.\n");
            exit(0);
        }
    }
    else {
        printf("\nFile \"%s\" opened successfully.", filename);
    }

    // Ask for user input to write to file
    printf("\nEnter text to write to the file (max %d characters):\n", MAX_LENGTH);
    scanf(" %[^\n]s", str);

    // Write to file
    fprintf(fp, "%s", str);

    // Print file contents
    printf("\nFile contents:\n");
    rewind(fp); // Set file pointer to the beginning of the file
    while((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }

    // Close file
    fclose(fp);
    printf("\nFile \"%s\" closed successfully.\n", filename);

    return 0;
}