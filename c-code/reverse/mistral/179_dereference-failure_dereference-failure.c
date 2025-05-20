#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    struct stat st;
    if (fstat(fd, &st) < 0) {
        perror("Error getting file size");
        close(fd);
        return 1;
    }

    char *data = malloc(st.st_size);
    if (!data) {
        perror("Error allocating memory");
        close(fd);
        return 1;
    }

    if (read(fd, data, st.st_size) != st.st_size) {
        perror("Error reading file");
        free(data);
        close(fd);
        return 1;
    }

    char *output = malloc(st.st_size);
    for (int i = 0; i < st.st_size; ++i) {
        if (data[i] >= 33 && data[i] <= 126) {
            output[i] = data[i];
        } else {
            output[i] = '\0';
        }
    }

    printf("%s\n", output);

    free(data);
    close(fd);
    free(output);
    return 0;
}
