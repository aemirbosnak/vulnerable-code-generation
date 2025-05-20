//FormAI DATASET v1.0 Category: Data recovery tool ; Style: intelligent
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct file {
    char name[50];
    int size;
    bool is_deleted;
};

void recover_data(struct file *files, int num_files) {
    int total_size = 0;
    int num_deleted = 0;
    for (int i = 0; i < num_files; i++) {
        if (!files[i].is_deleted) {
            total_size += files[i].size;
        } else {
            num_deleted++;
        }
    }
    printf("Total recoverable data size: %d bytes\n", total_size);
    printf("Number of files deleted: %d\n", num_deleted);
}

int main() {
    int num_files;
    printf("Enter the number of files: ");
    scanf("%d", &num_files);

    struct file *files = malloc(num_files * sizeof(struct file));
    for (int i = 0; i < num_files; i++) {
        printf("Enter file name and size (separated by a space) for file %d: ", i+1);
        scanf("%s %d", files[i].name, &files[i].size);
        files[i].is_deleted = false;
    }

    printf("\nData recovery tool: \n");
    printf("1. List all files\n");
    printf("2. Recover a file\n");
    printf("3. Exit\n");

    int choice;
    do {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nList of all files: \n");
                for (int i = 0; i < num_files; i++) {
                    printf("%d. %s (%d bytes)\n", i+1, files[i].name, files[i].size);
                }
                break;
            case 2:
                printf("\nEnter the number of the file to recover: ");
                int file_num;
                scanf("%d", &file_num);
                if (file_num > 0 && file_num <= num_files) {
                    if (!files[file_num-1].is_deleted) {
                        printf("File is not deleted!\n");
                    } else {
                        files[file_num-1].is_deleted = false;
                        printf("%s has been recovered.\n", files[file_num-1].name);
                    }
                } else {
                    printf("Invalid file number!");
                }
                break;
            case 3:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    } while (choice != 3);
    
    recover_data(files, num_files);

    free(files);

    return 0;
}