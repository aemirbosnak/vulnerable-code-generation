//FormAI DATASET v1.0 Category: File Backup System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define FILE_NAME_LEN 25

// function declarations
int get_file_count();
void get_file_names(char file_names[][FILE_NAME_LEN], int file_count);
void backup_files(char file_names[][FILE_NAME_LEN], int file_count);

int main()
{
    printf("Welcome to the C File Backup System\n\n");
    
    int file_count = get_file_count(); // get the number of files to backup
    
    char file_names[MAX_FILES][FILE_NAME_LEN]; // create a 2D array to store file names
    
    get_file_names(file_names, file_count); // get the names of the files to backup
    
    backup_files(file_names, file_count); // backup the files
    
    printf("\nBackup successful!\n");
    
    return 0;
}

int get_file_count()
{
    int file_count;
    
    printf("How many files would you like to backup? (maximum %d): ", MAX_FILES);
    scanf("%d", &file_count);
    while (getchar() != '\n'); // clear input buffer
    
    if (file_count > MAX_FILES)
    {
        printf("Error: too many files, please try again.\n");
        return get_file_count();
    }
    else if (file_count <= 0)
    {
        printf("Error: invalid input, please try again.\n");
        return get_file_count();
    }
    else
    {
        return file_count;
    }
}

void get_file_names(char file_names[][FILE_NAME_LEN], int file_count)
{
    int i;
    
    for (i = 0; i < file_count; i++)
    {
        printf("\nEnter the name of file %d to backup: ", i+1);
        fgets(file_names[i], FILE_NAME_LEN, stdin);
        file_names[i][strcspn(file_names[i], "\n")] = 0; // remove newline character
    }
}

void backup_files(char file_names[][FILE_NAME_LEN], int file_count)
{
    int i;
    char command[100];
    
    printf("\nBacking up files...\n");
    
    for (i = 0; i < file_count; i++)
    {
        sprintf(command, "cp %s %s.bak", file_names[i], file_names[i]); // create terminal command
        system(command); // execute terminal command
    }
}