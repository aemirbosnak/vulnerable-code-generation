//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    int size;
    char data[MAX_FILE_SIZE];
} File;

int main() {
    int choice;
    char dir_path[MAX_FILE_NAME_LEN];

    printf("Enter directory path: ");
    scanf("%s", dir_path);

    while (1) {
        printf("\n1. Create file\n2. Open file\n3. Delete file\n4. Rename file\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", dir_path);
                strcat(dir_path, ".txt");
                File f;
                f.size = 0;
                strcpy(f.name, dir_path);
                printf("File created successfully.\n");
                break;

            case 2:
                printf("Enter file name: ");
                scanf("%s", dir_path);
                FILE *fp = fopen(dir_path, "r");
                if (fp == NULL) {
                    printf("File not found.\n");
                } else {
                    fclose(fp);
                    printf("File opened successfully.\n");
                }
                break;

            case 3:
                printf("Enter file name: ");
                scanf("%s", dir_path);
                remove(dir_path);
                printf("File deleted successfully.\n");
                break;

            case 4:
                printf("Enter old file name: ");
                scanf("%s", dir_path);
                printf("Enter new file name: ");
                scanf("%s", dir_path);
                rename(dir_path, dir_path);
                printf("File renamed successfully.\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}