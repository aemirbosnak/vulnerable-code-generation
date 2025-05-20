//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILESYSTEM_BLOCK_SIZE 4096
#define SECTOR_SIZE 512

typedef struct {
    unsigned long long start;
    unsigned long long end;
} DiskRange;

typedef struct {
    char *name;
    unsigned long long size;
    DiskRange range;
} File;

int compare_files(const void *a, const void *b) {
    File *fa = (File *)a;
    File *fb = (File *)b;

    return strcmp(fa->name, fb->name);
}

int main() {
    // Get the disk size.
    unsigned long long disk_size = 0;
    FILE *fd = fopen("/sys/block/sda/size", "r");
    if (fd != NULL) {
        fscanf(fd, "%llu", &disk_size);
        fclose(fd);
    }

    // Create an array of files.
    File *files = NULL;
    unsigned long long num_files = 0;

    // Parse the df output.
    fd = popen("df -kP /", "r");
    if (fd != NULL) {
        char line[1024];
        while (fgets(line, sizeof(line), fd) != NULL) {
            if (strncmp(line, "Filesystem", 10) == 0) {
                continue;
            }

            char *fields[6];
            int num_fields = 0;
            char *field = strtok(line, " ");
            while (field != NULL) {
                fields[num_fields++] = field;
                field = strtok(NULL, " ");
            }

            if (num_fields != 6) {
                continue;
            }

            // Parse the file size.
            unsigned long long size = atoi(fields[2]);
            if (size == 0) {
                continue;
            }

            // Parse the file name.
            char *name = strdup(fields[5]);
            if (name == NULL) {
                fprintf(stderr, "Error: strdup() failed.\n");
                exit(1);
            }

            // Add the file to the array.
            files = realloc(files, (num_files + 1) * sizeof(File));
            if (files == NULL) {
                fprintf(stderr, "Error: realloc() failed.\n");
                exit(1);
            }

            files[num_files++] = (File){
                .name = name,
                .size = size,
                .range = {
                    .start = 0,
                    .end = 0,
                },
            };
        }

        pclose(fd);
    }

    // Sort the files by name.
    qsort(files, num_files, sizeof(File), compare_files);

    // Calculate the range of each file.
    for (unsigned long long i = 0; i < num_files; i++) {
        files[i].range.start = (files[i].size + FILESYSTEM_BLOCK_SIZE - 1) / FILESYSTEM_BLOCK_SIZE;
        files[i].range.end = files[i].range.start + files[i].size / SECTOR_SIZE;
    }

    // Print the disk space usage.
    printf("Disk usage:\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("| %-4s | %-20s | %-10s | %-10s | %-10s |\n", "ID", "Name", "Size (KiB)", "Start (sectors)", "End (sectors)");
    printf("-------------------------------------------------------------------------------------------------\n");
    for (unsigned long long i = 0; i < num_files; i++) {
        printf("| %-4llu | %-20s | %-10llu | %-10llu | %-10llu |\n", i, files[i].name, files[i].size / 1024, files[i].range.start, files[i].range.end);
    }
    printf("-------------------------------------------------------------------------------------------------\n");

    // Free the memory.
    for (unsigned long long i = 0; i < num_files; i++) {
        free(files[i].name);
    }

    free(files);

    return 0;
}