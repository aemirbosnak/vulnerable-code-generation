//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 512  // Size of the buffer to read from the disk
#define RECOVERY_FILE "recovered_data.bin"  // File where recovered data will be stored

void recover_data(const char *disk_path) {
    int disk_fd = open(disk_path, O_RDONLY); // Open the disk for reading
    if (disk_fd < 0) {
        perror("Failed to open disk for reading");
        exit(EXIT_FAILURE);
    }

    FILE *recovery_file = fopen(RECOVERY_FILE, "wb"); // Open the recovery file for writing
    if (!recovery_file) {
        perror("Failed to open recovery file");
        close(disk_fd);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    off_t offset = 0; // Offset on the disk

    while ((bytes_read = pread(disk_fd, buffer, BUFFER_SIZE, offset)) > 0) {
        fwrite(buffer, 1, bytes_read, recovery_file); // Write the data to the recovery file
        offset += bytes_read; // Move to the next block
    }

    if (bytes_read < 0) {
        perror("Failed to read from disk");
        fclose(recovery_file);
        close(disk_fd);
        exit(EXIT_FAILURE);
    }

    printf("Data recovery completed successfully. Recovered data saved to '%s'.\n", RECOVERY_FILE);
    
    fclose(recovery_file);
    close(disk_fd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <disk_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *disk_path = argv[1];
    recover_data(disk_path);

    return EXIT_SUCCESS;
}