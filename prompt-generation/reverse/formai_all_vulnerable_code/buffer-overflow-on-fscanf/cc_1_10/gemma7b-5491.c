//Gemma-7B DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void file_handling()
{
    FILE *fp;
    char filename[20];
    int choice;

    printf("Enter file name:");
    scanf("%s", filename);

    printf("Choose an option:");
    printf("\n1. Open file\n2. Close file\n3. Read file\n4. Write file\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            fp = fopen(filename, "r");
            if (fp == NULL)
            {
                printf("Error opening file");
            }
            else
            {
                printf("File opened successfully");
            }
            break;

        case 2:
            fp = fopen(filename, "w");
            if (fp == NULL)
            {
                printf("Error closing file");
            }
            else
            {
                printf("File closed successfully");
            }
            break;

        case 3:
            fp = fopen(filename, "r");
            if (fp == NULL)
            {
                printf("Error reading file");
            }
            else
            {
                char data[1024];
                printf("Data read from file:");
                fscanf(fp, "%s", data);
                printf("%s", data);
            }
            break;

        case 4:
            fp = fopen(filename, "w");
            if (fp == NULL)
            {
                printf("Error writing file");
            }
            else
            {
                char data[1024];
                printf("Enter data to write:");
                scanf("%s", data);
                fprintf(fp, "%s", data);
                printf("Data written successfully");
            }
            break;

        default:
            printf("Invalid choice");
    }

    fclose(fp);
}

int main()
{
    file_handling();

    return 0;
}