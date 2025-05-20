//Gemma-7B DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char filename[256];
    FILE *fp;
    int choice;

    // Get the file name from the user
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    // Open the file
    fp = fopen(filename, "r");

    // Check if the file is open
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    // Display the file contents
    printf("File contents:\n");
    while (1)
    {
        char line[256];
        int lines = 0;

        // Read a line from the file
        fgets(line, 256, fp);

        // Check if the line is empty
        if (line[0] == '\0')
        {
            break;
        }

        // Print the line
        printf("%s\n", line);

        lines++;
    }

    // Close the file
    fclose(fp);

    // Ask the user if they want to continue
    printf("Do you want to continue? (Y/N): ");
    scanf("%c", &choice);

    // Check if the user wants to continue
    if (choice == 'Y')
    {
        main();
    }

    return 0;
}