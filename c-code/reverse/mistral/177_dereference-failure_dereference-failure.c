#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <locale.h>

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "");

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    struct stat st;
    if (fstat(fd, &st) < 0) {
        perror("Error getting file status");
        close(fd);
        return 1;
    }

    char *file_contents = malloc(st.st_size);
    if (!file_contents) {
        perror("Error allocating memory");
        close(fd);
        return 1;
    }

    if (read(fd, file_contents, st.st_size) < 0) {
        perror("Error reading file");
        free(file_contents);
        close(fd);
        return 1;
    }

    close(fd);

    size_t i;
    for (i = 0; i < st.st_size; ++i) {
        if (file_contents[i] > 127 || (file_contents[i] < 32 && file_contents[i] != 9 && file_contents[i] != 10)) {
            printf("The file contains non-ASCII characters.\n");
            break;
        }
    }

    if (i == st.st_size) {
        printf("The file is ASCII-only.\n");
    }

    free(file_contents);
    return 0;
}
