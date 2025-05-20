//FormAI DATASET v1.0 Category: File system simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILENAME_SIZE 20
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_FILENAME_SIZE];
    int size;
    char data[MAX_FILE_SIZE];
} File;

int main() {
    File file_system[MAX_FILES];
    int num_files = 0;

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Create a new file\n");
        printf("2. View an existing file\n");
        printf("3. Edit an existing file\n");
        printf("4. Delete an existing file\n");
        printf("5. List all existing files\n");
        printf("6. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (num_files == MAX_FILES) {
                    printf("Cannot create a new file, maximum number of files reached.\n");
                    break;
                }

                printf("Enter the name of the new file (maximum %d characters): ", MAX_FILENAME_SIZE-1);
                char name[MAX_FILENAME_SIZE];
                scanf("%s", name);

                for (int i = 0; i < num_files; i++) {
                    if (strcmp(name, file_system[i].name) == 0) {
                        printf("File already exists!\n");
                        goto end;
                    }
                }

                strcpy(file_system[num_files].name, name);

                printf("Enter the size of the new file (in bytes): ");
                scanf("%d", &file_system[num_files].size);

                printf("Enter the contents of the new file (maximum %d characters): ", MAX_FILE_SIZE-1);
                scanf("%s", file_system[num_files].data);

                printf("File created!\n");

                num_files++;

                end:
                break;
            }

            case 2: {
                if (num_files == 0) {
                    printf("No files exist.\n");
                    break;
                }

                printf("Enter the name of the file you want to view: ");
                char name[MAX_FILENAME_SIZE];
                scanf("%s", name);

                int found = 0;

                for (int i = 0; i < num_files; i++) {
                    if (strcmp(name, file_system[i].name) == 0) {
                        printf("Name: %s\n", file_system[i].name);
                        printf("Size: %d bytes\n", file_system[i].size);
                        printf("Data: %s\n", file_system[i].data);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("File not found!\n");
                }

                break;
            }

            case 3: {
                if (num_files == 0) {
                    printf("No files exist.\n");
                    break;
                }

                printf("Enter the name of the file you want to edit: ");
                char name[MAX_FILENAME_SIZE];
                scanf("%s", name);

                int found = 0;

                for (int i = 0; i < num_files; i++) {
                    if (strcmp(name, file_system[i].name) == 0) {
                        printf("Current contents of the file: %s\n", file_system[i].data);
                        printf("Enter the new contents of the file (maximum %d characters): ", MAX_FILE_SIZE-1);
                        scanf("%s", file_system[i].data);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("File not found!\n");
                }
                
                break;
            }

            case 4: {
                if (num_files == 0) {
                    printf("No files exist.\n");
                    break;
                }

                printf("Enter the name of the file you want to delete: ");
                char name[MAX_FILENAME_SIZE];
                scanf("%s", name);

                int found = 0;

                for (int i = 0; i < num_files; i++) {
                    if (strcmp(name, file_system[i].name) == 0) {
                        for (int j = i; j < num_files-1; j++) {
                            strcpy(file_system[j].name, file_system[j+1].name);
                            file_system[j].size = file_system[j+1].size;
                            strcpy(file_system[j].data, file_system[j+1].data);
                        }
                        num_files--;
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("File not found!\n");
                }
                
                break;
            }

            case 5: {
                if (num_files == 0) {
                    printf("No files exist.\n");
                    break;
                }

                printf("List of all files:\n");

                for (int i = 0; i < num_files; i++) {
                    printf("%s\n", file_system[i].name);
                }

                break;
            }

            case 6: {
                exit(0);
            }

            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }
}