//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PATH 256
#define MAX_BACKUPS 10

typedef struct {
    char path[MAX_PATH];
    time_t timestamp;
} Backup;

void create_backup(const char* path) {
    Backup backup;
    strcpy(backup.path, path);
    time(&backup.timestamp);

    FILE* backup_file = fopen("backups.txt", "a");
    if (backup_file == NULL) {
        printf("Error: could not open backups.txt\n");
        exit(1);
    }

    fwrite(&backup, sizeof(Backup), 1, backup_file);
    fclose(backup_file);
}

bool backup_exists(const char* path) {
    FILE* backup_file = fopen("backups.txt", "r");
    if (backup_file == NULL) {
        printf("Error: could not open backups.txt\n");
        exit(1);
    }

    Backup backup;
    bool found = false;
    while (fread(&backup, sizeof(Backup), 1, backup_file) == 1) {
        if (strcmp(backup.path, path) == 0) {
            found = true;
            break;
        }
    }

    fclose(backup_file);
    return found;
}

void restore_backup(const char* path) {
    char backup_path[MAX_PATH];
    sprintf(backup_path, "%s.bak", path);

    if (backup_exists(path)) {
        rename(path, backup_path);
        rename(backup_path, path);
        printf("Restored %s to %s\n", path, backup_path);
    } else {
        printf("No backup found for %s\n", path);
    }
}

int main() {
    char path[MAX_PATH];
    printf("Enter file path: ");
    scanf("%s", path);

    if (backup_exists(path)) {
        char choice;
        printf("A backup exists for %s. Do you want to restore it? (y/n): ", path);
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            restore_backup(path);
        }
    } else {
        create_backup(path);
        printf("Created backup of %s\n", path);
    }

    return 0;
}