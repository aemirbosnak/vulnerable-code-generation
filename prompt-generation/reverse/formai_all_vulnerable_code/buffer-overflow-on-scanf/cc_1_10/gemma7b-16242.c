//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    system("clear");
    system("cowsay \"Welcome to the C File Backup System!\"");

    char filename[256];
    printf("Enter the name of the file you want to backup: ");
    scanf("%s", filename);

    struct stat file_stat;
    stat(filename, &file_stat);

    if (file_stat.st_size > 100000) {
        printf("Error: File size too large. Maximum size is 100KB.\n");
        return 1;
    }

    char backup_dir[256];
    sprintf(backup_dir, "/home/user/backup/%s", filename);

    if (mkdir(backup_dir, 0755) == -1) {
        printf("Error: Unable to create backup directory.\n");
        return 1;
    }

    char backup_filename[256];
    sprintf(backup_filename, "%s/%s", backup_dir, filename);

    FILE *backup_file = fopen(backup_filename, "w");

    if (backup_file == NULL) {
        printf("Error: Unable to open backup file.\n");
        return 1;
    }

    FILE *source_file = fopen(filename, "r");

    if (source_file == NULL) {
        printf("Error: Unable to open source file.\n");
        return 1;
    }

    char buffer[1024];
    int read_size;

    while ((read_size = fread(buffer, 1, 1024, source_file)) > 0) {
        fwrite(buffer, 1, read_size, backup_file);
    }

    fclose(source_file);
    fclose(backup_file);

    system("cowsay \"File backup complete!\"");

    return 0;
}