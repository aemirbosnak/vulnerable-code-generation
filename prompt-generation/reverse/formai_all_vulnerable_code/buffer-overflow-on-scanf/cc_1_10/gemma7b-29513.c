//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

#define BACKUP_DIR "/home/backup"

int main()
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char datetime[20];
    strftime(datetime, 20, "%Y-%m-%d_%H-%M-%S", tm);

    char filename[256];
    printf("Enter filename: ");
    scanf("%s", filename);

    char backup_filename[256];
    snprintf(backup_filename, 256, "%s/%s_%s.bak", BACKUP_DIR, filename, datetime);

    struct stat stat_buf;
    if (stat(filename, &stat_buf) == 0)
    {
        if (S_ISREG(stat_buf.st_mode))
        {
            FILE *f = fopen(filename, "r");
            FILE *b = fopen(backup_filename, "w");

            char buffer[4096];
            int read_size;

            while ((read_size = fread(buffer, 1, 4096, f)) > 0)
            {
                fwrite(buffer, 1, read_size, b);
            }

            fclose(f);
            fclose(b);
            printf("File successfully backed up.\n");
        }
        else
        {
            printf("Error: File is not a regular file.\n");
        }
    }
    else
    {
        printf("Error: File not found.\n");
    }

    return 0;
}