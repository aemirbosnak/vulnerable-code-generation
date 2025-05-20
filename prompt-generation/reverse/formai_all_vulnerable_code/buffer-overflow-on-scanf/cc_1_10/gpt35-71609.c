//FormAI DATASET v1.0 Category: File Backup System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50
#define MAX_FILES 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t last_modified;
    char data[MAX_FILE_SIZE];
    int size;
} File;

File backup[MAX_FILES];
int num_files = 0;

void backup_file(char* name, char* data, int size) {
    if (num_files == MAX_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }
    if (size > MAX_FILE_SIZE) {
        printf("Error: File size too large.\n");
        return;
    }
    strcpy(backup[num_files].name, name);
    backup[num_files].last_modified = time(NULL);
    memcpy(backup[num_files].data, data, size);
    backup[num_files].size = size;
    num_files++;
    printf("File '%s' backed up.\n", name);
}

void list_files() {
    printf("Available files:\n");
    for (int i = 0; i < num_files; i++) {
        char* time_str = ctime(&backup[i].last_modified);
        time_str[strlen(time_str) - 1] = '\0';
        printf("%d. %s (last modified: %s)\n", i + 1, backup[i].name, time_str);
    }
}

void write_file(char* name, char* data, int size) {
    FILE* file = fopen(name, "wb");
    if (file == NULL) {
        printf("Error: could not open file '%s'.\n", name);
        return;
    }
    fwrite(data, sizeof(char), size, file);
    fclose(file);
    printf("File '%s' written.\n", name);
}

int main() {
    char name[MAX_NAME_LENGTH];
    char data[MAX_FILE_SIZE];
    int size;

    printf("Welcome to the backup system.\n");

    while (1) {
        printf("Enter command (backup, list, write, quit): ");
        char command[MAX_NAME_LENGTH];
        scanf("%s", command);

        if (strcmp(command, "backup") == 0) {
            printf("Enter file name: ");
            scanf("%s", name);
            printf("Enter file contents: ");
            scanf("%s", data);
            size = strlen(data);
            backup_file(name, data, size);
        }
        else if (strcmp(command, "list") == 0) {
            list_files();
        }
        else if (strcmp(command, "write") == 0) {
            printf("Enter backup file number to write: ");
            int backup_num;
            scanf("%d", &backup_num);
            if (backup_num < 1 || backup_num > num_files) {
                printf("Error: Invalid backup number.\n");
                continue;
            }
            printf("Enter destination file name: ");
            scanf("%s", name);
            write_file(name, backup[backup_num - 1].data, backup[backup_num - 1].size);
        }
        else if (strcmp(command, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Error: Invalid command.\n");
        }
    }

    return 0;
}