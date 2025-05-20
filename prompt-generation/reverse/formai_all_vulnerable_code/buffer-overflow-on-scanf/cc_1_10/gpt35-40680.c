//FormAI DATASET v1.0 Category: File Backup System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to create backup file */
void create_backup_file(char *file_name, char *backup_file_name)
{
    FILE *file, *backup;
    char c;

    file = fopen(file_name, "r");
    backup = fopen(backup_file_name, "w");

    if (file == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }

    if (backup == NULL)
    {
        printf("Error creating backup file!");
        exit(1);
    }

    while ((c = fgetc(file)) != EOF)
        fputc(c, backup);

    printf("Backup created successfully!\n");

    fclose(file);
    fclose(backup);
}

int main()
{
    char file_name[50], backup_file_name[50];
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    int choice;

    printf("Welcome to the C File Backup System.\n\n");

    printf("Enter the file name to create the backup: ");
    scanf("%s", file_name);

    printf("\nEnter the name of the backup file: ");
    scanf("%s", backup_file_name);

    printf("\n1. Create backup file\n2. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            create_backup_file(file_name, backup_file_name);
            break;

        case 2:
            exit(0);
            break;

        default:
            printf("\nInvalid choice!\n");
            break;
    }

    return 0;
}