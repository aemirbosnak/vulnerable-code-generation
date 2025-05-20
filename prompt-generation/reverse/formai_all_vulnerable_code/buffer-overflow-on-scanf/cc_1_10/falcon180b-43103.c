//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 100000

typedef struct {
    char filename[100];
    int filesize;
    char *data;
} file_t;

int read_file(file_t *file) {
    FILE *fp = fopen(file->filename, "rb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", file->filename);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    file->filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    file->data = (char *) malloc(file->filesize);
    if (file->data == NULL) {
        printf("Error allocating memory for file data\n");
        return 1;
    }

    fread(file->data, 1, file->filesize, fp);
    fclose(fp);

    return 0;
}

int write_file(file_t *file) {
    FILE *fp = fopen(file->filename, "wb");
    if (fp == NULL) {
        printf("Error creating file: %s\n", file->filename);
        return 1;
    }

    fwrite(file->data, 1, file->filesize, fp);
    fclose(fp);

    return 0;
}

int main() {
    int num_files = 0;
    file_t files[100];

    printf("Enter the number of files to recover (1-100): ");
    scanf("%d", &num_files);

    for (int i = 0; i < num_files; i++) {
        printf("Enter the filename for file %d: ", i+1);
        scanf("%s", files[i].filename);

        if (read_file(&files[i])!= 0) {
            printf("Error reading file %s\n", files[i].filename);
            return 1;
        }
    }

    printf("Enter the output directory: ");
    scanf("%s", files[0].filename);
    strcat(files[0].filename, "/recovered_files");

    if (mkdir(files[0].filename)!= 0) {
        printf("Error creating output directory\n");
        return 1;
    }

    for (int i = 0; i < num_files; i++) {
        char output_filename[200];
        sprintf(output_filename, "%s/%s", files[0].filename, files[i].filename);

        if (write_file(&files[i])!= 0) {
            printf("Error writing file %s\n", output_filename);
            return 1;
        }
    }

    printf("File recovery complete!\n");

    return 0;
}