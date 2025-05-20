//FormAI DATASET v1.0 Category: File Backup System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_FILES 100

struct file {
    char name[MAX_NAME_LENGTH];
    time_t last_modified;
    size_t size;
};

struct backup {
    char name[MAX_NAME_LENGTH];
    struct file *files;
    size_t num_files;
};

struct backup_manager {
    struct backup *backups;
    size_t num_backups;
};

int main() {
    struct backup_manager manager;
    manager.backups = NULL;
    manager.num_backups = 0;

    int choice = 0;
    char backup_name[MAX_NAME_LENGTH];

    while (1) {
        printf("1. Create backup\n");
        printf("2. View backups\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter backup name: ");
                scanf("%s", backup_name);
                struct backup temp_backup;
                strcpy(temp_backup.name, backup_name);
                temp_backup.num_files = 0;
                temp_backup.files = NULL;

                int num_files = 0;
                printf("Enter number of files to backup: ");
                scanf("%d", &num_files);

                for (int i = 0; i < num_files; i++) {
                    struct file temp_file;

                    printf("\nEnter name of file %d: ", i + 1);
                    scanf("%s", temp_file.name);

                    printf("Enter size of file %d (in bytes): ", i + 1);
                    scanf("%ld", &temp_file.size);

                    temp_file.last_modified = time(NULL);
                    temp_backup.num_files++;
                    temp_backup.files = realloc(temp_backup.files, sizeof(struct file) * temp_backup.num_files);
                    temp_backup.files[temp_backup.num_files - 1] = temp_file;
                }

                manager.num_backups++;
                manager.backups = realloc(manager.backups, sizeof(struct backup) * manager.num_backups);
                manager.backups[manager.num_backups - 1] = temp_backup;

                printf("\nBackup created successfully!\n\n");
                break;

            case 2:
                if (manager.num_backups == 0) {
                    printf("\nNo backups to display!\n\n");
                    break;
                }

                for (int i = 0; i < manager.num_backups; i++) {
                    printf("\nBackup %d: %s\n\n", i + 1, manager.backups[i].name);

                    for (int j = 0; j < manager.backups[i].num_files; j++) {
                        printf("Name: %s\n", manager.backups[i].files[j].name);
                        printf("Size: %ld bytes\n", manager.backups[i].files[j].size);
                        printf("Last modified: %s", ctime(&manager.backups[i].files[j].last_modified));
                        printf("\n");
                    }
                }

                break;

            case 3:
                printf("\nExiting...\n\n");
                return 0;

            default:
                printf("\nInvalid choice!\n\n");
                break;
        }
    }
}