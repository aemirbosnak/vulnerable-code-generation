//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_CONTENT_LENGTH 1000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
    time_t timestamp;
} File;

int file_count = 0;
File files[MAX_FILES];

void create_file(char* name, char* content) {
    if(file_count >= MAX_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }

    strcpy(files[file_count].name, name);
    strcpy(files[file_count].content, content);
    files[file_count].timestamp = time(NULL);

    file_count++;
}

void delete_file(char* name) {
    int i;

    for(i = 0; i < file_count; i++) {
        if(strcmp(files[i].name, name) == 0) {
            memset(&files[i], 0, sizeof(File));
            file_count--;
            break;
        }
    }
}

void rename_file(char* old_name, char* new_name) {
    int i;

    for(i = 0; i < file_count; i++) {
        if(strcmp(files[i].name, old_name) == 0) {
            strcpy(files[i].name, new_name);
            break;
        }
    }
}

void list_files() {
    int i;

    printf("File List:\n");
    for(i = 0; i < file_count; i++) {
        printf("%s (%d bytes) - %s\n", files[i].name, strlen(files[i].content), ctime(&files[i].timestamp));
    }
}

int main() {
    char command[100];
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];

    while(1) {
        printf("Enter command: ");
        scanf("%s", command);

        if(strcmp(command, "create") == 0) {
            printf("Enter file name: ");
            scanf("%s", name);
            printf("Enter file content: ");
            scanf("%s", content);
            create_file(name, content);
        } else if(strcmp(command, "delete") == 0) {
            printf("Enter file name to delete: ");
            scanf("%s", name);
            delete_file(name);
        } else if(strcmp(command, "rename") == 0) {
            printf("Enter old file name: ");
            scanf("%s", name);
            printf("Enter new file name: ");
            scanf("%s", name);
            rename_file(name, name);
        } else if(strcmp(command, "list") == 0) {
            list_files();
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}