//FormAI DATASET v1.0 Category: File handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *filePtr;
    char fileName[20];
    char content[1000];
    int choice;

    printf("Enter file name: ");
    scanf("%s", fileName);

    filePtr = fopen(fileName, "w");

    if (filePtr == NULL)
    {
        printf("Unable to create file.\n");
        return 0;
    }

    printf("Enter contents to write in the file: ");
    scanf("%s", content);

    fprintf(filePtr, "%s", content);

    printf("Contents have been successfully written to the file '%s'.\n\n", fileName);

    fclose(filePtr);

    printf("Do you want to read the contents of the file? (1/0): ");
    scanf("%d", &choice);

    if (choice)
    {
        filePtr = fopen(fileName, "r");

        if (filePtr == NULL)
        {
            printf("Unable to open file.\n");
            return 0;
        }

        printf("\n\nThe contents of the file '%s': \n", fileName);

        char c = fgetc(filePtr);
        while (c != EOF)
        {
            printf("%c", c);
            c = fgetc(filePtr);
        }

        fclose(filePtr);
    }

    return 0;
}