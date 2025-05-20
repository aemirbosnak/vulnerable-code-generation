//FormAI DATASET v1.0 Category: File handling ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// function to write data to file
void writeToFile(FILE *fptr, char *data)
{
    if (fptr == NULL)
    {
        printf("Error: Could not open file\n");
        exit(1);
    }
    
    fprintf(fptr, "%s", data);
    printf("Data written to file successfully!\n");
    
    // close the file
    fclose(fptr);
}

// function to read data from file
void readFromFile(FILE *fptr)
{
    char c;

    if (fptr == NULL)
    {
        printf("Error: Could not open file\n");
        exit(1);
    }

    printf("\nData in file: ");
    c = fgetc(fptr);
    while (c != EOF)
    {
        putchar(c);
        c = fgetc(fptr);
    }

    // close the file
    fclose(fptr);
}

int main()
{
    FILE *fptr;
    char filename[100];
    char data[100];
    int choice;

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("\nCyberpunk style file handling program\n");
    printf("1. Write data to file\n");
    printf("2. Read data from file\n");
    printf("3. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("\nEnter data to be written to file: ");
            scanf("%s", data);

            fptr = fopen(filename, "w");
            writeToFile(fptr, data);
            break;

        case 2:
            fptr = fopen(filename, "r");
            readFromFile(fptr);
            break;

        case 3:
            printf("\nExiting program...\n");
            exit(0);

        default:
            printf("\nInvalid choice\n");
            break;
    }

    return 0;
}