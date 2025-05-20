//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BACKUP_FILES 10
#define BACKUP_DIR "backups/"

typedef struct BackupFile {
    char name[100];
    time_t timestamp;
} BackupFile;

BackupFile backup_files[MAX_BACKUP_FILES];
int num_backup_files = 0;

void add_backup_file(char* filename) {
    strcpy(backup_files[num_backup_files].name, filename);
    backup_files[num_backup_files].timestamp = time(NULL);
    num_backup_files++;
}

void print_backup_files() {
    printf("Backup Files:\n");
    for (int i = 0; i < num_backup_files; i++) {
        printf("%s - %s\n", backup_files[i].name, ctime(&backup_files[i].timestamp));
    }
}

void backup_file(char* filename) {
    char backup_filename[100];
    strcpy(backup_filename, BACKUP_DIR);
    strcat(backup_filename, filename);
    strcat(backup_filename, ".bak");

    FILE* backup_file = fopen(backup_filename, "w");
    if (backup_file == NULL) {
        printf("Error: could not create backup file.\n");
        return;
    }

    FILE* original_file = fopen(filename, "r");
    if (original_file == NULL) {
        printf("Error: could not open original file.\n");
        fclose(backup_file);
        return;
    }

    char buffer[1024];
    while (fgets(buffer, 1024, original_file)!= NULL) {
        fputs(buffer, backup_file);
    }

    fclose(original_file);
    fclose(backup_file);

    add_backup_file(filename);
    print_backup_files();
}

int main() {
    char filename[100];
    printf("Enter filename to backup: ");
    scanf("%s", filename);

    backup_file(filename);

    return 0;
}