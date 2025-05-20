//Gemma-7B DATASET v1.0 Category: File handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char filename[256];
    FILE *fp;
    int choice;

    // Get the filename from the user
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
    while (!feof(fp))
    {
        char line[256];
        fgets(line, 256, fp);
        printf("%s\n", line);
    }

    // Close the file
    fclose(fp);

    // Get the user's choice
    printf("Enter 1 to search for a line in the file, 2 to edit the file, or 3 to delete the file: ");
    scanf("%d", &choice);

    // Search for a line in the file
    if (choice == 1)
    {
        char search_term[256];
        printf("Enter the line number you want to search for: ");
        scanf("%d", &choice);
        printf("Enter the search term: ");
        scanf("%s", search_term);

        // Search for the line
        fp = fopen(filename, "r");
        while (!feof(fp))
        {
            char line[256];
            fgets(line, 256, fp);
            if (strstr(line, search_term) != NULL)
            {
                printf("%s\n", line);
            }
        }
        fclose(fp);
    }

    // Edit the file
    else if (choice == 2)
    {
        char edit_line[256];
        printf("Enter the line number you want to edit: ");
        scanf("%d", &choice);
        printf("Enter the new line content: ");
        scanf("%s", edit_line);

        // Edit the line
        fp = fopen(filename, "r");
        char file_contents[10000];
        int i = 0;
        while (!feof(fp))
        {
            char line[256];
            fgets(line, 256, fp);
            if (i == choice - 1)
            {
                fprintf(fp, "%s", edit_line);
            }
            else
            {
                file_contents[i] = line;
                i++;
            }
        }
        fclose(fp);

        // Write the file contents to a new file
        fp = fopen("temp.txt", "w");
        fprintf(fp, "%s", file_contents);
        fclose(fp);

        // Rename the temporary file to the original file
        rename("temp.txt", filename);
    }

    // Delete the file
    else if (choice == 3)
    {
        printf("Enter the name of the file you want to delete: ");
        scanf("%s", filename);

        // Delete the file
        unlink(filename);
    }

    return 0;
}