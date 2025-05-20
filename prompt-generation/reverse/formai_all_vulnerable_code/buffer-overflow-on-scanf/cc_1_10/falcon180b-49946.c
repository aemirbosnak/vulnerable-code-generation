//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILES 100

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
} File;

File files[MAX_FILES];
int num_files;

void create_file(char* name, int size) {
    if (num_files >= MAX_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }

    strcpy(files[num_files].name, name);
    files[num_files].size = size;
    num_files++;
}

void delete_file(char* name) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memmove(&files[i], &files[i+1], sizeof(File) * (num_files - i - 1));
            num_files--;
            return;
        }
    }

    printf("Error: File not found.\n");
}

void display_files() {
    int i;

    for (i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

int main() {
    char choice;
    char filename[MAX_FILE_NAME_LENGTH];

    printf("Welcome to the Simple File System!\n");
    printf("Commands:\n");
    printf("c - Create file\n");
    printf("d - Delete file\n");
    printf("s - Display files\n");
    printf("q - Quit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case 'c':
                printf("Enter file name: ");
                scanf("%s", filename);
                printf("Enter file size: ");
                scanf("%d", &files[num_files].size);
                create_file(filename, files[num_files].size);
                break;

            case 'd':
                printf("Enter file name to delete: ");
                scanf("%s", filename);
                delete_file(filename);
                break;

            case's':
                display_files();
                break;

            case 'q':
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}