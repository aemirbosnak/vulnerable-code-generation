//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_SIZE 1024

typedef struct File {
    char name[256];
    int size;
    char data[MAX_FILE_SIZE];
} File;

File files[MAX_FILES];

void backup() {
    FILE *fp;
    int i, j, file_size;
    char filename[256];

    for (i = 0; i < MAX_FILES; i++) {
        if (files[i].name[0] != '\0') {
            printf("Backing up file: %s\n", files[i].name);

            filename[0] = '\0';
            strcpy(filename, files[i].name);
            file_size = files[i].size;

            fp = fopen(filename, "wb");
            fwrite(files[i].data, file_size, 1, fp);
            fclose(fp);
        }
    }
}

int main() {
    int i, choice;

    printf("C File Backup System\n");
    printf("1. Backup\n");
    printf("2. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            backup();
            break;
        case 2:
            exit(0);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}