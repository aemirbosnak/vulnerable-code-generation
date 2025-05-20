//Gemma-7B DATASET v1.0 Category: File handling ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    FILE *fp;
    char filename[20], data[1024], command[20], ch;

    printf("Welcome to the retro file handling system!\n");

    // Get the file name
    printf("Enter file name: ");
    scanf("%s", filename);

    // Open the file
    fp = fopen(filename, "r");

    // Check if the file is open
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    // Get the command
    printf("Enter command (read/write/close): ");
    scanf("%s", command);

    // Execute the command
    switch (command[0])
    {
        case 'r':
            // Read data from the file
            printf("Enter data: ");
            scanf("%s", data);
            fprintf(fp, "%s", data);
            break;
        case 'w':
            // Write data to the file
            printf("Enter data: ");
            scanf("%s", data);
            fprintf(fp, "%s", data);
            break;
        case 'c':
            // Close the file
            fclose(fp);
            break;
        default:
            printf("Invalid command.\n");
    }

    // Close the file
    fclose(fp);

    // Thank you
    printf("Thank you for using the retro file handling system!\n");
}