//FormAI DATASET v1.0 Category: File handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to File Handling Invasion!\n\n");

    char fileName[20], data[100];
    FILE *fptr;

    printf("Enter file name: ");
    scanf("%s", fileName);

    //creating a new file
    fptr = fopen(fileName, "w");

    if (fptr == NULL)
    {
        printf("Error creating file!");
        exit(1);
    }

    printf("File created successfully!\n\n");

    //writing into file
    printf("Now, let's invade the file with some data:\n");
    fprintf(fptr, "You have been hacked! \n");

    printf("Enter some secret message: ");
    scanf("%s", data);

    fprintf(fptr, "%s", data);

    printf("Data Written in the File successfully!\n");

    //closing the file
    fclose(fptr);

    //reopening the file in read mode
    fptr = fopen(fileName, "r");

    if (fptr == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }

    //reading from file
    printf("\nData read from the file:\n");
    char c = fgetc(fptr);
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(fptr);
    }

    printf("\n\nThank you for being part of the File Handling Invasion!");
    fclose(fptr);
    return 0;
}