//Falcon2-11B DATASET v1.0 Category: RAM usage monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];
    char *file_content = NULL;
    int file_size = 0;

    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    file_content = malloc(file_size + 1);
    if (file_content == NULL) {
        perror("Error allocating memory");
        return 1;
    }

    fread(file_content, 1, file_size, file);
    file_content[file_size] = '\0';
    fclose(file);

    int fd = open(file_name, O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    void *mmap_addr = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mmap_addr == MAP_FAILED) {
        perror("Error mapping file");
        return 1;
    }

    memcpy(mmap_addr, file_content, file_size);
    close(fd);

    char *output = NULL;
    int num_bytes = 0;

    int pid = fork();
    if (pid == -1) {
        perror("Error forking process");
        return 1;
    }

    if (pid == 0) {
        execlp("cat", "cat", "-s", "-n", file_name, (char *)NULL);
    } else {
        wait(NULL);

        num_bytes = read(STDIN_FILENO, &output, sizeof(output));
        if (num_bytes <= 0) {
            perror("Error reading from standard input");
            return 1;
        }

        printf("RAM usage: %ld bytes\n", (long)num_bytes);
    }

    free(file_content);
    return 0;
}