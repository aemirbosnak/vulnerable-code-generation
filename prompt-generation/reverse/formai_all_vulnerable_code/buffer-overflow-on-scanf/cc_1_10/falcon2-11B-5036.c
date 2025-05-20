//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_PATH_LENGTH 100
#define MAX_FILE_NAME_LENGTH 50
#define MAX_BACKUP_COUNT 5

typedef struct {
    char file_path[MAX_FILE_PATH_LENGTH];
    char file_name[MAX_FILE_NAME_LENGTH];
    int backup_count;
} File;

File files[MAX_BACKUP_COUNT];
int file_count = 0;

void create_file_backup(char* file_path, char* file_name) {
    int i;
    char backup_file_name[MAX_FILE_NAME_LENGTH];

    for (i = 0; i < file_count; i++) {
        if (strcmp(files[i].file_name, file_name) == 0) {
            printf("File %s already exists in the backup list.\n", file_name);
            return;
        }
    }

    strcpy(backup_file_name, file_name);
    strcat(backup_file_name, ".bak");

    if (file_count < MAX_BACKUP_COUNT) {
        strcpy(files[file_count].file_path, file_path);
        strcpy(files[file_count].file_name, file_name);
        files[file_count].backup_count = 1;
        file_count++;

        printf("File %s has been added to the backup list.\n", file_name);
    } else {
        printf("Maximum backup limit (%d) reached. Cannot add more files.\n", MAX_BACKUP_COUNT);
    }
}

int main() {
    char file_path[MAX_FILE_PATH_LENGTH];
    char file_name[MAX_FILE_NAME_LENGTH];
    int choice;

    while (1) {
        printf("1. Create a backup of a file\n2. List all backup files\n3. Restore a file from the backup list\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the path of the file to backup: ");
                scanf("%s", file_path);

                printf("Enter the name of the file to backup: ");
                scanf("%s", file_name);

                create_file_backup(file_path, file_name);
                break;

            case 2:
                printf("List of backup files:\n");

                for (int i = 0; i < file_count; i++) {
                    printf("%s\n", files[i].file_name);
                }
                break;

            case 3:
                printf("Enter the path of the file to restore: ");
                scanf("%s", file_path);

                printf("Enter the name of the file to restore: ");
                scanf("%s", file_name);

                strcpy(file_name, "");

                for (int i = 0; i < file_count; i++) {
                    if (strcmp(files[i].file_name, file_name) == 0) {
                        strcpy(file_name, files[i].file_name);
                        strcat(file_name, ".bak");
                        printf("File %s has been restored.\n", file_name);
                        break;
                    }
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}