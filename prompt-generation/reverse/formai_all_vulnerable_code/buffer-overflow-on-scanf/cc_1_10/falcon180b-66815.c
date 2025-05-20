//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_SIZE];
    int size;
} File;

void create_file(File *file, char *name, char *content) {
    strcpy(file->name, name);
    strcpy(file->content, content);
    file->size = strlen(content);
}

void delete_file(File *file) {
    memset(file, 0, sizeof(File));
}

void rename_file(File *file, char *new_name) {
    strcpy(file->name, new_name);
}

void copy_file(File *src_file, File *dest_file) {
    strcpy(dest_file->content, src_file->content);
    dest_file->size = src_file->size;
}

void move_file(File *src_file, File *dest_file) {
    rename_file(src_file, dest_file->name);
    delete_file(src_file);
}

int main() {
    File files[MAX_FILES];
    int num_files = 0;

    while (num_files < MAX_FILES) {
        printf("Enter command (create/delete/rename/copy/move): ");
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            char file_name[MAX_FILE_NAME_LENGTH];
            char file_content[MAX_FILE_SIZE];
            printf("Enter file name: ");
            scanf("%s", file_name);
            printf("Enter file content: ");
            scanf("%s", file_content);
            create_file(&files[num_files], file_name, file_content);
            num_files++;
        } else if (strcmp(command, "delete") == 0) {
            int file_id;
            printf("Enter file ID: ");
            scanf("%d", &file_id);
            delete_file(&files[file_id]);
        } else if (strcmp(command, "rename") == 0) {
            int file_id;
            char new_name[MAX_FILE_NAME_LENGTH];
            printf("Enter file ID: ");
            scanf("%d", &file_id);
            printf("Enter new file name: ");
            scanf("%s", new_name);
            rename_file(&files[file_id], new_name);
        } else if (strcmp(command, "copy") == 0) {
            int src_file_id, dest_file_id;
            printf("Enter source file ID: ");
            scanf("%d", &src_file_id);
            printf("Enter destination file ID: ");
            scanf("%d", &dest_file_id);
            copy_file(&files[src_file_id], &files[dest_file_id]);
        } else if (strcmp(command, "move") == 0) {
            int src_file_id, dest_file_id;
            printf("Enter source file ID: ");
            scanf("%d", &src_file_id);
            printf("Enter destination file ID: ");
            scanf("%d", &dest_file_id);
            move_file(&files[src_file_id], &files[dest_file_id]);
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}