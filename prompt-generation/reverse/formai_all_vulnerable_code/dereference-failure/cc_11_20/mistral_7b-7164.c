//MISTRAL-7B DATASET v1.0 Category: Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <time.h>

#define MAX_INPUT_SIZE 1024
#define MAX_SECRET_SIZE 64

volatile int g_paranoia_level = 0;

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        exit(1);
    }

    char *input = mmap(NULL, MAX_INPUT_SIZE, PROT_READ, MAP_PRIVATE, 0, 0);
    if (input == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("open failed");
        munmap(input, MAX_INPUT_SIZE);
        exit(1);
    }

    ssize_t nread = read(fd, input, MAX_INPUT_SIZE - 1);
    if (nread < 0) {
        perror("read failed");
        close(fd);
        munmap(input, MAX_INPUT_SIZE);
        exit(1);
    }
    input[nread] = '\0';

    close(fd);

    char secret[MAX_SECRET_SIZE];
    int secret_length = 0;

    while (1) {
        if (g_paranoia_level >= 5) {
            fprintf(stderr, "Paranoia level too high, exiting...\n");
            munmap(input, MAX_INPUT_SIZE);
            exit(1);
        }

        if (strlen(input) > MAX_INPUT_SIZE - 10) {
            fprintf(stderr, "Input too long, exiting...\n");
            munmap(input, MAX_INPUT_SIZE);
            exit(1);
        }

        if (strstr(input, "secret") != NULL) {
            if (secret_length > 0) {
                fprintf(stderr, "Multiple secrets detected, exiting...\n");
                munmap(input, MAX_INPUT_SIZE);
                exit(1);
            }

            ssize_t secret_pos = strlen(input) - 6;
            if (input[secret_pos] != 's' || input[secret_pos - 1] != 'e' || input[secret_pos - 2] != 'c' || input[secret_pos - 3] != 'r' || input[secret_pos - 4] != 'e' || input[secret_pos - 5] != 't') {
                fprintf(stderr, "Invalid secret detected, paranoia level increasing...\n");
                g_paranoia_level++;
                continue;
            }

            int i;
            for (i = secret_pos - 9; i <= secret_pos; i++) {
                secret[secret_length++] = input[i];
            }

            fprintf(stderr, "Secret detected: %s\n", secret);
            break;
        }

        sleep(1);
    }

    munmap(input, MAX_INPUT_SIZE);

    return 0;
}