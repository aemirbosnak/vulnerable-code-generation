//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define PAGE_SIZE 4096
#define MAX_FILE_SIZE (1024*1024)

int main() {
    char filename[100];
    printf("Enter the name of the file to monitor: ");
    scanf("%s", filename);

    int fd = open(filename, O_RDWR);
    if (fd == -1) {
        printf("Error opening file.\n");
        exit(1);
    }

    struct stat statbuf;
    if (fstat(fd, &statbuf) == -1) {
        printf("Error getting file status.\n");
        exit(1);
    }

    int file_size = statbuf.st_size;
    if (file_size > MAX_FILE_SIZE) {
        printf("File is too large to monitor.\n");
        exit(1);
    }

    char *file_data = malloc(file_size);
    if (file_data == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }

    int pages = (file_size + PAGE_SIZE - 1) / PAGE_SIZE;
    int *page_counts = malloc(pages * sizeof(int));
    if (page_counts == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }

    memset(page_counts, 0, pages * sizeof(int));

    if (mmap(file_data, file_size, PROT_READ, MAP_SHARED, fd, 0) == MAP_FAILED) {
        printf("Error mapping file.\n");
        exit(1);
    }

    int max_page_count = 0;
    int max_page = 0;

    while (1) {
        int page_count = 0;
        for (int i = 0; i < pages; i++) {
            if (page_counts[i] > page_count) {
                page_count = page_counts[i];
                max_page = i;
            }
        }
        if (page_count > max_page_count) {
            max_page_count = page_count;
        }

        printf("Current RAM usage: %d pages\n", max_page_count);
        printf("Current page count for page %d: %d\n", max_page, max_page_count);

        usleep(100000);
    }

    munmap(file_data, file_size);
    close(fd);
    free(page_counts);
    free(file_data);

    return 0;
}