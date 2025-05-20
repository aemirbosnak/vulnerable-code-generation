//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 50
#define MAX_FILE_CONTENT_LEN 1000
#define MAX_NUM_FILES 100

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    char file_content[MAX_FILE_CONTENT_LEN];
} File;

File files[MAX_NUM_FILES];
int num_files = 0;

void create_file(char* file_name, char* file_content) {
    if (num_files >= MAX_NUM_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }

    strcpy(files[num_files].file_name, file_name);
    strcpy(files[num_files].file_content, file_content);

    num_files++;
}

void read_file(char* file_name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].file_name, file_name) == 0) {
            printf("File content: %s\n", files[i].file_content);
            return;
        }
    }

    printf("File not found.\n");
}

void delete_file(char* file_name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].file_name, file_name) == 0) {
            memset(&files[i], 0, sizeof(File));
            num_files--;
            printf("File deleted successfully.\n");
            return;
        }
    }

    printf("File not found.\n");
}

int main() {
    char file_name[MAX_FILE_NAME_LEN];
    char file_content[MAX_FILE_CONTENT_LEN];

    while (1) {
        printf("Enter command (create/read/delete): ");
        scanf("%s", file_name);

        if (strcmp(file_name, "create") == 0) {
            printf("Enter file name: ");
            scanf("%s", file_name);
            printf("Enter file content: ");
            scanf("%s", file_content);
            create_file(file_name, file_content);
        } else if (strcmp(file_name, "read") == 0) {
            printf("Enter file name: ");
            scanf("%s", file_name);
            read_file(file_name);
        } else if (strcmp(file_name, "delete") == 0) {
            printf("Enter file name: ");
            scanf("%s", file_name);
            delete_file(file_name);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}