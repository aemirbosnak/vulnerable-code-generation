//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1024
#define MAX_FILES 100

typedef struct {
    char filename[20];
    char content[MAX_FILE_SIZE];
    int size;
} File;

void create_file(File* file) {
    printf("Enter filename: ");
    scanf("%s", file->filename);
    printf("Enter content: ");
    fgets(file->content, MAX_FILE_SIZE, stdin);
    file->size = strlen(file->content);
}

void read_file(File* file) {
    printf("Content of %s:\n%s\n", file->filename, file->content);
}

void delete_file(File* file) {
    printf("Deleting %s...\n", file->filename);
}

int main() {
    File files[MAX_FILES];
    int num_files = 0;

    while (num_files < MAX_FILES) {
        printf("\n1. Create file\n2. Read file\n3. Delete file\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_files >= MAX_FILES) {
                    printf("Maximum number of files reached.\n");
                } else {
                    create_file(&files[num_files]);
                    num_files++;
                }
                break;
            case 2:
                printf("Enter filename: ");
                scanf("%s", files[num_files-1].filename);
                read_file(&files[num_files-1]);
                break;
            case 3:
                printf("Enter filename: ");
                scanf("%s", files[num_files-1].filename);
                delete_file(&files[num_files-1]);
                num_files--;
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}