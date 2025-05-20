//FormAI DATASET v1.0 Category: File system simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILENAME 20

struct file {
    char name[MAX_FILENAME];
    char content[100];
};

struct filesystem {
    struct file files[MAX_FILES];
    int num_files;
};

int main() {
    struct filesystem fs;
    fs.num_files = 0;

    printf("Welcome to the File System Simulator!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Create a new file\n");
        printf("2. Delete a file\n");
        printf("3. Read a file\n");
        printf("4. Write to a file\n");
        printf("5. List all files\n");
        printf("6. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char filename[MAX_FILENAME];
                printf("Enter the filename: ");
                scanf("%s", filename);

                if (fs.num_files == MAX_FILES) {
                    printf("ERROR: Maximum number of files reached.\n");
                    break;
                }

                for (int i = 0; i < fs.num_files; i++) {
                    if (strcmp(fs.files[i].name, filename) == 0) {
                        printf("ERROR: File already exists.\n");
                        break;
                    }
                }

                struct file new_file;
                strncpy(new_file.name, filename, MAX_FILENAME);
                new_file.content[0] = '\0';

                fs.files[fs.num_files] = new_file;
                fs.num_files++;

                printf("File created successfully.\n");
                break;
            }

            case 2: {
                char filename[MAX_FILENAME];
                printf("Enter the filename: ");
                scanf("%s", filename);

                int found_file = 0;
                for (int i = 0; i < fs.num_files; i++) {
                    if (strcmp(fs.files[i].name, filename) == 0) {
                        for (int j = i; j < fs.num_files - 1; j++) {
                            fs.files[j] = fs.files[j+1];
                        }
                        fs.num_files--;
                        printf("File deleted successfully.\n");
                        found_file = 1;
                        break;
                    }
                }

                if (!found_file) {
                    printf("ERROR: File not found.\n");
                }
                break;
            }

            case 3: {
                char filename[MAX_FILENAME];
                printf("Enter the filename: ");
                scanf("%s", filename);

                int found_file = 0;
                for (int i = 0; i < fs.num_files; i++) {
                    if (strcmp(fs.files[i].name, filename) == 0) {
                        printf("%s\n", fs.files[i].content);
                        found_file = 1;
                        break;
                    }
                }

                if (!found_file) {
                    printf("ERROR: File not found.\n");
                }
                break;
            }

            case 4: {
                char filename[MAX_FILENAME];
                printf("Enter the filename: ");
                scanf("%s", filename);

                int found_file = 0;
                for (int i = 0; i < fs.num_files; i++) {
                    if (strcmp(fs.files[i].name, filename) == 0) {
                        printf("Enter the new content: ");
                        scanf("%s", fs.files[i].content);
                        printf("Content written successfully.\n");
                        found_file = 1;
                        break;
                    }
                }

                if (!found_file) {
                    printf("ERROR: File not found.\n");
                }
                break;
            }

            case 5: {
                printf("Listing all files:\n");
                for (int i = 0; i < fs.num_files; i++) {
                    printf("%s\n", fs.files[i].name);
                }
                break;
            }

            case 6: {
                printf("Goodbye!\n");
                exit(0);
            }

            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    }
    return 0;
}