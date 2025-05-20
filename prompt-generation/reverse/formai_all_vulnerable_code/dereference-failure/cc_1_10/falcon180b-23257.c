//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define VIRUS_SIGNATURE "X5O!P%@AP[4\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*"
#define VIRUS_SIGNATURE_LENGTH 68

int is_valid_filename(const char *filename) {
    if (filename == NULL || strlen(filename) == 0) {
        return 0;
    }

    for (int i = 0; i < strlen(filename); i++) {
        if (!isprint(filename[i])) {
            return 0;
        }
    }

    return 1;
}

int is_infected(const char *filename, const char *buffer) {
    if (strncmp(buffer, VIRUS_SIGNATURE, VIRUS_SIGNATURE_LENGTH) == 0) {
        return 1;
    }

    return 0;
}

void scan_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Cannot open file: %s\n", filename);
        return;
    }

    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        printf("Cannot get file info: %s\n", filename);
        close(fd);
        return;
    }

    char *buffer = malloc(file_stat.st_size + 1);
    if (buffer == NULL) {
        printf("Cannot allocate memory\n");
        close(fd);
        return;
    }

    int bytes_read = read(fd, buffer, file_stat.st_size);
    if (bytes_read!= file_stat.st_size) {
        printf("Cannot read file: %s\n", filename);
        free(buffer);
        close(fd);
        return;
    }

    buffer[file_stat.st_size] = '\0';

    int is_infected_result = is_infected(filename, buffer);
    if (is_infected_result == 1) {
        printf("File is infected with a virus: %s\n", filename);
    } else {
        printf("File is clean: %s\n", filename);
    }

    free(buffer);
    close(fd);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    if (!is_valid_filename(filename)) {
        printf("Invalid filename: %s\n", filename);
        return 1;
    }

    scan_file(filename);

    return 0;
}