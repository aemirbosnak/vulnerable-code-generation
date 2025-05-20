//FormAI DATASET v1.0 Category: File handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function prototypes
void createFile();
void readFile();
void appendFile();
void deleteFile();

int main()
{
    int choice;

    while (1)
    {
        printf("\nEnter your choice:\n");
        printf("1. Create a file\n");
        printf("2. Read a file\n");
        printf("3. Append to a file\n");
        printf("4. Delete a file\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createFile();
                break;
            case 2:
                readFile();
                break;
            case 3:
                appendFile();
                break;
            case 4:
                deleteFile();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

void createFile()
{
    FILE *fp;
    char filename[MAX_SIZE];
    char content[MAX_SIZE];

    printf("Enter the file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error creating file\n");
        return;
    }

    printf("Enter the content to be written to the file: ");
    scanf("%s", content);

    fprintf(fp, "%s", content);

    fclose(fp);

    printf("File created successfully\n");
}

void readFile()
{
    FILE *fp;
    char filename[MAX_SIZE];
    char ch;

    printf("Enter the file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error reading file\n");
        return;
    }

    printf("The content of the file is:\n");
    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(fp);
}

void appendFile()
{
    FILE *fp;
    char filename[MAX_SIZE];
    char content[MAX_SIZE];

    printf("Enter the file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "a");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    printf("Enter the content to be appended: ");
    scanf("%s", content);

    fprintf(fp, "%s", content);

    fclose(fp);

    printf("Content appended successfully\n");
}

void deleteFile()
{
    char filename[MAX_SIZE];

    printf("Enter the file name: ");
    scanf("%s", filename);

    if (remove(filename) == 0)
    {
        printf("File deleted successfully\n");
    }
    else
    {
        printf("Error deleting file\n");
    }
}