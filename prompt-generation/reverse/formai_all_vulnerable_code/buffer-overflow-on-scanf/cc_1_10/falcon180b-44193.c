//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <errno.h>

#define BUFFER_SIZE 4096

typedef struct {
    char *filename;
    int fd;
    void *buffer;
    size_t size;
} FileBackup;

void *backup_thread(void *arg) {
    FileBackup *file = arg;
    ssize_t nbytes;
    int ret;

    ret = read(file->fd, file->buffer, file->size);
    if (ret == -1) {
        fprintf(stderr, "Error reading file: %s\n", strerror(errno));
        exit(1);
    }

    nbytes = ret;
    while (nbytes > 0) {
        ssize_t written = write(file->fd, file->buffer, nbytes);
        if (written == -1) {
            fprintf(stderr, "Error writing file: %s\n", strerror(errno));
            exit(1);
        }
        nbytes -= written;
    }

    close(file->fd);
    free(file->buffer);
    free(file);
    return NULL;
}

int main() {
    int i, j, nfiles;
    char *filename;
    FileBackup *files;
    pthread_t threads[10];

    printf("Enter number of files to backup: ");
    scanf("%d", &nfiles);

    files = malloc(nfiles * sizeof(FileBackup));

    for (i = 0; i < nfiles; i++) {
        printf("Enter filename %d: ", i);
        scanf("%s", filename);

        files[i].filename = strdup(filename);
        files[i].fd = open(filename, O_RDWR);
        if (files[i].fd == -1) {
            fprintf(stderr, "Error opening file: %s\n", strerror(errno));
            exit(1);
        }

        files[i].size = lseek(files[i].fd, 0, SEEK_END);
        lseek(files[i].fd, 0, SEEK_SET);

        files[i].buffer = mmap(NULL, files[i].size, PROT_READ | PROT_WRITE, MAP_SHARED, files[i].fd, 0);
        if (files[i].buffer == MAP_FAILED) {
            fprintf(stderr, "Error mapping file: %s\n", strerror(errno));
            exit(1);
        }
    }

    for (i = 0; i < nfiles; i++) {
        pthread_create(&threads[i], NULL, backup_thread, &files[i]);
    }

    for (i = 0; i < nfiles; i++) {
        pthread_join(threads[i], NULL);
    }

    free(files);

    return 0;
}