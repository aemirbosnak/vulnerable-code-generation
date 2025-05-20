//FormAI DATASET v1.0 Category: File handling ; Style: imaginative
#include <stdio.h>

int main()
{
    // Welcome message
    printf("Welcome to the file handling program!\n");

    // Ask user for filename
    printf("Please enter the filename to read: ");

    // Initialize file pointer
    FILE *fp;

    // Read filename into buffer
    char filename[50];
    scanf("%s", filename);

    // Open file in read mode
    fp = fopen(filename, "r");

    // Check if file is open
    if (fp == NULL)
    {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    // Read contents of file
    char ch;
    printf("\nThe contents of the file are:\n\n");
    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }

    // Close file
    fclose(fp);

    // Ask user if they want to modify the file
    printf("\n\nDo you want to modify the file? (Y/N): ");

    // Read user input
    char choice;
    scanf(" %c", &choice);

    // Check user's choice
    if (choice == 'Y' || choice == 'y')
    {
        // Open file in write mode
        fp = fopen(filename, "w");

        // Check if file is open
        if (fp == NULL)
        {
            printf("Error opening file: %s\n", filename);
            return 1;
        }

        // Ask user for new contents of file
        printf("\nPlease enter the new contents of the file:\n\n");
        char newContents[1000];
        scanf(" %[^\n]s", newContents);

        // Write new contents to file
        fprintf(fp, "%s", newContents);

        // Close file
        fclose(fp);

        // Confirmation message
        printf("\nFile modification successful!\n");
    }
    else
    {
        // Goodbye message
        printf("\nGoodbye!\n");
    }

    return 0;
}