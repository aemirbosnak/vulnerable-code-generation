//Gemma-7B DATASET v1.0 Category: File handling ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char filename[20];
    char data[100];
    int i, size, choice;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Enter 1 to read data, 2 to write data, 3 to close file: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Data in the file:\n");
            size = fread(data, 1, 100, fp);
            for (i = 0; i < size; i++)
            {
                printf("%c", data[i]);
            }
            break;

        case 2:
            printf("Enter the data you want to write: ");
            scanf("%s", data);

            size = fwrite(data, 1, 100, fp);
            printf("Data written successfully.\n");
            break;

        case 3:
            fclose(fp);
            printf("File closed.\n");
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}