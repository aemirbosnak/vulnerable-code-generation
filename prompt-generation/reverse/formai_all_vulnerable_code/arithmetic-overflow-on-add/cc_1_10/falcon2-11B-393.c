//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char filename1[100];
    char filename2[100];
    FILE *file1, *file2;
    int filesize1, filesize2;
    char *buffer1, *buffer2;
    char *line1, *line2;
    int i, j;

    // Get the first file name
    printf("Enter the name of the first file: ");
    fgets(filename1, 100, stdin);

    // Get the second file name
    printf("Enter the name of the second file: ");
    fgets(filename2, 100, stdin);

    // Open the first file
    file1 = fopen(filename1, "r");
    if (file1 == NULL)
    {
        printf("Unable to open the file '%s'\n", filename1);
        exit(1);
    }

    // Open the second file
    file2 = fopen(filename2, "r");
    if (file2 == NULL)
    {
        printf("Unable to open the file '%s'\n", filename2);
        exit(1);
    }

    // Get the size of the first file
    fseek(file1, 0, SEEK_END);
    filesize1 = ftell(file1);
    rewind(file1);

    // Allocate memory for the buffer
    buffer1 = malloc(filesize1 + 1);
    if (buffer1 == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Read the first file into the buffer
    fread(buffer1, 1, filesize1, file1);

    // Get the size of the second file
    fseek(file2, 0, SEEK_END);
    filesize2 = ftell(file2);
    rewind(file2);

    // Allocate memory for the buffer
    buffer2 = malloc(filesize2 + 1);
    if (buffer2 == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Read the second file into the buffer
    fread(buffer2, 1, filesize2, file2);

    // Compare the two files line by line
    line1 = strtok(buffer1, "\n");
    line2 = strtok(buffer2, "\n");

    while (line1!= NULL && line2!= NULL)
    {
        // Check if the lines are identical
        if (strcmp(line1, line2) == 0)
        {
            printf("Line %d is identical\n", i);
        }
        else
        {
            printf("Line %d is different\n", i);
        }

        line1 = strtok(NULL, "\n");
        line2 = strtok(NULL, "\n");

        i++;
    }

    // Free the memory
    free(buffer1);
    free(buffer2);

    // Close the files
    fclose(file1);
    fclose(file2);

    return 0;
}