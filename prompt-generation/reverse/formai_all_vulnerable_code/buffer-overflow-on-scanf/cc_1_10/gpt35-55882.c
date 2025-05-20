//FormAI DATASET v1.0 Category: File handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    char filename[20], ch;
    int choice, pos, ctr;
    printf("Enter filename to open for writing: ");
    scanf("%s", filename);
    fptr = fopen(filename, "w");
    if (fptr == NULL)
    {
        printf("Error opening file %s! Program terminated.", filename);
        exit(1);
    }
    printf("File %s opened for writing.\n", filename);
    printf("Enter some text to write in the file: ");
    while ((ch = getchar()) != '\n')
        fputc(ch, fptr);
    printf("Text written successfully to the file!\n");
    fclose(fptr);
    printf("File %s closed successfully!\n\n", filename);
    printf("What do you want to do with the file now?\n");
    printf("1. Read the file contents\n2. Add more text to the file\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        fptr = fopen(filename, "r");
        if (fptr == NULL)
        {
            printf("Error opening file %s! Program terminated.", filename);
            exit(1);
        }
        printf("\nFile %s opened for reading.\n", filename);
        while ((ch = fgetc(fptr)) != EOF)
            putchar(ch);
        fclose(fptr);
        printf("\nFile %s closed successfully!", filename);
    }
    else if (choice == 2)
    {
        fptr = fopen(filename, "a");
        if (fptr == NULL)
        {
            printf("Error opening file %s! Program terminated.", filename);
            exit(1);
        }
        printf("\nFile %s opened for appending.\n", filename);
        printf("Enter some more text to append to the file: ");
        while ((ch = getchar()) != '\n')
            fputc(ch, fptr);
        printf("\nText appended successfully to the file!\n");
        fclose(fptr);
        printf("File %s closed successfully!", filename);
    }
    else
    {
        printf("Invalid choice! Program terminated.");
        exit(1);
    }
    return 0;
}