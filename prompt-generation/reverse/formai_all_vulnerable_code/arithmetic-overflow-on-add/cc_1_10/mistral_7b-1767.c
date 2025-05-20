//MISTRAL-7B DATASET v1.0 Category: Antivirus scanner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <ctype.h>
#include <errno.h>

#define MAX_FILE_SIZE 1024 * 1024
#define MAX_FILE_NAME 256
#define SIGNATURE_SIZE 16
#define BLOCK_SIZE 4096

typedef unsigned char byte;

byte signature[] = {0x4D, 0x5A, 0x90, 0x00, 0x50, 0x45, 0x00, 0x3C,
                    0x69, 0x6E, 0x64, 0x65, 0x78, 0x41, 0x52, 0x53,
                    0x53, 0x45, 0x54};

int is_safe(const byte* file_buffer, int file_size) {
    for (int i = 0; i < file_size - SIGNATURE_SIZE + 1; i++) {
        int j;
        for (j = 0; j < SIGNATURE_SIZE; j++) {
            if (file_buffer[i + j] != signature[j])
                break;
        }
        if (j == SIGNATURE_SIZE)
            return 1;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char file_name[MAX_FILE_NAME];
    strcpy(file_name, argv[1]);

    int file_fd = open(file_name, O_RDONLY);
    if (file_fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    struct stat file_stat;
    if (fstat(file_fd, &file_stat) < 0) {
        perror("fstat");
        close(file_fd);
        exit(EXIT_FAILURE);
    }

    if (file_stat.st_size > MAX_FILE_SIZE) {
        printf("File size too large\n");
        close(file_fd);
        exit(EXIT_FAILURE);
    }

    byte* file_buffer = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, file_fd, 0);
    if (file_buffer == MAP_FAILED) {
        perror("mmap");
        close(file_fd);
        exit(EXIT_FAILURE);
    }

    int file_size = file_stat.st_size;

    close(file_fd);

    if (!is_safe(file_buffer, file_size)) {
        printf("File contains virus!\n");
        munmap(file_buffer, file_size);
        exit(EXIT_FAILURE);
    }

    printf("File is safe\n");
    munmap(file_buffer, file_size);

    return EXIT_SUCCESS;
}