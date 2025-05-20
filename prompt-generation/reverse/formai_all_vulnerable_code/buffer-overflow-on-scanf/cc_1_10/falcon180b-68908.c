//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000 /* Maximum file size in bytes */
#define MAX_FILES 100 /* Maximum number of files to backup */

typedef struct {
    char filename[100];
    char backup_filename[200];
    int size;
} file_t;

void backup_file(file_t* file) {
    FILE* input_file = fopen(file->filename, "rb");
    FILE* output_file = fopen(file->backup_filename, "wb");

    if (input_file == NULL || output_file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    char buffer[1024];
    int bytes_read;

    while ((bytes_read = fread(buffer, 1, 1024, input_file)) > 0) {
        fwrite(buffer, 1, bytes_read, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    int num_files = 0;
    file_t files[MAX_FILES];

    printf("Enter the number of files to backup: ");
    scanf("%d", &num_files);

    for (int i = 0; i < num_files; i++) {
        printf("Enter the name of file %d: ", i+1);
        scanf("%s", files[i].filename);

        strcat(files[i].backup_filename, files[i].filename);
        strcat(files[i].backup_filename, ".bak");

        files[i].size = 0;
    }

    printf("Backup in progress...\n");

    for (int i = 0; i < num_files; i++) {
        if (files[i].size > MAX_FILE_SIZE) {
            printf("Error: file %s is too large to backup.\n", files[i].filename);
            continue;
        }

        backup_file(&files[i]);
        printf("File %s backed up successfully.\n", files[i].filename);
    }

    return 0;
}