//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: scalable
// FileEncryptor.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// Define the encryption key
#define KEY 0x55AA55AA

// Define the block size
#define BLOCK_SIZE 1024

// Function to encrypt a block of data
void encrypt_block(uint8_t* data, size_t size) {
    for (int i = 0; i < size; i++) {
        data[i] = (data[i] ^ KEY) + 1;
    }
}

// Function to decrypt a block of data
void decrypt_block(uint8_t* data, size_t size) {
    for (int i = 0; i < size; i++) {
        data[i] = (data[i] - 1) ^ KEY;
    }
}

// Function to encrypt a file
void encrypt_file(char* file_name) {
    // Open the file for reading and writing
    int fd = open(file_name, O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Get the file size
    struct stat st;
    fstat(fd, &st);
    size_t file_size = st.st_size;

    // Allocate a buffer for the file contents
    uint8_t* buffer = malloc(file_size);
    if (buffer == NULL) {
        perror("malloc");
        exit(1);
    }

    // Read the file contents into the buffer
    ssize_t bytes_read = read(fd, buffer, file_size);
    if (bytes_read != file_size) {
        perror("read");
        exit(1);
    }

    // Encrypt the file contents
    encrypt_block(buffer, file_size);

    // Write the encrypted contents back to the file
    ssize_t bytes_written = write(fd, buffer, file_size);
    if (bytes_written != file_size) {
        perror("write");
        exit(1);
    }

    // Free the buffer
    free(buffer);

    // Close the file
    close(fd);
}

// Function to decrypt a file
void decrypt_file(char* file_name) {
    // Open the file for reading and writing
    int fd = open(file_name, O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Get the file size
    struct stat st;
    fstat(fd, &st);
    size_t file_size = st.st_size;

    // Allocate a buffer for the file contents
    uint8_t* buffer = malloc(file_size);
    if (buffer == NULL) {
        perror("malloc");
        exit(1);
    }

    // Read the file contents into the buffer
    ssize_t bytes_read = read(fd, buffer, file_size);
    if (bytes_read != file_size) {
        perror("read");
        exit(1);
    }

    // Decrypt the file contents
    decrypt_block(buffer, file_size);

    // Write the decrypted contents back to the file
    ssize_t bytes_written = write(fd, buffer, file_size);
    if (bytes_written != file_size) {
        perror("write");
        exit(1);
    }

    // Free the buffer
    free(buffer);

    // Close the file
    close(fd);
}

int main(int argc, char* argv[]) {
    // Check the number of arguments
    if (argc != 3) {
        printf("Usage: %s <operation> <file_name>\n", argv[0]);
        exit(1);
    }

    // Check the operation
    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt_file(argv[2]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt_file(argv[2]);
    } else {
        printf("Invalid operation: %s\n", argv[1]);
        exit(1);
    }

    return 0;
}