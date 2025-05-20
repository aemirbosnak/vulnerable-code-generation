//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BLOCK_SIZE 512
#define MAX_THREADS 4

typedef struct {
    int thread_id;
    char *disk_image;
    long start_sector;
    long end_sector;
} RecoveryThreadData;

void* recover_data(void* arg) {
    RecoveryThreadData *data = (RecoveryThreadData*) arg;

    printf("Thread %d started recovery from sector %ld to %ld.\n", 
           data->thread_id, data->start_sector, data->end_sector);

    int fd = open(data->disk_image, O_RDONLY);
    if (fd < 0) {
        perror("Error opening disk image");
        return NULL;
    }

    char buffer[BLOCK_SIZE];
    for (long sector = data->start_sector; sector < data->end_sector; ++sector) {
        lseek(fd, sector * BLOCK_SIZE, SEEK_SET);
        ssize_t bytes_read = read(fd, buffer, BLOCK_SIZE);
        if (bytes_read < 0) {
            perror("Error reading sector");
            close(fd);
            return NULL;
        }

        // Mocking a condition to simulate recovery
        if (bytes_read > 0) {
            printf("Thread %d recovered data from sector %ld: ", 
                   data->thread_id, sector);
            for (ssize_t i = 0; i < bytes_read; ++i) {
                printf("%02x ", (unsigned char)buffer[i]);
            }
            printf("\n");
        } else {
            printf("Thread %d found empty sector %ld.\n", 
                   data->thread_id, sector);
        }
    }

    close(fd);
    printf("Thread %d finished recovery.\n", data->thread_id);
    return NULL;
}

void print_usage(char *program_name) {
    printf("Usage: %s <disk_image> <total_sectors>\n", program_name);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    char *disk_image = argv[1];
    long total_sectors = strtol(argv[2], NULL, 10);
    long sectors_per_thread = total_sectors / MAX_THREADS;

    pthread_t threads[MAX_THREADS];
    RecoveryThreadData thread_data[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; ++i) {
        thread_data[i].thread_id = i;
        thread_data[i].disk_image = disk_image;
        thread_data[i].start_sector = i * sectors_per_thread;
        thread_data[i].end_sector = (i == MAX_THREADS - 1) ? total_sectors : 
                                    (i + 1) * sectors_per_thread;

        pthread_create(&threads[i], NULL, recover_data, (void*)&thread_data[i]);
    }

    for (int i = 0; i < MAX_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("Data recovery complete.\n");
    return EXIT_SUCCESS;
}