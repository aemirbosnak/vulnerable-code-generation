//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>

#define MEGABYTE (1024*1024)

int main() {
    FILE *fp;
    char filename[20];
    struct statvfs buf;
    int i, j, max_line = 0;
    float total_mem = 0, used_mem = 0, free_mem = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Enter the name of the file to monitor RAM usage: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while ((read = getline(&line, &len, fp))!= -1) {
        if (read > max_line) {
            max_line = read;
        }
    }

    rewind(fp);

    printf("File: %s\n", filename);
    printf("Max line length: %d\n", max_line);
    printf("RAM usage:\n");

    while ((read = getline(&line, &len, fp))!= -1) {
        total_mem += MEGABYTE;
        used_mem += MEGABYTE;
        free_mem += MEGABYTE;
    }

    statvfs(filename, &buf);
    total_mem += buf.f_blocks * buf.f_bsize;
    free_mem += buf.f_bavail * buf.f_bsize;

    used_mem = total_mem - free_mem;

    printf("Total memory: %.2f MB\n", total_mem/MEGABYTE);
    printf("Used memory: %.2f MB\n", used_mem/MEGABYTE);
    printf("Free memory: %.2f MB\n", free_mem/MEGABYTE);

    free(line);
    fclose(fp);

    return 0;
}