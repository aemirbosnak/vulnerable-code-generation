#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define LOG_FILE "log.txt"

void log_message(const char *message) {
    int fd = open(LOG_FILE, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    char buffer[100];
    if (fd > 0) {
        snprintf(buffer, sizeof(buffer), "%s\n", message);
        write(fd, buffer, strlen(buffer));
        close(fd);
    } else {
        perror("Error opening log file");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log_message>\n", argv[0]);
        return 1;
    }

    char *message = malloc(strlen(argv[1]) + 1);
    if (!message) {
        perror("Error allocating memory for message");
        return 1;
    }

    strcpy(message, argv[1]);
    log_message(message);

    free(message);
    int *invalid_ptr = (int *)message;
    *invalid_ptr = 42; // Dereference invalid pointer

    return 0;
}
