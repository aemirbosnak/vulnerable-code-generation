//FormAI DATASET v1.0 Category: File handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *filePointer;
    char fileName[20], fileContent[1000];

    printf("Enter the name of the file you wish to create:\n");
    scanf("%s", fileName);

    filePointer = fopen(fileName, "w");

    if (filePointer == NULL)
    {
        printf("Sorry, unable to create the file!\n");
        exit(1);
    }
    else
    {
        printf("File created successfully!\n");
        printf("Enter the content you wish to write in the file:\n");
        scanf("%s", fileContent);

        fprintf(filePointer, "%s", fileContent);

        printf("Content written successfully to the file!\n");
        fclose(filePointer);
    }

    printf("Would you like to read the contents of the file? (y/n)\n");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'y')
    {
        filePointer = fopen(fileName, "r");

        if (filePointer == NULL)
        {
            printf("Sorry, file does not exist!\n");
            exit(1);
        }

        printf("The contents of the file \"%s\" are:\n", fileName);

        char readChar;
        while ((readChar = fgetc(filePointer)) != EOF)
        {
            printf("%c", readChar);
        }

        fclose(filePointer);
    }

    return 0;
}