//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LEN 50

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    int size;
} File;

File files[MAX_FILES];
int num_files;

void create_file(char *name, int size) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("File already exists.\n");
            return;
        }
    }
    if (num_files >= MAX_FILES) {
        printf("No more space for files.\n");
        return;
    }
    strcpy(files[num_files].name, name);
    files[num_files].size = size;
    num_files++;
}

void delete_file(char *name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memmove(&files[i], &files[i+1], (num_files-i-1)*sizeof(File));
            num_files--;
            return;
        }
    }
    printf("File not found.\n");
}

void list_files() {
    int i;
    for (i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

int main() {
    srand(time(NULL));
    int choice, size;
    char name[MAX_FILE_NAME_LEN];

    num_files = 0;

    while (1) {
        printf("1. Create file\n2. Delete file\n3. List files\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", name);
                printf("Enter file size (bytes): ");
                scanf("%d", &size);
                create_file(name, size);
                break;
            case 2:
                printf("Enter file name: ");
                scanf("%s", name);
                delete_file(name);
                break;
            case 3:
                list_files();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}