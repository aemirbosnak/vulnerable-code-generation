//FormAI DATASET v1.0 Category: File system simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10
#define MAX_FILE_SIZE 100

struct file {
    char name[20];
    char content[MAX_FILE_SIZE];
    int size;
};

int num_files = 0;
struct file files[MAX_FILES];

void create_file(char *name) {
    if(num_files == MAX_FILES) {
        printf("Error: No more space for files!\n");
        return;
    }
    for(int i = 0; i < num_files; i++) {
        if(strcmp(files[i].name, name) == 0) {
            printf("Error: File already exists!\n");
            return;
        }
    }
    strcpy(files[num_files].name, name);
    files[num_files].size = 0;
    num_files++;
    printf("File %s created.\n", name);
}

void delete_file(char *name) {
    int found = 0;
    for(int i = 0; i < num_files; i++) {
        if(strcmp(files[i].name, name) == 0) {
            found = 1;
            for(int j = i; j < num_files-1; j++) {
                strcpy(files[j].name, files[j+1].name);
                strcpy(files[j].content, files[j+1].content);
                files[j].size = files[j+1].size;
            }
            num_files--;
            printf("File %s deleted.\n", name);
        }
    }
    if(!found) {
        printf("Error: File not found!\n");
    }
}

void read_file(char *name) {
    int found = 0;
    for(int i = 0; i < num_files; i++) {
        if(strcmp(files[i].name, name) == 0) {
            found = 1;
            printf("Content of file %s: %s\n", name, files[i].content);
        }
    }
    if(!found) {
        printf("Error: File not found!\n");
    }
}

void write_file(char *name, char *content) {
    int found = 0;
    for(int i = 0; i < num_files; i++) {
        if(strcmp(files[i].name, name) == 0) {
            found = 1;
            if(strlen(content) > MAX_FILE_SIZE) {
                printf("Error: File size too large!\n");
                return;
            }
            strcpy(files[i].content, content);
            files[i].size = strlen(content);
            printf("Content written to file %s.\n", name);
        }
    }
    if(!found) {
        printf("Error: File not found!\n");
    }
}

int main() {
    char command[20];
    char input[50];
    char name[20];
    char content[MAX_FILE_SIZE];

    printf("Welcome to File System Simulation!\n\n");
    while(1) {
        printf("Command list:\n");
        printf("\tcreate <filename>\n");
        printf("\tdelete <filename>\n");
        printf("\tread <filename>\n");
        printf("\twrite <filename> <content>\n");
        printf("\texit\n");

        printf("\nEnter a command: ");
        scanf("%s", command);

        if(strcmp(command, "create") == 0) {
            scanf("%s", name);
            create_file(name);
        } else if(strcmp(command, "delete") == 0) {
            scanf("%s", name);
            delete_file(name);
        } else if(strcmp(command, "read") == 0) {
            scanf("%s", name);
            read_file(name);
        } else if(strcmp(command, "write") == 0) {
            scanf("%s %[^\n]", name, content);
            write_file(name, content);
        } else if(strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Error: Invalid command!\n");
        }
        printf("\n");
    }
    return 0;
}