//FormAI DATASET v1.0 Category: File system simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_NAME_SZ 32
#define MAX_FILE_SZ 1024

typedef struct _File {
    char name[MAX_NAME_SZ];
    char contents[MAX_FILE_SZ];
} File;

File fileSystem[MAX_FILES];

int main() {
    int i, choice;
    char fileName[MAX_NAME_SZ], buffer[MAX_FILE_SZ];

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Create a file\n");
        printf("2. Delete a file\n");
        printf("3. Read a file\n");
        printf("4. Write to a file\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (i < MAX_FILES) {
                    printf("Enter file name: ");
                    scanf("%s", fileName);

                    for (i = 0; i < MAX_FILES; i++) {
                        if (!strcmp(fileSystem[i].name, fileName)) {
                            printf("File already exists.\n");
                            break;
                        }
                    }

                    if (i == MAX_FILES) {
                        strncpy(fileSystem[i].name, fileName, MAX_NAME_SZ);
                        printf("File created.\n");
                    }
                } else {
                    printf("Maximum number of files reached.\n");
                }

                break;

            case 2:
                printf("Enter file name: ");
                scanf("%s", fileName);

                for (i = 0; i < MAX_FILES; i++) {
                    if (!strcmp(fileSystem[i].name, fileName)) {
                        memset(&fileSystem[i], 0, sizeof(File));
                        break;
                    }
                }

                if (i == MAX_FILES) {
                    printf("File not found.\n");
                } else {
                    printf("File deleted.\n");
                }

                break;

            case 3:
                printf("Enter file name: ");
                scanf("%s", fileName);

                for (i = 0; i < MAX_FILES; i++) {
                    if (!strcmp(fileSystem[i].name, fileName)) {
                        printf("File contents:\n%s\n", fileSystem[i].contents);
                        break;
                    }
                }

                if (i == MAX_FILES) {
                    printf("File not found.\n");
                }

                break;

            case 4:
                printf("Enter file name: ");
                scanf("%s", fileName);

                for (i = 0; i < MAX_FILES; i++) {
                    if (!strcmp(fileSystem[i].name, fileName)) {
                        printf("Enter text:\n");
                        scanf(" %[^\n]s", buffer);

                        // Make sure input fits within file size limit
                        if (strlen(buffer) > MAX_FILE_SZ) {
                            printf("File too large.\n");
                            break;
                        }

                        strncpy(fileSystem[i].contents, buffer, MAX_FILE_SZ);
                        printf("File written to.\n");
                        break;
                    }
                }

                if (i == MAX_FILES) {
                    printf("File not found.\n");
                }

                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}