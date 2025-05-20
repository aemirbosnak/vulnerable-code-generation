//FormAI DATASET v1.0 Category: File handling ; Style: Ada Lovelace
/*
This program demonstrates how to read and write to a file in C.
It prompts the user to enter the file name and the content to write.
Then, it reads the content from the file and prints it on the screen.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Prompt the user to enter the file name
    printf("Enter the filename: ");
    char filename[100];
    scanf("%s", filename);

    // Open the file for writing
    FILE *fp = fopen(filename, "w");

    // Check if the file could be opened
    if (fp == NULL)
    {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Prompt the user to enter the content to write to the file
    printf("\nEnter the content to write:\n");
    char content[1000];
    fflush(stdin);
    fgets(content, 1000, stdin);

    // Write the content to the file
    fputs(content, fp);

    // Close the file
    fclose(fp);

    // Open the file for reading
    fp = fopen(filename, "r");

    // Check if the file could be opened
    if (fp == NULL)
    {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Print the content of the file
    printf("\nThe content of the file:\n");
    char c = fgetc(fp);
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(fp);
    }

    // Close the file
    fclose(fp);

    return 0;
}