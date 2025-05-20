//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

#define MEGABYTE (1024 * 1024)

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <process_id>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);

    char path[16];
    sprintf(path, "/proc/%d/statm", pid);

    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Failed to open %s\n", path);
        return 1;
    }

    int pagesize, resident_pages;
    if (fscanf(fp, "%d %d", &pagesize, &resident_pages)!= 2) {
        fprintf(stderr, "Error: Failed to read from %s\n", path);
        return 1;
    }

    fclose(fp);

    int rss = resident_pages * pagesize;

    char filename[64];
    sprintf(filename, "/proc/%d/maps", pid);

    FILE *maps_fp = fopen(filename, "r");
    if (maps_fp == NULL) {
        fprintf(stderr, "Error: Failed to open %s\n", filename);
        return 1;
    }

    off_t file_size = 0;
    char *start_addr = NULL;

    while (fgets(filename, sizeof(filename), maps_fp)!= NULL) {
        char *end_ptr;
        unsigned long long start = strtoull(filename, &end_ptr, 16);
        unsigned long long end = strtoull(end_ptr, NULL, 16);

        if (start_addr == NULL) {
            start_addr = (char *)start;
        }

        if (end > file_size) {
            file_size = end;
        }
    }

    fclose(maps_fp);

    if (start_addr == NULL) {
        fprintf(stderr, "Error: Failed to find start address\n");
        return 1;
    }

    unsigned long long total_pages = file_size / pagesize;
    unsigned long long total_rss = total_pages * pagesize;

    printf("PID: %d\n", pid);
    printf("RSS: %ld KB\n", rss / 1024);
    printf("Total RSS: %ld KB\n", total_rss / 1024);

    return 0;
}