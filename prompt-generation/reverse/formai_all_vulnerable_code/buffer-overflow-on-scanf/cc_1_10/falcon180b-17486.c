//Falcon-180B DATASET v1.0 Category: File handling ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_DATA_LENGTH 10000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char data[MAX_FILE_DATA_LENGTH];
} File;

File* create_file(char* name, char* data) {
    File* file = (File*)malloc(sizeof(File));
    strcpy(file->name, name);
    strcpy(file->data, data);
    return file;
}

void delete_file(File* file) {
    free(file);
}

void print_file(File* file) {
    printf("Name: %s\nData: %s\n", file->name, file->data);
}

int main() {
    int choice;
    char file_name[MAX_FILE_NAME_LENGTH];
    char file_data[MAX_FILE_DATA_LENGTH];
    File* file = NULL;

    do {
        printf("1. Create file\n2. Delete file\n3. Print file\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", file_name);
                printf("Enter file data: ");
                scanf("%s", file_data);
                file = create_file(file_name, file_data);
                break;
            case 2:
                if (file!= NULL) {
                    delete_file(file);
                    file = NULL;
                }
                break;
            case 3:
                if (file!= NULL) {
                    print_file(file);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while(1);

    return 0;
}