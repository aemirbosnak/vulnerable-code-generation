//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1000000
#define MAX_NUM_FILES 100

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
    char file_data[MAX_FILE_SIZE];
} File;

int num_files = 0;
File files[MAX_NUM_FILES];

int main() {
    int choice;
    while (1) {
        printf("1. Create file\n");
        printf("2. Read file\n");
        printf("3. Write file\n");
        printf("4. Delete file\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_files >= MAX_NUM_FILES) {
                printf("Error: Maximum number of files reached.\n");
            } else {
                char file_name[MAX_FILE_NAME_LENGTH];
                printf("Enter file name: ");
                scanf("%s", file_name);

                if (strlen(file_name) > MAX_FILE_NAME_LENGTH) {
                    printf("Error: File name too long.\n");
                } else {
                    files[num_files].file_name[0] = '\0';
                    strcpy(files[num_files].file_name, file_name);
                    printf("File created successfully.\n");
                    num_files++;
                }
            }
            break;
        case 2:
            if (num_files == 0) {
                printf("Error: No files found.\n");
            } else {
                int file_index;
                printf("Enter file index: ");
                scanf("%d", &file_index);

                if (file_index < 0 || file_index >= num_files) {
                    printf("Error: Invalid file index.\n");
                } else {
                    printf("File contents:\n%s\n", files[file_index].file_data);
                }
            }
            break;
        case 3:
            if (num_files == 0) {
                printf("Error: No files found.\n");
            } else {
                int file_index;
                printf("Enter file index: ");
                scanf("%d", &file_index);

                if (file_index < 0 || file_index >= num_files) {
                    printf("Error: Invalid file index.\n");
                } else {
                    printf("Enter new file contents: ");
                    scanf("%s", files[file_index].file_data);
                }
            }
            break;
        case 4:
            if (num_files == 0) {
                printf("Error: No files found.\n");
            } else {
                int file_index;
                printf("Enter file index: ");
                scanf("%d", &file_index);

                if (file_index < 0 || file_index >= num_files) {
                    printf("Error: Invalid file index.\n");
                } else {
                    if (remove(files[file_index].file_name) == 0) {
                        printf("File deleted successfully.\n");
                        num_files--;
                    } else {
                        printf("Error: File not found.\n");
                    }
                }
            }
            break;
        case 5:
            exit(0);
        default:
            printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}