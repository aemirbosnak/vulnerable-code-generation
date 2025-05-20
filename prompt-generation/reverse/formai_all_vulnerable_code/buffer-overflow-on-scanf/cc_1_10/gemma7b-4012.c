//Gemma-7B DATASET v1.0 Category: File handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare variables
    char filename[255];
    FILE *fp;
    int choice, option, data;
    char buffer[1024];

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file
    fp = fopen(filename, "r");

    // Check if the file is opened successfully
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // Display the menu options
    printf("\nMenu options:\n");
    printf("1. Read data from the file\n");
    printf("2. Write data to the file\n");
    printf("3. Append data to the file\n");
    printf("4. Close the file\n");

    // Get the user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Switch case to handle the user's choice
    switch (choice)
    {
        case 1:
            // Read data from the file
            printf("Data from the file:\n");
            while (fgets(buffer, 1024, fp) != NULL)
            {
                printf("%s", buffer);
            }
            break;

        case 2:
            // Write data to the file
            printf("Enter the data you want to write: ");
            scanf("%s", buffer);

            fprintf(fp, "%s", buffer);
            break;

        case 3:
            // Append data to the file
            printf("Enter the data you want to append: ");
            scanf("%s", buffer);

            fprintf(fp, "%s", buffer);
            break;

        case 4:
            // Close the file
            fclose(fp);
            break;

        default:
            // Invalid choice
            printf("Invalid choice.\n");
    }

    // Close the file
    fclose(fp);

    return 0;
}