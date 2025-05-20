//LLAMA2-13B DATASET v1.0 Category: Data recovery tool ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#define BLOCK_SIZE 512

int main(void)
{
    // Get the device name and file name
    char device_name[] = "sda1";
    char file_name[] = "lostfile.txt";

    // Open the device file
    int fd = open(device_name, O_RDONLY);
    if (fd == -1) {
        perror("Error opening device file");
        return 1;
    }

    // Get the file's starting block and size
    off_t start_block = 0;
    off_t file_size = 0;
    struct stat stat_info;
    fstat(fd, &stat_info);
    start_block = stat_info.st_blocks * BLOCK_SIZE;
    file_size = stat_info.st_size;

    // Calculate the number of blocks needed to store the file
    off_t num_blocks = file_size / BLOCK_SIZE;

    // Calculate the number of blocks to read
    off_t blocks_to_read = num_blocks;

    // Allocate memory for the file's contents
    char *file_contents = malloc(num_blocks * BLOCK_SIZE);
    if (file_contents == NULL) {
        perror("Error allocating memory for file contents");
        close(fd);
        return 1;
    }

    // Read the file's contents from the device
    read(fd, file_contents, num_blocks * BLOCK_SIZE);

    // Find the location of the deleted file
    off_t deleted_block = start_block + file_size;
    off_t deleted_offset = 0;
    off_t last_block = start_block;
    off_t last_offset = 0;
    for (off_t i = start_block; i < deleted_block; i++) {
        if (file_contents[i] == 0x00) {
            last_block = i;
            last_offset = deleted_offset;
        }
        deleted_offset++;
    }

    // Recover the deleted file
    char recovered_file[BLOCK_SIZE];
    for (off_t i = last_block; i >= start_block; i--) {
        if (file_contents[i] == 0x00) {
            memcpy(recovered_file, &file_contents[last_offset], BLOCK_SIZE);
            last_offset += BLOCK_SIZE;
            break;
        }
    }

    // Write the recovered file to a new file
    char new_file_name[] = "recovered_file.txt";
    int new_fd = open(new_file_name, O_WRONLY | O_CREAT, 0644);
    if (new_fd == -1) {
        perror("Error creating new file");
        close(fd);
        free(file_contents);
        return 1;
    }
    write(new_fd, recovered_file, BLOCK_SIZE);
    close(new_fd);

    // Clean up
    free(file_contents);
    close(fd);

    printf("File recovered successfully\n");
    return 0;
}