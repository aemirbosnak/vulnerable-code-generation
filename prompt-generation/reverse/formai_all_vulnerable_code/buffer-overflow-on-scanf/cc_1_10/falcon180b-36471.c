//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 32
#define MAX_FILE_SIZE 1024
#define MAX_NUM_FILES 100

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
} File;

File* files[MAX_NUM_FILES];
int num_files;

void init() {
    num_files = 0;
}

int create_file(char* name, int size) {
    if (num_files >= MAX_NUM_FILES) {
        printf("Error: Cannot create more than %d files.\n", MAX_NUM_FILES);
        return -1;
    }

    File* file = malloc(sizeof(File));
    strcpy(file->name, name);
    file->size = size;

    files[num_files++] = file;

    return num_files - 1;
}

int delete_file(int index) {
    if (index < 0 || index >= num_files) {
        printf("Error: Invalid file index.\n");
        return -1;
    }

    free(files[index]);
    for (int i = index; i < num_files - 1; i++) {
        files[i] = files[i + 1];
    }

    num_files--;

    return 0;
}

int rename_file(int index, char* new_name) {
    if (index < 0 || index >= num_files) {
        printf("Error: Invalid file index.\n");
        return -1;
    }

    strcpy(files[index]->name, new_name);

    return 0;
}

int get_file_size(int index) {
    if (index < 0 || index >= num_files) {
        printf("Error: Invalid file index.\n");
        return -1;
    }

    return files[index]->size;
}

int main() {
    init();

    int choice;
    while (1) {
        printf("\n");
        printf("1. Create file\n");
        printf("2. Delete file\n");
        printf("3. Rename file\n");
        printf("4. Get file size\n");
        printf("5. Exit\n");
        printf("\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            char name[MAX_FILE_NAME_LENGTH];
            int size;

            printf("Enter file name: ");
            scanf("%s", name);

            printf("Enter file size: ");
            scanf("%d", &size);

            int index = create_file(name, size);
            printf("File created with index %d.\n", index);

            break;
        }
        case 2: {
            int index;

            printf("Enter file index to delete: ");
            scanf("%d", &index);

            delete_file(index);

            break;
        }
        case 3: {
            int index;
            char new_name[MAX_FILE_NAME_LENGTH];

            printf("Enter file index to rename: ");
            scanf("%d", &index);

            printf("Enter new file name: ");
            scanf("%s", new_name);

            rename_file(index, new_name);

            break;
        }
        case 4: {
            int index;

            printf("Enter file index to get size: ");
            scanf("%d", &index);

            int size = get_file_size(index);
            printf("File size is %d bytes.\n", size);

            break;
        }
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}