//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Define a matrix to store file information
    int file_info[100][3] = {{0}};

    // Get the number of files to be backed up
    int num_files = 0;
    printf("Enter the number of files you want to back up: ");
    scanf("%d", &num_files);

    // Loop to get file information
    for (int i = 0; i < num_files; i++)
    {
        // Get the file name
        printf("Enter the name of the file you want to back up: ");
        scanf("%s", file_info[i][0]);

        // Get the file size
        printf("Enter the size of the file (in KB): ");
        scanf("%d", &file_info[i][1]);

        // Get the file type
        printf("Enter the file type (e.g. doc, txt, img): ");
        scanf("%s", file_info[i][2]);
    }

    // Calculate the total size of the files
    int total_size = 0;
    for (int i = 0; i < num_files; i++)
    {
        total_size += file_info[i][1] * 1024;
    }

    // Display the total size of the files
    printf("Total size of files: %.2f MB", (double)total_size / 1000000);

    // Create a backup file
    FILE *backup_file = fopen("backup.txt", "w");
    fprintf(backup_file, "Total size of files: %.2f MB\n", (double)total_size / 1000000);
    for (int i = 0; i < num_files; i++)
    {
        fprintf(backup_file, "File name: %s\n", file_info[i][0]);
        fprintf(backup_file, "File size: %.2f KB\n", (double)file_info[i][1] / 1024);
        fprintf(backup_file, "File type: %s\n\n", file_info[i][2]);
    }
    fclose(backup_file);

    return 0;
}