//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 1024) // 1GB

typedef struct {
    char *name;
    size_t size;
} FileEntry;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <device>\n", argv[0]);
        return 1;
    }

    char device[64] = {0};
    strncpy(device, argv[1], sizeof(device));

    FILE *fp = fopen("/dev/sd", "r");
    if (fp == NULL) {
        printf("Error opening device.\n");
        return 2;
    }

    fseek(fp, 0, SEEK_SET);
    fread(&device[strlen(device)], 1, 1, fp);
    fclose(fp);

    printf("Scanning device %s...\n", device);

    int num_files = 0;
    FileEntry *files = malloc(MAX_FILE_SIZE * sizeof(FileEntry));
    if (files == NULL) {
        printf("Error allocating memory.\n");
        return 3;
    }

    FILE *file_fp = fopen(device, "r");
    if (file_fp == NULL) {
        printf("Error opening device.\n");
        free(files);
        return 4;
    }

    char buffer[1024] = {0};
    while (fread(buffer, 1, sizeof(buffer), file_fp) > 0) {
        char *filename = strtok(buffer, "\n");
        if (filename == NULL) {
            continue;
        }

        size_t filesize = 0;
        fseek(file_fp, -strlen(filename) - 1, SEEK_CUR);
        while (fread(buffer, 1, sizeof(buffer), file_fp) > 0) {
            if (buffer[0] == '\n') {
                break;
            }
            filesize += strlen(buffer);
        }

        if (num_files >= MAX_FILE_SIZE) {
            printf("Maximum number of files reached.\n");
            break;
        }

        files[num_files].name = strdup(filename);
        files[num_files].size = filesize;
        num_files++;
    }

    fclose(file_fp);

    printf("Found %d files:\n", num_files);
    for (int i = 0; i < num_files; i++) {
        printf("File %d: %s (%zu bytes)\n", i + 1, files[i].name, files[i].size);
    }

    free(files);
    return 0;
}