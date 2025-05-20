//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_SIZE 256
#define MAX_NUM_BACKUPS 10

typedef struct {
    char file_name[MAX_FILE_NAME_SIZE];
    time_t timestamp;
} Backup;

void create_backup(char* file_name) {
    Backup backup;
    strcpy(backup.file_name, file_name);
    time(&backup.timestamp);

    FILE* backup_file = fopen("backups.txt", "a+");
    if (backup_file == NULL) {
        printf("Error opening backups file.\n");
        exit(1);
    }

    int num_backups = 0;
    Backup backups[MAX_NUM_BACKUPS];
    while (fscanf(backup_file, "%s %ld\n", backups[num_backups].file_name, &backups[num_backups].timestamp)!= EOF) {
        num_backups++;
        if (num_backups == MAX_NUM_BACKUPS) {
            break;
        }
    }

    fclose(backup_file);

    FILE* backup_file_new = fopen("backups.txt", "w");
    if (backup_file_new == NULL) {
        printf("Error opening backups file for writing.\n");
        exit(1);
    }

    for (int i = 0; i < num_backups; i++) {
        fprintf(backup_file_new, "%s %ld\n", backups[i].file_name, backups[i].timestamp);
    }

    fprintf(backup_file_new, "%s %ld\n", backup.file_name, backup.timestamp);

    fclose(backup_file_new);
}

int main() {
    char file_name[MAX_FILE_NAME_SIZE];
    printf("Enter file name: ");
    scanf("%s", file_name);

    create_backup(file_name);

    printf("Backup created.\n");

    return 0;
}