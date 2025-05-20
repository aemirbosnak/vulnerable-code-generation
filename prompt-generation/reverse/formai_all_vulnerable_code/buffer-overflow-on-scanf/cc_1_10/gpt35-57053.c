//FormAI DATASET v1.0 Category: File handling ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *filePointer;
    char fileName[20], character;

    printf("Enter the file name to create: ");
    scanf("%s", fileName);

    filePointer = fopen(fileName, "w"); // open file in write mode

    if (filePointer == NULL)
    {
        printf("Unable to create file.\n");
        exit(1);
    }

    printf("File created successfully.\n");

    fprintf(filePointer, "Congratulations, you have just created a file by using C File Handling!\n");

    fclose(filePointer); // close the file

    printf("Would you like to see the contents of the file? (Y/N): ");
    scanf(" %c", &character);

    if (character == 'Y' || character == 'y')
    {
        filePointer = fopen(fileName, "r"); // open file in read mode

        if (filePointer == NULL)
        {
            printf("Unable to open file.\n");
            exit(1);
        }

        printf("The contents of the file are:\n");

        character = fgetc(filePointer);

        while (character != EOF)
        {
            printf("%c", character);
            character = fgetc(filePointer);
        }

        fclose(filePointer); // close the file
    }

    return 0;
}