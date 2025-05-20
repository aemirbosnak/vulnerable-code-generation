//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

// Structure for each file in the system
typedef struct {
    char name[20];
    int size;
} File;

// Structure for the file system
typedef struct {
    File files[SIZE];
    int num_files;
} FileSystem;

// Function to initialize the file system
void init(FileSystem* fs) {
    fs->num_files = 0;
}

// Function to create a new file
void create_file(FileSystem* fs, char* name, int size) {
    if (fs->num_files >= SIZE) {
        printf("File system is full!\n");
        return;
    }

    strcpy(fs->files[fs->num_files].name, name);
    fs->files[fs->num_files].size = size;
    fs->num_files++;
}

// Function to delete a file
void delete_file(FileSystem* fs, char* name) {
    int i;

    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            fs->num_files--;
            break;
        }
    }
}

// Function to display all files in the system
void display_files(FileSystem* fs) {
    int i;

    for (i = 0; i < fs->num_files; i++) {
        printf("%s - %d bytes\n", fs->files[i].name, fs->files[i].size);
    }
}

// Main function
int main() {
    FileSystem fs;
    init(&fs);

    while (1) {
        printf("1. Create file\n");
        printf("2. Delete file\n");
        printf("3. Display files\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[20];
                int size;

                printf("Enter file name: ");
                scanf("%s", name);
                printf("Enter file size: ");
                scanf("%d", &size);

                create_file(&fs, name, size);
                break;
            }

            case 2: {
                char name[20];

                printf("Enter file name: ");
                scanf("%s", name);

                delete_file(&fs, name);
                break;
            }

            case 3:
                display_files(&fs);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}