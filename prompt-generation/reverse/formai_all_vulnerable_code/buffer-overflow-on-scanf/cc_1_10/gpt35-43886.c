//FormAI DATASET v1.0 Category: File Backup System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 20
#define MAX_NUM_FILES 10

typedef struct {
    char filename[MAX_FILENAME_SIZE];
    char contents[1024];
} File;

typedef struct {
    File files[MAX_NUM_FILES];
    int num_files;
} Backup;

void add_file(Backup* backup, char* filename, char* contents) {
    if (backup->num_files == MAX_NUM_FILES) {
        printf("Backup is full, cannot add file %s\n", filename);
        return;
    }
    strcpy(backup->files[backup->num_files].filename, filename);
    strcpy(backup->files[backup->num_files].contents, contents);
    backup->num_files++;
    printf("File %s added to backup\n", filename);
}

void remove_file(Backup* backup, char* filename) {
    int i, index = -1;
    for (i = 0; i < backup->num_files; i++) {
        if (strcmp(backup->files[i].filename, filename) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("File %s not found in backup\n", filename);
        return;
    }
    for (i = index; i < backup->num_files-1; i++) {
        backup->files[i] = backup->files[i+1];
    }
    backup->num_files--;
    printf("File %s removed from backup\n", filename);
}

void list_files(Backup* backup) {
    int i;
    printf("Backup contents:\n");
    for (i = 0; i < backup->num_files; i++) {
        printf("%s\n", backup->files[i].filename);
    }
}

int main() {
    Backup backup = {0};
    char filename[MAX_FILENAME_SIZE];
    char contents[1024];
    int choice;
    while (1) {
        printf("Backup menu:\n");
        printf("1) Add file\n");
        printf("2) Remove file\n");
        printf("3) List files\n");
        printf("4) Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter filename: ");
                scanf("%s", filename);
                printf("Enter contents: ");
                scanf("%s", contents);
                add_file(&backup, filename, contents);
                break;
            case 2:
                printf("Enter filename: ");
                scanf("%s", filename);
                remove_file(&backup, filename);
                break;
            case 3:
                list_files(&backup);
                break;
            case 4:
                printf("Terminating backup system...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    }
    return 0;
}