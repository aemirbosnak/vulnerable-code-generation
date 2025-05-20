//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BLOCK_SIZE 512

void recover_data(const char *filename, off_t offset, size_t size) {
    char buffer[BLOCK_SIZE];
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Failed to open file");
        return;
    }

    // Seek to the specified offset
    fseek(fp, offset, SEEK_SET);
    
    // Read data from the file
    size_t bytes_read = fread(buffer, 1, size, fp);
    if (bytes_read <= 0) {
        perror("Failed to read data");
        fclose(fp);
        return;
    }

    // Write recovered data to a new file
    FILE *recovery_fp = fopen("recovered_data.bin", "wb");
    if (!recovery_fp) {
        perror("Failed to create recovered_data.bin");
        fclose(fp);
        return;
    }

    fwrite(buffer, 1, bytes_read, recovery_fp);
    fclose(fp);
    fclose(recovery_fp);
    
    printf("Data recovered successfully! %lu bytes saved to 'recovered_data.bin'\n", bytes_read);
}

void display_file_info(const char *filename) {
    struct stat file_stat;
    
    if (stat(filename, &file_stat) == -1) {
        perror("Unable to get file stats");
        return;
    }

    printf("File: %s\n", filename);
    printf("Size: %ld bytes\n", file_stat.st_size);
    printf("Last modified: %ld\n", file_stat.st_mtime);
}

void get_user_input(off_t *offset, size_t *size) {
    printf("Enter the offset in bytes: ");
    scanf("%ld", offset);
    
    printf("Enter the number of bytes to recover: ");
    scanf("%ld", size);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    size_t recovery_size = 0;
    off_t recovery_offset = 0;

    display_file_info(filename);
    get_user_input(&recovery_offset, &recovery_size);
    
    if (recovery_offset < 0 || recovery_size <= 0) {
        fprintf(stderr, "Invalid offset or size.\n");
        return EXIT_FAILURE;
    }

    recover_data(filename, recovery_offset, recovery_size);
    
    printf("Recovery process has been initiated based on provided inputs.\n");

    return EXIT_SUCCESS;
}