//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define KEY_LEN 16
#define BLOCK_LEN 16

void encrypt(unsigned char *data, int data_len, unsigned char *key) {
    int i, j;
    unsigned char block[BLOCK_LEN];

    for (i = 0; i < data_len; i += BLOCK_LEN) {
        memcpy(block, data + i, BLOCK_LEN);
        for (j = 0; j < BLOCK_LEN; j++) {
            block[j] ^= key[j];
        }
        memcpy(data + i, block, BLOCK_LEN);
    }
}

void decrypt(unsigned char *data, int data_len, unsigned char *key) {
    encrypt(data, data_len, key);
}

int main(int argc, char **argv) {
    int fd, fd2;
    unsigned char key[KEY_LEN];
    unsigned char buf[BLOCK_LEN];
    int n;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input file> <output file> <key>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd2 < 0) {
        perror("open");
        return 1;
    }

    memcpy(key, argv[3], KEY_LEN);

    while ((n = read(fd, buf, BLOCK_LEN)) > 0) {
        encrypt(buf, n, key);
        write(fd2, buf, n);
    }

    close(fd);
    close(fd2);

    return 0;
}