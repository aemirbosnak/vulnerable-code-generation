//FormAI DATASET v1.0 Category: File Backup System ; Style: Ada Lovelace
/* Ada Lovelace style C File Backup System Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_BACKUP_COUNT 5

/* Function to create backup folder if it does not exist */
void createBackupFolder() {
    #ifdef _WIN32
    system("mkdir .\\Backup");
    #else
    system("mkdir ./Backup");
    #endif
}

/* Function to get current date and time as string */
void getCurrentDateTime(char* buffer) {
    time_t timer;
    struct tm* tm_info;
    time(&timer);
    tm_info = localtime(&timer);
    strftime(buffer, 30, "%Y-%m-%d_%H-%M-%S", tm_info);
}

/* Function to backup a file */
void backupFile(char* filename) {
    char source[MAX_FILENAME_LENGTH+1], dest[MAX_FILENAME_LENGTH+1];
    char datetime[30];
    getCurrentDateTime(datetime);
    #ifdef _WIN32
    sprintf(source, ".\\%s", filename);
    sprintf(dest, ".\\Backup\\%s_%s", filename, datetime);
    #else
    sprintf(source, "./%s", filename);
    sprintf(dest, "./Backup/%s_%s", filename, datetime);
    #endif
    FILE *source_file, *dest_file;
    source_file = fopen(source, "rb");
    dest_file = fopen(dest, "wb");
    char ch;
    while((ch = fgetc(source_file)) != EOF) {
        fputc(ch, dest_file);
    }
    fclose(source_file);
    fclose(dest_file);
}

int main() {
    char filename[MAX_FILENAME_LENGTH+1];
    printf("Enter filename to backup: ");
    scanf("%s", filename);
    createBackupFolder();
    backupFile(filename);
    printf("File backed up successfully!");
    return 0;
}