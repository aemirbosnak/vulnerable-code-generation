//FormAI DATASET v1.0 Category: File Backup System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILENAME 100
#define MAX_FILETYPE 20
#define MAX_BACKUP_COUNT 10

struct backup_file {
    char filename[MAX_FILENAME];
    char type[MAX_FILETYPE];
};

int main() {
    int backup_count = 0;
    struct backup_file backups[MAX_BACKUP_COUNT];

    while (1) {
        printf("Enter the filename: ");
        char filename[MAX_FILENAME];
        scanf("%s", filename);

        if (strcmp(filename, "exit") == 0) {
            break;
        }

        printf("Enter the file type: ");
        char type[MAX_FILETYPE];
        scanf("%s", type);

        if (backup_count == MAX_BACKUP_COUNT) {
            printf("Maximum backup limit reached\n");
            break;
        }

        struct backup_file backup;
        strcpy(backup.filename, filename);
        strcpy(backup.type, type);
        backups[backup_count++] = backup;

        printf("Backup created successfully\n");
    }

    printf("All backups:\n");
    for (int i = 0; i < backup_count; i++) {
        printf("%s.%s\n", backups[i].filename, backups[i].type);
    }

    return 0;
}