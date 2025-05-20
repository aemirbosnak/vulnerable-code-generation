//FormAI DATASET v1.0 Category: File system simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 20
#define MAX_FILE_CONTENT_LENGTH 100

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
} File;

int main() {
    int option, num_files = 0;
    char name[MAX_FILENAME_LENGTH], content[MAX_FILE_CONTENT_LENGTH];
    File* files = malloc(sizeof(File));

    do {
        // Print options
        printf("Options:\n");
        printf("1. Create file\n");
        printf("2. Delete file\n");
        printf("3. List files\n");
        printf("4. Quit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                // Create file
                printf("Enter file name: ");
                scanf("%s", name);
                printf("Enter file content: ");
                scanf("%s", content);

                // Add file to array
                files = realloc(files, sizeof(File) * ++num_files);
                strcpy(files[num_files - 1].name, name);
                strcpy(files[num_files - 1].content, content);
                printf("File \"%s\" created.\n", name);
                break;

            case 2:
                // Delete file
                printf("Enter file name: ");
                scanf("%s", name);

                // Find and remove file from array
                int found = 0;
                for (int i = 0; i < num_files; ++i) {
                    if (strcmp(files[i].name, name) == 0) {
                        found = 1;
                        memmove(&files[i], &files[i + 1], sizeof(File) * (num_files - i));
                        --num_files;
                        break;
                    }
                }

                if (found) {
                    printf("File \"%s\" deleted.\n", name);
                } else {
                    printf("File \"%s\" not found.\n", name);
                }
                break;

            case 3:
                // List files
                printf("Files:\n");
                for (int i = 0; i < num_files; ++i) {
                    printf("%s: %s\n", files[i].name, files[i].content);
                }
                break;

            case 4:
                // Quit
                break;

            default:
                printf("Invalid option.\n");
                break;
        }
    } while (option != 4);

    // Free dynamically allocated memory
    free(files);

    return 0;
}