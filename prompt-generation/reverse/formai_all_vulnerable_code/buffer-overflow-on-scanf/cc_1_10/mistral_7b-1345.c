//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define KEY_SIZE 25
#define BLOCK_SIZE 16
#define ALPHABET_SIZE 26
#define FILE_MODE 0644

char key[KEY_SIZE];
char iv[BLOCK_SIZE];

void xor_key(char* data, int length) {
    int i;
    for (i = 0; i < length; ++i) {
        data[i] ^= key[i % KEY_SIZE];
    }
}

void encrypt_file(const char* input_file, const char* output_file) {
    int input_fd, output_fd, read_bytes;
    char buffer[BLOCK_SIZE];

    if ((input_fd = open(input_file, O_RDONLY)) < 0) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    if ((output_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE)) < 0) {
        perror("Error creating output file");
        close(input_fd);
        exit(EXIT_FAILURE);
    }

    read_bytes = read(input_fd, iv, BLOCK_SIZE);
    if (read_bytes != BLOCK_SIZE) {
        perror("Error reading initialization vector");
        close(input_fd);
        close(output_fd);
        exit(EXIT_FAILURE);
    }

    printf("Input file: %s\n", input_file);
    printf("Output file: %s\n", output_file);
    printf("Key: ");
    scanf("%s", key);

    xor_key(iv, BLOCK_SIZE);

    while ((read_bytes = read(input_fd, buffer, BLOCK_SIZE)) > 0) {
        xor_key(buffer, read_bytes);
        write(output_fd, buffer, read_bytes);
    }

    close(input_fd);
    close(output_fd);

    printf("File encryption completed successfully.\n");
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    encrypt_file(argv[1], argv[2]);

    return EXIT_SUCCESS;
}