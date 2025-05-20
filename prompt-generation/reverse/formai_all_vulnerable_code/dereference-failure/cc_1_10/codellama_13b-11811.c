//Code Llama-13B DATASET v1.0 Category: File Synchronizer ; Style: active
// File Synchronizer Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>

// Structures
struct file_sync {
    int fd;
    char *buffer;
    size_t size;
};

// Functions
void file_sync_init(struct file_sync *sync) {
    sync->fd = -1;
    sync->buffer = NULL;
    sync->size = 0;
}

void file_sync_open(struct file_sync *sync, const char *filename) {
    sync->fd = open(filename, O_RDONLY);
    if (sync->fd == -1) {
        perror("Error opening file");
        return;
    }
    sync->size = lseek(sync->fd, 0, SEEK_END);
    lseek(sync->fd, 0, SEEK_SET);
    sync->buffer = mmap(NULL, sync->size, PROT_READ, MAP_SHARED, sync->fd, 0);
    if (sync->buffer == MAP_FAILED) {
        perror("Error mmapping file");
        close(sync->fd);
        sync->fd = -1;
        sync->buffer = NULL;
        sync->size = 0;
        return;
    }
}

void file_sync_close(struct file_sync *sync) {
    if (sync->fd != -1) {
        munmap(sync->buffer, sync->size);
        close(sync->fd);
        sync->fd = -1;
        sync->buffer = NULL;
        sync->size = 0;
    }
}

void file_sync_print(struct file_sync *sync) {
    if (sync->fd == -1) {
        printf("File not open\n");
        return;
    }
    printf("File contents:\n");
    for (size_t i = 0; i < sync->size; i++) {
        printf("%c", sync->buffer[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    struct file_sync sync;
    file_sync_init(&sync);
    file_sync_open(&sync, argv[1]);
    file_sync_print(&sync);
    file_sync_close(&sync);
    return 0;
}