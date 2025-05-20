//FormAI DATASET v1.0 Category: File system simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 20
#define NUM_FILES 5

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    int size;
} file_t;

void show_menu() {
    printf("\nWelcome to the CyberFS!\n");
    printf("1. List files\n");
    printf("2. Add file\n");
    printf("3. Remove file\n");
    printf("4. Exit\n");
}

void list_files(file_t files[], int num_files) {
    if (num_files == 0) {
        printf("No files found!\n");
    } else {
        printf("File list:\n");
        for (int i = 0; i < num_files; i++) {
            printf("%s\t%d KB\n", files[i].filename, files[i].size);
        }
    }
}

void add_file(file_t files[], int *num_files) {
    if (*num_files == NUM_FILES) {
        printf("Maximum number of files reached!\n");
    } else {
        char filename[MAX_FILENAME_LENGTH];
        int size;

        printf("Enter filename (up to %d characters):\n", MAX_FILENAME_LENGTH);
        scanf("%s", filename);

        printf("Enter file size (in KB):\n");
        scanf("%d", &size);

        strcpy(files[*num_files].filename, filename);
        files[*num_files].size = size;

        printf("File added!\n");

        (*num_files)++;
    }
}

void remove_file(file_t files[], int *num_files) {
    if (*num_files == 0) {
        printf("No files found!\n");
    } else {
        char filename[MAX_FILENAME_LENGTH];
    
        printf("Enter filename to remove:\n");
        scanf("%s", filename);
        
        int found = 0;
        for (int i = 0; i < *num_files; i++) {
            if (strcmp(files[i].filename, filename) == 0) {
                found = 1;
                for (int j = i; j < *num_files - 1; j++) {
                    strcpy(files[j].filename, files[j+1].filename);
                    files[j].size = files[j+1].size;
                }
                (*num_files)--;
                printf("File removed!\n");
                break;
            }
        }
        if (!found) {
            printf("File not found!\n");
        }
    }
}

int main() {
    file_t files[NUM_FILES];
    int num_files = 0;
    int choice;

    do {
        show_menu();

        printf("Enter choice (1-4):\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list_files(files, num_files);
                break;
            case 2:
                add_file(files, &num_files);
                break;
            case 3:
                remove_file(files, &num_files);
                break;
            case 4:
                printf("Exiting CyberFS...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}