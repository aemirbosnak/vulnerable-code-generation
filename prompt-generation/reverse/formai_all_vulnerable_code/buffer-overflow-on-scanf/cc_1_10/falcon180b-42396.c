//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_SIZE 100000

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    int file_size;
    int file_type;
    char file_data[MAX_FILE_SIZE];
} File;

int main() {
    int num_files, i;
    File files[10];

    printf("Enter the number of files you want to create: ");
    scanf("%d", &num_files);

    for (i = 0; i < num_files; i++) {
        printf("\nEnter the filename for file %d: ", i+1);
        scanf(" %[^\n]", files[i].filename);

        printf("Enter the file size for file %s: ", files[i].filename);
        scanf("%d", &files[i].file_size);

        printf("Enter the file type for file %s (0 for text, 1 for binary): ", files[i].filename);
        scanf("%d", &files[i].file_type);

        if (files[i].file_type == 0) {
            printf("Enter the file data for file %s: ", files[i].filename);
            scanf(" %[^\n]", files[i].file_data);
        }
    }

    printf("\nFile System Simulation\n");
    printf("=======================\n");

    for (i = 0; i < num_files; i++) {
        printf("\n%s\n", files[i].filename);
        printf("File Size: %d bytes\n", files[i].file_size);
        printf("File Type: %s\n", files[i].file_type == 0? "Text" : "Binary");

        if (files[i].file_type == 0) {
            printf("File Data:\n%s\n", files[i].file_data);
        }
    }

    return 0;
}