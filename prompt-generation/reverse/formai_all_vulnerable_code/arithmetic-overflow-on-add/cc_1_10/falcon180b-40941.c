//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 255
#define MAX_FILE_SIZE 1000000

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
    char file_data[MAX_FILE_SIZE];
} File;

File* create_file(char* file_name) {
    File* new_file = malloc(sizeof(File));
    strcpy(new_file->file_name, file_name);
    new_file->file_size = 0;
    return new_file;
}

void delete_file(File* file) {
    free(file);
}

void write_file(File* file, char* data, int data_size) {
    if (file->file_size + data_size > MAX_FILE_SIZE) {
        printf("Error: File is full.\n");
        return;
    }
    strcat(file->file_data, data);
    file->file_size += data_size;
}

void read_file(File* file, int offset, int size, char* buffer) {
    int end_offset = offset + size;
    if (end_offset > file->file_size) {
        end_offset = file->file_size;
    }
    strncpy(buffer, file->file_data + offset, end_offset - offset);
}

int main() {
    int choice;
    char file_name[MAX_FILE_NAME_LENGTH];
    File* file = NULL;

    while (1) {
        printf("1. Create File\n2. Open File\n3. Write File\n4. Read File\n5. Delete File\n6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", file_name);
                file = create_file(file_name);
                break;
            case 2:
                printf("File opened successfully.\n");
                break;
            case 3:
                printf("Enter data to write: ");
                char data[1000];
                scanf("%s", data);
                write_file(file, data, strlen(data));
                break;
            case 4:
                printf("Enter offset: ");
                int offset;
                scanf("%d", &offset);
                printf("Enter size: ");
                int size;
                scanf("%d", &size);
                char buffer[1000];
                read_file(file, offset, size, buffer);
                printf("Data read: %s\n", buffer);
                break;
            case 5:
                delete_file(file);
                file = NULL;
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}