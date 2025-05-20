//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backup_file(char *filename)
{
    FILE *fp, *fp_backup;
    char buffer[1024];
    int read_size, write_size;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file: %s", filename);
        exit(1);
    }

    fp_backup = fopen("backup.txt", "a");
    if (fp_backup == NULL)
    {
        fclose(fp);
        printf("Error opening file: backup.txt");
        exit(1);
    }

    while ((read_size = fread(buffer, 1, 1024, fp)) > 0)
    {
        write_size = fwrite(buffer, 1, read_size, fp_backup);
        if (write_size != read_size)
        {
            fclose(fp);
            fclose(fp_backup);
            printf("Error writing to file: backup.txt");
            exit(1);
        }
    }

    fclose(fp);
    fclose(fp_backup);
    printf("File backup successful: %s", filename);
}

int main()
{
    char filename[256];

    printf("Enter file name: ");
    scanf("%s", filename);

    backup_file(filename);

    return 0;
}