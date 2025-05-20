//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_CONTENT_LENGTH 1000
#define MAX_NUM_OF_FILES 100

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char file_content[MAX_FILE_CONTENT_LENGTH];
} file_t;

file_t files[MAX_NUM_OF_FILES];
int num_of_files = 0;

void create_file(char* file_name, char* file_content) {
    strcpy(files[num_of_files].file_name, file_name);
    strcpy(files[num_of_files].file_content, file_content);
    num_of_files++;
}

void delete_file(char* file_name) {
    int i;
    for(i=0; i<num_of_files; i++) {
        if(strcmp(files[i].file_name, file_name) == 0) {
            num_of_files--;
            break;
        }
    }
}

void list_files() {
    int i;
    for(i=0; i<num_of_files; i++) {
        printf("%s\n", files[i].file_name);
    }
}

void read_file(char* file_name) {
    int i;
    for(i=0; i<num_of_files; i++) {
        if(strcmp(files[i].file_name, file_name) == 0) {
            printf("%s\n", files[i].file_content);
            break;
        }
    }
}

int main() {
    char command[80];
    while(1) {
        printf("Enter a command: ");
        scanf("%s", command);

        if(strcmp(command, "create") == 0) {
            char file_name[MAX_FILE_NAME_LENGTH];
            char file_content[MAX_FILE_CONTENT_LENGTH];
            printf("Enter file name: ");
            scanf("%s", file_name);
            printf("Enter file content: ");
            scanf("%s", file_content);
            create_file(file_name, file_content);
        }
        else if(strcmp(command, "delete") == 0) {
            char file_name[MAX_FILE_NAME_LENGTH];
            printf("Enter file name: ");
            scanf("%s", file_name);
            delete_file(file_name);
        }
        else if(strcmp(command, "list") == 0) {
            list_files();
        }
        else if(strcmp(command, "read") == 0) {
            char file_name[MAX_FILE_NAME_LENGTH];
            printf("Enter file name: ");
            scanf("%s", file_name);
            read_file(file_name);
        }
        else {
            printf("Invalid command\n");
        }
    }

    return 0;
}