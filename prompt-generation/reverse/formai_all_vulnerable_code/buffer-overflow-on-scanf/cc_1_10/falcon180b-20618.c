//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_SIZE 1024

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
    char file_content[MAX_FILE_SIZE];
} file_t;

int main() {
    int num_files = 0;
    file_t *files = NULL;

    while (num_files == 0) {
        printf("Enter the number of files you want to create (between 1 and 10): ");
        scanf("%d", &num_files);

        if (num_files < 1 || num_files > 10) {
            printf("Invalid number of files. Please enter a number between 1 and 10.\n");
        }
    }

    files = (file_t *)malloc(num_files * sizeof(file_t));

    for (int i = 0; i < num_files; i++) {
        printf("Enter the name of file %d: ", i + 1);
        scanf("%s", files[i].file_name);

        printf("Enter the size of file %s (in bytes): ", files[i].file_name);
        scanf("%d", &files[i].file_size);

        if (files[i].file_size > MAX_FILE_SIZE) {
            printf("Invalid file size. File size must be less than or equal to %d bytes.\n", MAX_FILE_SIZE);
            num_files = 0;
            break;
        }

        printf("Enter the content of file %s: ", files[i].file_name);
        scanf("%s", files[i].file_content);
    }

    printf("\nFile system created:\n");
    for (int i = 0; i < num_files; i++) {
        printf("File %s: %d bytes\n", files[i].file_name, files[i].file_size);
        printf("%s\n", files[i].file_content);
    }

    free(files);
    return 0;
}