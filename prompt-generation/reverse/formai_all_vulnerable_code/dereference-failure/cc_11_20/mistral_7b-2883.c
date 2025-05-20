//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 256
#define MIN_SHIFT 1
#define MAX_SHIFT 25

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <file_path> <shift_value>\n", argv[0]);
        return 1;
    }

    int shift = atoi(argv[2]);

    if (shift < MIN_SHIFT || shift > MAX_SHIFT) {
        printf("Shift value must be between %d and %d\n", MIN_SHIFT, MAX_SHIFT);
        return 1;
    }

    int file_fd = open(argv[1], O_RDWR);
    if (file_fd < 0) {
        perror("Error opening file");
        return 1;
    }

    struct stat file_stat;
    if (fstat(file_fd, &file_stat) < 0) {
        perror("Error getting file size");
        close(file_fd);
        return 1;
    }

    char *file_content = malloc(file_stat.st_size);
    if (!file_content) {
        perror("Error allocating memory for file content");
        close(file_fd);
        return 1;
    }

    ssize_t read_bytes = read(file_fd, file_content, file_stat.st_size);
    if (read_bytes < 0) {
        perror("Error reading file content");
        free(file_content);
        close(file_fd);
        return 1;
    }

    for (int i = 0; i < read_bytes; i++) {
        file_content[i] = (char)(((int)file_content[i] + shift) % 256);
    }

    int output_fd = open("encrypted_file.bin", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (output_fd < 0) {
        perror("Error creating output file");
        free(file_content);
        close(file_fd);
        return 1;
    }

    ssize_t write_bytes = write(output_fd, file_content, file_stat.st_size);
    if (write_bytes < 0) {
        perror("Error writing encrypted file content");
        close(output_fd);
        free(file_content);
        close(file_fd);
        return 1;
    }

    printf("File encrypted successfully\n");

    free(file_content);
    close(file_fd);
    close(output_fd);

    return 0;
}