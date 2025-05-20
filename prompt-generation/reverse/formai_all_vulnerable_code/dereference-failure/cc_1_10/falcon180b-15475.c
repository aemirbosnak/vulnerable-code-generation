//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

void log_event(const char* message) {
    FILE* log_file = fopen("intrusion_detection.log", "a");
    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file: %s\n", strerror(errno));
        return;
    }

    fprintf(log_file, "%s\n", message);
    fclose(log_file);
}

int main() {
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    fd = open("/dev/tty", O_RDONLY);
    if (fd == -1) {
        log_event("Failed to open tty device");
        return 1;
    }

    while (1) {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1) {
            if (errno == EINTR) {
                continue;
            }

            log_event("Error reading from tty device");
            break;
        }

        if (bytes_read == 0) {
            continue;
        }

        char* newline = strchr(buffer, '\n');
        if (newline == NULL) {
            continue;
        }

        *newline = '\0';
        log_event(buffer);
    }

    close(fd);
    return 0;
}