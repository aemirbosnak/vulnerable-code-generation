//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_FILE_NAME 100

typedef struct {
    char file_name[MAX_FILE_NAME];
    int size;
    int deleted;
} File;

int main() {
    int num_files;
    File *files;

    printf("Enter the number of files: ");
    scanf("%d", &num_files);

    files = (File *) malloc(num_files * sizeof(File));

    for (int i = 0; i < num_files; i++) {
        printf("Enter file name (%d/%d): ", i+1, num_files);
        scanf("%s", files[i].file_name);
        files[i].size = 0;
        files[i].deleted = FALSE;
    }

    printf("Enter the name of the file to delete: ");
    scanf("%s", files[0].file_name);

    int file_deleted = FALSE;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].file_name, files[0].file_name) == 0) {
            files[i].deleted = TRUE;
            file_deleted = TRUE;
        }
    }

    if (!file_deleted) {
        printf("File not found.\n");
        return 1;
    }

    int num_deleted_files = 0;
    for (int i = 0; i < num_files; i++) {
        if (files[i].deleted) {
            num_deleted_files++;
        }
    }

    int num_deleted_blocks = 0;
    for (int i = 0; i < num_files; i++) {
        if (files[i].deleted) {
            num_deleted_blocks += files[i].size / 512;
        }
    }

    printf("Number of deleted files: %d\n", num_deleted_files);
    printf("Number of deleted blocks: %d\n", num_deleted_blocks);

    free(files);

    return 0;
}