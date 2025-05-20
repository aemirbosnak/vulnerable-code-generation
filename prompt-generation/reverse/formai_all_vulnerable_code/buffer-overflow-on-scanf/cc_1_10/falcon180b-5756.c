//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

#define MAX_BACKUPS 10
#define MAX_FILENAME_LEN 256
#define BACKUP_FILE_EXT ".bak"

typedef struct {
    char filename[MAX_FILENAME_LEN];
    time_t backup_time;
} Backup;

int backup_count = 0;
Backup backups[MAX_BACKUPS];

void create_backup(char* filename) {
    if (backup_count >= MAX_BACKUPS) {
        printf("Error: Maximum number of backups reached.\n");
        return;
    }

    Backup backup;
    strcpy(backup.filename, filename);
    backup.backup_time = time(NULL);

    backups[backup_count++] = backup;
}

int compare_backups(const void* a, const void* b) {
    Backup backup_a = *(Backup*)a;
    Backup backup_b = *(Backup*)b;

    if (backup_a.backup_time > backup_b.backup_time) {
        return -1;
    } else if (backup_a.backup_time < backup_b.backup_time) {
        return 1;
    } else {
        return 0;
    }
}

void sort_backups() {
    qsort(backups, backup_count, sizeof(Backup), compare_backups);
}

void delete_oldest_backup() {
    if (backup_count == 0) {
        printf("Error: No backups found.\n");
        return;
    }

    Backup oldest_backup = backups[0];
    backups[0] = backups[--backup_count];

    remove(strcat(oldest_backup.filename, BACKUP_FILE_EXT));
}

void print_backups() {
    if (backup_count == 0) {
        printf("No backups found.\n");
        return;
    }

    sort_backups();

    printf("Backups:\n");
    for (int i = 0; i < backup_count; i++) {
        Backup backup = backups[i];
        printf("%s (%ld)\n", backup.filename, backup.backup_time);
    }
}

int main() {
    char filename[MAX_FILENAME_LEN];
    printf("Enter filename to backup: ");
    scanf("%s", filename);

    create_backup(filename);
    print_backups();

    return 0;
}