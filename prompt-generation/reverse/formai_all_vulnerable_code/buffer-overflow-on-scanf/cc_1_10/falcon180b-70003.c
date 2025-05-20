//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_SIZE 1024
#define MAX_NUM_FILES 10

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
    char file_content[MAX_FILE_SIZE];
} File;

File file_system[MAX_NUM_FILES];
int num_files;

void create_file(char* file_name, int file_size, char* file_content) {
    int i;
    for(i=0; i<num_files; i++) {
        if(strcmp(file_system[i].file_name, file_name) == 0) {
            printf("File already exists.\n");
            return;
        }
    }
    if(num_files >= MAX_NUM_FILES) {
        printf("File system full.\n");
        return;
    }
    strcpy(file_system[num_files].file_name, file_name);
    file_system[num_files].file_size = file_size;
    strcpy(file_system[num_files].file_content, file_content);
    num_files++;
}

void read_file(char* file_name) {
    int i;
    for(i=0; i<num_files; i++) {
        if(strcmp(file_system[i].file_name, file_name) == 0) {
            printf("File content: %s\n", file_system[i].file_content);
            return;
        }
    }
    printf("File not found.\n");
}

void delete_file(char* file_name) {
    int i;
    for(i=0; i<num_files; i++) {
        if(strcmp(file_system[i].file_name, file_name) == 0) {
            memset(file_system[i].file_name, 0, MAX_FILE_NAME_LENGTH);
            memset(file_system[i].file_content, 0, MAX_FILE_SIZE);
            num_files--;
            return;
        }
    }
    printf("File not found.\n");
}

int main() {
    int choice, file_size;
    char file_name[MAX_FILE_NAME_LENGTH], file_content[MAX_FILE_SIZE];

    num_files = 0;

    while(1) {
        printf("\nFile System Simulation\n");
        printf("1. Create file\n2. Read file\n3. Delete file\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", file_name);
                printf("Enter file size: ");
                scanf("%d", &file_size);
                printf("Enter file content: ");
                scanf("%s", file_content);
                create_file(file_name, file_size, file_content);
                break;
            case 2:
                printf("Enter file name: ");
                scanf("%s", file_name);
                read_file(file_name);
                break;
            case 3:
                printf("Enter file name: ");
                scanf("%s", file_name);
                delete_file(file_name);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}