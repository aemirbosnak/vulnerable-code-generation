//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: irregular
// Our backup system, a bit of a mess but it works!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The main function, where the magic happens
int main() {

    // Lets start with a pinch of file handling
    FILE *source, *target;

    // Define our input and output files
    char source_file[100], target_file[100];

    // Ask the user for the file names
    printf("Enter the name of the file to be backed up: ");
    scanf("%s", source_file);
    printf("Enter the name of the backup file: ");
    scanf("%s", target_file);

    // Open the input file in read mode
    source = fopen(source_file, "r");
    if (source == NULL) {
        printf("Error opening the source file!");
        return -1;
    }

    // Open the output file in write mode
    target = fopen(target_file, "w");
    if (target == NULL) {
        printf("Error opening the target file!");
        fclose(source);
        return -1;
    }

    // Time to do some character juggling
    char ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, target);
    }

    // All done, close the files
    fclose(source);
    fclose(target);

    // A little message of success (or not)
    printf("File backed up successfully (hopefully)! \n");

    return 0;
}