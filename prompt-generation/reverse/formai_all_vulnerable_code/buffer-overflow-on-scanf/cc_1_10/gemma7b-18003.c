//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

#define BACKUP_DIR "/home/user/backup"

int main()
{
    char filename[256];
    char backup_filename[256];
    struct stat file_stat;
    FILE *fp, *backup_fp;

    printf("Enter filename: ");
    scanf("%s", filename);

    // Check if file exists
    if (stat(filename, &file_stat) == 0)
    {
        // Calculate backup filename
        snprintf(backup_filename, 256, "%s/%s", BACKUP_DIR, filename);

        // Create backup file
        fp = fopen(filename, "r");
        backup_fp = fopen(backup_filename, "w");

        // Copy file data
        if (fp && backup_fp)
        {
            char buffer[4096];
            int read_bytes;

            while ((read_bytes = read(fp, buffer, 4096)) > 0)
            {
                write(backup_fp, buffer, read_bytes);
            }

            fclose(fp);
            fclose(backup_fp);
        }
    }
    else
    {
        printf("Error: file does not exist.\n");
    }

    return 0;
}