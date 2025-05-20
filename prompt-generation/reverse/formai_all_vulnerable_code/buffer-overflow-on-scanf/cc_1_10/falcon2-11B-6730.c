//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

#define BACKUP_DIR "C:/Backup"
#define FILE_EXTENSION ".bak"

int main()
{
    char filename[100];
    struct stat file_stat;

    printf("Enter the file name: ");
    fgets(filename, 100, stdin);

    // Check if the file exists
    if (stat(filename, &file_stat) == 0)
    {
        printf("The file '%s' already exists. Do you want to continue? (y/n): ", filename);
        char choice;
        scanf("%c", &choice);

        if (choice!= 'y')
        {
            printf("Aborting backup operation.\n");
            return 0;
        }

        // Create a backup directory if it doesn't exist
        mkdir(BACKUP_DIR, 0777);

        // Get the original file's timestamp
        struct stat orig_stat;
        stat(filename, &orig_stat);

        // Get the current time in seconds since the epoch
        time_t now = time(NULL);

        // Generate a unique filename for the backup
        sprintf(filename, "%s%s_%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", BACKUP_DIR, filename, orig_stat.st_dev, orig_stat.st_ino, orig_stat.st_mode, orig_stat.st_nlink, orig_stat.st_uid, orig_stat.st_gid, orig_stat.st_size, orig_stat.st_atime, orig_stat.st_mtime, orig_stat.st_ctime, now, orig_stat.st_blksize, orig_stat.st_blocks, orig_stat.st_rdev, orig_stat.st_ino);

        // Create the backup file
        FILE *fp = fopen(filename, "wb");
        if (fp == NULL)
        {
            printf("Error creating the backup file.\n");
            return 0;
        }

        // Copy the original file to the backup file
        fseek(fp, 0, SEEK_SET);
        fseek(fopen(filename, "rb"), 0, SEEK_SET);
        while (!feof(fopen(filename, "rb")))
        {
            fread(fp, 1, 1, fopen(filename, "rb"));
        }

        // Close the backup file
        fclose(fp);

        // Delete the original file
        remove(filename);

        // Rename the backup file to the original filename
        rename(filename, filename);

        printf("Backup completed successfully.\n");
    }
    else
    {
        printf("Error: The file does not exist.\n");
    }

    return 0;
}