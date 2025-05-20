//FormAI DATASET v1.0 Category: File handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void write_file();
void read_file();

int main()
{
    int choice;

    do
    {
        printf("Select an option:\n");
        printf("1. Write to file\n");
        printf("2. Read from file\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                write_file();
                break;
            case 2:
                read_file();
                break;
            case 3:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}

void write_file()
{
    char filename[20], text[100];
    FILE *fptr;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fptr = fopen(filename, "w");
    if (fptr == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter text to write to file: ");
    scanf("%s", text);

    fputs(text, fptr);

    printf("Data written to file successfully!\n");

    fclose(fptr);
}

void read_file()
{
    char filename[20], text[100];
    FILE *fptr;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    fgets(text, 100, fptr);
    printf("Data read from file: %s\n", text);

    fclose(fptr);
}