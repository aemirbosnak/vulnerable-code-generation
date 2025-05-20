//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME 50
#define MAX_FILE_SIZE 100

typedef struct {
    char name[MAX_FILE_NAME];
    char extension[10];
    int size;
    int is_deleted;
} File;

File files[MAX_FILES];

int num_files = 0;
int num_deleted_files = 0;

void create_file(char* name, char* extension, int size) {
    strcpy(files[num_files].name, name);
    strcpy(files[num_files].extension, extension);
    files[num_files].size = size;
    files[num_files].is_deleted = 0;
    num_files++;
}

void delete_file(int index) {
    strcpy(files[index].name, "DELETED");
    files[index].is_deleted = 1;
    num_deleted_files++;
}

void list_files() {
    printf("File List:\n");
    for (int i = 0; i < num_files; i++) {
        if (!files[i].is_deleted) {
            printf("%s.%s - %d bytes\n", files[i].name, files[i].extension, files[i].size);
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int choice;
    char name[MAX_FILE_NAME];
    char extension[10];
    int size;
    int index;

    do {
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. List Files\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", name);
                printf("Enter file extension: ");
                scanf("%s", extension);
                printf("Enter file size: ");
                scanf("%d", &size);
                create_file(name, extension, size);
                break;
            case 2:
                printf("Enter file index to delete: ");
                scanf("%d", &index);
                if (index >= 0 && index < num_files) {
                    delete_file(index);
                } else {
                    printf("Invalid file index.\n");
                }
                break;
            case 3:
                list_files();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}