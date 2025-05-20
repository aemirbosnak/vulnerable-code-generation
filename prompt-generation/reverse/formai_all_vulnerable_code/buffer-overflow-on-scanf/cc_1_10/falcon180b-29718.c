//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 100000
#define BUFFER_SIZE 1024

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
} file_t;

int main() {

    int num_files = 0;
    file_t files[MAX_FILE_SIZE];

    // Read in the number of files
    printf("Enter the number of files: ");
    scanf("%d", &num_files);

    // Read in the file names and sizes
    for (int i = 0; i < num_files; i++) {
        printf("Enter the name of file %d: ", i+1);
        scanf("%s", files[i].name);
        printf("Enter the size of file %s: ", files[i].name);
        scanf("%d", &files[i].size);
    }

    // Synchronize the files
    for (int i = 0; i < num_files; i++) {
        char filename[MAX_FILE_NAME_LENGTH];
        sprintf(filename, "%s.syn", files[i].name);
        FILE *input_file = fopen(files[i].name, "rb");
        FILE *output_file = fopen(filename, "wb");

        char buffer[BUFFER_SIZE];
        int bytes_read = 0;
        int bytes_written = 0;

        while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0) {
            bytes_written += fwrite(buffer, 1, bytes_read, output_file);
        }

        fclose(input_file);
        fclose(output_file);

        if (bytes_read!= bytes_written) {
            printf("Error synchronizing file %s\n", files[i].name);
        } else {
            printf("File %s synchronized successfully\n", files[i].name);
        }
    }

    return 0;
}