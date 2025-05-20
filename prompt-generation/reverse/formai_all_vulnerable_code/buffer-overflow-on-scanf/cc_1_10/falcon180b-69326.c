//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_NAME 100

typedef struct {
    char file_name[MAX_FILE_NAME];
    time_t last_modified;
} file_t;

file_t files[MAX_FILES];
int num_files;

void add_file(char *file_name) {
    file_t *new_file = &files[num_files];
    strcpy(new_file->file_name, file_name);
    new_file->last_modified = time(NULL);
    num_files++;
}

void remove_file(char *file_name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].file_name, file_name) == 0) {
            memmove(&files[i], &files[i + 1], sizeof(file_t) * (num_files - i - 1));
            num_files--;
            break;
        }
    }
}

void backup_file(char *file_name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].file_name, file_name) == 0) {
            printf("Backing up %s...\n", files[i].file_name);
            remove_file(file_name);
            add_file(file_name);
            break;
        }
    }
}

void restore_file(char *file_name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].file_name, file_name) == 0) {
            printf("Restoring %s...\n", files[i].file_name);
            remove_file(file_name);
            add_file(file_name);
            break;
        }
    }
}

void list_files() {
    int i;
    for (i = 0; i < num_files; i++) {
        printf("%s (%s)\n", files[i].file_name, ctime(&files[i].last_modified));
    }
}

int main() {
    int choice;
    char file_name[MAX_FILE_NAME];

    printf("Enter file name: ");
    scanf("%s", file_name);
    add_file(file_name);

    while (1) {
        printf("\n1. Backup file\n2. Restore file\n3. List files\n4. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter file name: ");
            scanf("%s", file_name);
            backup_file(file_name);
        } else if (choice == 2) {
            printf("Enter file name: ");
            scanf("%s", file_name);
            restore_file(file_name);
        } else if (choice == 3) {
            list_files();
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}