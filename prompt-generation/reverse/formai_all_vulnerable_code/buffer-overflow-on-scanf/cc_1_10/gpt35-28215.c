//FormAI DATASET v1.0 Category: File handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the File Handling Example Program!\n");

    // Create a file pointer and a filename string
    FILE *fp;
    char filename[20];

    // Ask user for filename and open the file for appending in write mode
    printf("Please enter the name of the file you wish to create or append to: ");
    scanf("%s", filename);
    fp = fopen(filename, "a+");

    // If the file pointer is null, then there was an error opening the file
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Ask user for input to write to the file
    int numLines;
    printf("How many lines of input do you want to write to the file? ");
    scanf("%d", &numLines);
    getchar(); // consume newline character left in input buffer

    // Loop through and write each line to the file
    char input[100];
    for (int i = 0; i < numLines; i++) {
        printf("Enter line %d of input: ", i+1);
        fgets(input, sizeof(input), stdin);
        fprintf(fp, "%s", input);
    }

    // Close the file
    fclose(fp);

    // Reopen the file for reading and print its contents
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Print out each line in the file
    printf("The contents of the file are:\n");
    char c = fgetc(fp);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(fp);
    }

    // Close the file and exit the program
    fclose(fp);
    printf("\nProgram complete.\n");

    return 0;
}