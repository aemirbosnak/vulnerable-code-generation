//FormAI DATASET v1.0 Category: Data recovery tool ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char filename[50];
    char filetype[10];
    int file_size;
    char* file_content;
} file;

int main() {
    FILE* fp;

    // open the disk image file
    fp = fopen("disk_image.bin", "rb");

    // get the disk size and number of files
    fseek(fp, 0, SEEK_END);
    int disk_size = ftell(fp);
    int num_files = (disk_size - sizeof(int)) / sizeof(file);
    rewind(fp);

    // read the number of files from the disk image
    int num_files_read;
    fread(&num_files_read, sizeof(int), 1, fp);

    // make sure the number of files matches
    if (num_files != num_files_read) {
        printf("Error: Number of files does not match.\n");
        exit(1);
    }

    // allocate space for the files
    file* files = malloc(num_files * sizeof(file));

    // read the files from the disk image
    fread(files, sizeof(file), num_files, fp);

    // ask the user which file they want to recover
    char filename[50];
    printf("Enter the name of the file you want to recover: ");
    scanf("%s", filename);

    // search for the file in the files array
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            // file found, print its contents and exit
            printf("File contents:\n%s\n", files[i].file_content);
            exit(0);
        }
    }

    // if we get here, the file was not found
    printf("Error: File not found.\n");
    exit(1);
}