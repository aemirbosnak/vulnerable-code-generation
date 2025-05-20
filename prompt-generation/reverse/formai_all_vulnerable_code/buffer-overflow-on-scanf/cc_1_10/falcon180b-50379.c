//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LEN 50
#define MAX_FILE_SIZE 100
#define MAX_FILES 50

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    char file_content[MAX_FILE_SIZE];
    int file_size;
} File;

File files[MAX_FILES];
int num_files = 0;

void create_file(char* file_name) {
    strcpy(files[num_files].file_name, file_name);
    files[num_files].file_size = 0;
    num_files++;
}

void write_to_file(char* file_name, char* content) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].file_name, file_name) == 0) {
            strcat(files[i].file_content, content);
            files[i].file_size += strlen(content);
            break;
        }
    }
}

void read_from_file(char* file_name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].file_name, file_name) == 0) {
            printf("%s\n", files[i].file_content);
            break;
        }
    }
}

int main() {
    char command[100];
    char file_name[MAX_FILE_NAME_LEN];
    char file_content[MAX_FILE_SIZE];

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            printf("Enter file name: ");
            scanf("%s", file_name);
            create_file(file_name);
        } else if (strcmp(command, "write") == 0) {
            printf("Enter file name: ");
            scanf("%s", file_name);
            printf("Enter file content: ");
            scanf("%s", file_content);
            write_to_file(file_name, file_content);
        } else if (strcmp(command, "read") == 0) {
            printf("Enter file name: ");
            scanf("%s", file_name);
            read_from_file(file_name);
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}