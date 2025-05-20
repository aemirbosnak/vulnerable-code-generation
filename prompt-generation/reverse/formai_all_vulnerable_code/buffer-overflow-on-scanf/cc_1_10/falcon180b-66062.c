//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10 MB max file size

typedef struct {
    char filename[256];
    char checksum[32];
} file_t;

void read_file(file_t *file) {
    FILE *fp = fopen(file->filename, "rb");
    if (fp == NULL) {
        strcpy(file->checksum, "Error reading file");
        return;
    }

    unsigned char buffer[4096];
    size_t bytes_read;
    unsigned int checksum = 0;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            checksum += buffer[i];
        }
    }

    sprintf(file->checksum, "%08X", checksum);

    fclose(fp);
}

int main() {
    file_t file;
    int num_files = 0;

    printf("Enter filename (or type 'done' to finish):\n");
    scanf("%s", file.filename);

    while (strcmp(file.filename, "done")!= 0) {
        if (num_files >= MAX_FILE_SIZE) {
            printf("Maximum number of files (%d) reached.\n", MAX_FILE_SIZE);
            break;
        }

        read_file(&file);
        printf("%s: %s\n", file.filename, file.checksum);

        num_files++;

        printf("Enter filename (or type 'done' to finish):\n");
        scanf("%s", file.filename);
    }

    return 0;
}