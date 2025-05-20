//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MB (1024*1024)

int main() {
    int fd;
    char filename[20] = "/proc/self/statm";
    struct stat sb;
    char *ptr;
    long int total_mem;
    long int free_mem;
    long int used_mem;
    double ram_usage;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file\n");
        exit(1);
    }

    if (fstat(fd, &sb) == -1) {
        printf("Error getting file status\n");
        exit(1);
    }

    ptr = (char*)malloc(sb.st_size);
    if (ptr == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    if (read(fd, ptr, sb.st_size) == -1) {
        printf("Error reading file\n");
        exit(1);
    }

    close(fd);

    total_mem = strtol(ptr, &ptr, 10);
    free_mem = strtol(ptr, &ptr, 10);
    used_mem = total_mem - free_mem;

    ram_usage = (double)used_mem / total_mem * 100.0;

    printf("RAM usage: %.2f%%\n", ram_usage);

    free(ptr);
    return 0;
}