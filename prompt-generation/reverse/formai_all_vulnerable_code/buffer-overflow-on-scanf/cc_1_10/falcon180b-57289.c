//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LEN 256

typedef struct {
    char filename[MAX_FILENAME_LEN];
    int file_size;
    char backup_filename[MAX_FILENAME_LEN];
} file_backup_t;

void create_backup_filename(char* filename, char* backup_filename) {
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");
}

int main() {
    int num_files;
    file_backup_t files[100];

    printf("Enter the number of files to backup: ");
    scanf("%d", &num_files);

    // Input file information
    for (int i = 0; i < num_files; i++) {
        printf("Enter the filename for file %d: ", i+1);
        scanf("%s", files[i].filename);
        printf("Enter the file size for file %s: ", files[i].filename);
        scanf("%d", &files[i].file_size);
        create_backup_filename(files[i].filename, files[i].backup_filename);
    }

    // Backup files
    for (int i = 0; i < num_files; i++) {
        FILE* input_file = fopen(files[i].filename, "rb");
        FILE* output_file = fopen(files[i].backup_filename, "wb");

        char buffer[1024];
        int bytes_read;

        while ((bytes_read = fread(buffer, 1, 1024, input_file)) > 0) {
            fwrite(buffer, 1, bytes_read, output_file);
        }

        fclose(input_file);
        fclose(output_file);

        printf("File %s backed up successfully!\n", files[i].filename);
    }

    return 0;
}