//FormAI DATASET v1.0 Category: File system simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define MAX_FILENAME_LENGTH 256
#define MAX_FILES 64

typedef struct file {
    char name[MAX_FILENAME_LENGTH];
    int size;
    char data[MAX_FILE_SIZE];
} File;

File files[MAX_FILES];
int num_files = 0;

void print_menu() {
    printf("\n\nFileSystem Simulation\n");
    printf("1) Create a file\n");
    printf("2) Delete a file\n");
    printf("3) List all files\n");
    printf("4) Read a file\n");
    printf("5) Write to a file\n");
    printf("6) Exit\n");
}

int get_choice() {
    int choice;
    printf("\nEnter choice: ");
    scanf("%d", &choice);
    return choice;
}

void create_file() {
    if(num_files == MAX_FILES) {
        printf("FileSystem is full!\n");
        return;
    }

    File f;
    printf("\nEnter filename: ");
    scanf("%s", f.name);
    printf("Enter file size in bytes: ");
    scanf("%d", &f.size);
    printf("Enter file data:\n");
    scanf("%s", f.data);

    files[num_files++] = f;
    printf("\nFile created successfully!\n");
}

void delete_file() {
    char filename[MAX_FILENAME_LENGTH];
    printf("\nEnter filename to delete: ");
    scanf("%s", filename);

    int i;
    for(i = 0; i < num_files; i++) {
        if(strcmp(files[i].name, filename) == 0) {
            memcpy(&files[i], &files[num_files-1], sizeof(File));
            num_files--;
            printf("\nFile deleted successfully!\n");
            return;
        }
    }
    printf("\nFile not found!\n");
}

void list_files() {
    if(num_files == 0) {
        printf("\nFileSystem is empty!\n");
        return;
    }

    int i;
    printf("\n%-20s %-10s\n", "Filename", "Size");
    for(i = 0; i < num_files; i++) {
        printf("%-20s %-10d\n", files[i].name, files[i].size);
    }
}

void read_file() {
    char filename[MAX_FILENAME_LENGTH];
    printf("\nEnter filename to read: ");
    scanf("%s", filename);

    int i;
    for(i = 0; i < num_files; i++) {
        if(strcmp(files[i].name, filename) == 0) {
            printf("\n%s\n", files[i].data);
            return;
        }
    }
    printf("\nFile not found!\n");
}

void write_file() {
    char filename[MAX_FILENAME_LENGTH];
    printf("\nEnter filename to write: ");
    scanf("%s", filename);

    int i;
    for(i = 0; i < num_files; i++) {
        if(strcmp(files[i].name, filename) == 0) {
            printf("Enter file data:\n");
            scanf("%s", files[i].data);
            printf("\nFile updated successfully!\n");
            return;
        }
    }
    printf("\nFile not found!\n");
}

int main() {
    int choice;

    do {
        print_menu();
        choice = get_choice();

        switch(choice) {
            case 1:
                create_file();
                break;
            case 2:
                delete_file();
                break;
            case 3:
                list_files();
                break;
            case 4:
                read_file();
                break;
            case 5:
                write_file();
                break;
            case 6:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while(choice != 6);

    return 0;
}