#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_BUFFER_SIZE 1024
#define LOG_FILE_PATH "./log.txt"

void log_message(char *message) {
    int fd = open(LOG_FILE_PATH, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd < 0) {
        perror("Failed to open log file");
        return;
    }

    char buffer[MAX_BUFFER_SIZE];
    strcpy(buffer, message);
    strcat(buffer, "\n");

    ssize_t bytes_written = write(fd, buffer, strlen(buffer) + 1);
    if (bytes_written < 0) {
        perror("Failed to write to log file");
    }

    close(fd);
}

void main() {
    char log_messages[10][MAX_BUFFER_SIZE];

    int i;
    for (i = 0; i < 10; i++) {
        sprintf(log_messages[i], "Log message %d: %s", i, "This is a very important log entry");
    }

    for (i = 0; i < 11; i++) {
        log_message(log_messages[i]);
    }
}
