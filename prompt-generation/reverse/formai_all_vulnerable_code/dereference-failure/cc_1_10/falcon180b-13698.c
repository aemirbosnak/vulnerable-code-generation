//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *fp1, *fp2;
    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
    int bytes_read1, bytes_read2;
    long file_size1, file_size2;

    // Open source file
    fp1 = fopen(argv[1], "rb");
    if (fp1 == NULL) {
        printf("Error opening source file.\n");
        exit(1);
    }

    // Get file size of source file
    fseek(fp1, 0, SEEK_END);
    file_size1 = ftell(fp1);
    rewind(fp1);

    // Open destination file
    fp2 = fopen(argv[2], "wb");
    if (fp2 == NULL) {
        printf("Error opening destination file.\n");
        exit(1);
    }

    // Get file size of destination file
    fseek(fp2, 0, SEEK_END);
    file_size2 = ftell(fp2);
    rewind(fp2);

    // Synchronize files
    if (file_size1 == file_size2) {
        printf("Files are already synchronized.\n");
        exit(0);
    }

    if (file_size1 > file_size2) {
        printf("Copying data from source to destination file.\n");
        while ((bytes_read1 = fread(buffer1, sizeof(char), BUFFER_SIZE, fp1)) > 0) {
            fwrite(buffer1, sizeof(char), bytes_read1, fp2);
        }
    } else {
        printf("Copying data from destination to source file.\n");
        while ((bytes_read2 = fread(buffer2, sizeof(char), BUFFER_SIZE, fp2)) > 0) {
            fwrite(buffer2, sizeof(char), bytes_read2, fp1);
        }
    }

    printf("Files synchronized successfully.\n");

    fclose(fp1);
    fclose(fp2);

    return 0;
}