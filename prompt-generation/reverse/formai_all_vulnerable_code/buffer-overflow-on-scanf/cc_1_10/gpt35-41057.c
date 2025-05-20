//FormAI DATASET v1.0 Category: File Backup System ; Style: visionary
#include<stdio.h>
#include<string.h>

#define MAX_STR_LEN 1000

void backup(char* file_path)
{
    FILE* file_pointer = NULL;
    file_pointer = fopen(file_path, "r");

    if(file_pointer == NULL)
    {
        printf("\n Error opening file! \n");
        return;
    }

    char file_data[MAX_STR_LEN];
    memset(file_data, 0, MAX_STR_LEN);

    while(fgets(file_data, MAX_STR_LEN, file_pointer) != NULL)
    {
        printf("%s", file_data);
    }

    fclose(file_pointer);

    char backup_file_name[MAX_STR_LEN + 5];
    memset(backup_file_name, 0, MAX_STR_LEN + 5);
    sprintf(backup_file_name, "%s.bak", file_path);

    FILE* backup_file_pointer = NULL;
    backup_file_pointer = fopen(backup_file_name, "w");

    if(backup_file_pointer == NULL)
    {
        printf("\n Error creating backup file! \n");
        return;
    }

    fwrite(file_data, strlen(file_data), 1, backup_file_pointer);
    fclose(backup_file_pointer);

    printf("\n Backup created successfully! \n\n");
}

int main()
{
    char file_path[MAX_STR_LEN];
    memset(file_path, 0, MAX_STR_LEN);

    printf("Enter the file path to backup: ");
    scanf("%s", file_path);

    printf("\n Read from file: \n");
    backup(file_path);

    return 0;
}