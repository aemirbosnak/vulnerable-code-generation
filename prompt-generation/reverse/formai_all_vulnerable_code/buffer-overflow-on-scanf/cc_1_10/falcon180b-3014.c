//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define MAX_FILE_NAME 100
#define MAX_FILE_SIZE 1000

typedef struct {
    char name[MAX_FILE_NAME];
    int size;
    char content[MAX_FILE_SIZE];
} File;

void create_file(File *file) {
    printf("Enter the file name: ");
    scanf("%s", file->name);
    printf("Enter the file size: ");
    scanf("%d", &file->size);
    printf("Enter the file content: ");
    fgets(file->content, MAX_FILE_SIZE, stdin);
    file->content[strcspn(file->content, "\n")] = '\0'; // Remove the newline character
}

void display_file(File file) {
    printf("File name: %s\nFile size: %d\nFile content:\n%s", file.name, file.size, file.content);
}

void rename_file(File *file) {
    printf("Enter the new file name: ");
    scanf("%s", file->name);
}

void delete_file(File *file) {
    printf("File %s has been deleted.\n", file->name);
}

void copy_file(File *src_file, File *dest_file) {
    strcpy(dest_file->name, src_file->name);
    dest_file->size = src_file->size;
    strcpy(dest_file->content, src_file->content);
}

void move_file(File *src_file, File *dest_file) {
    rename_file(src_file);
    copy_file(src_file, dest_file);
    delete_file(src_file);
}

int main() {
    File file1, file2;
    int choice;

    do {
        printf("\n\nFile System Simulation\n");
        printf("1. Create file\n2. Display file\n3. Rename file\n4. Delete file\n5. Copy file\n6. Move file\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_file(&file1);
                break;
            case 2:
                display_file(file1);
                break;
            case 3:
                rename_file(&file1);
                break;
            case 4:
                delete_file(&file1);
                break;
            case 5:
                printf("Enter the destination file name: ");
                scanf("%s", file2.name);
                copy_file(&file1, &file2);
                break;
            case 6:
                printf("Enter the destination file name: ");
                scanf("%s", file2.name);
                move_file(&file1, &file2);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (TRUE);

    return 0;
}