#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define LOG_FILE "security_log.log"
#define BUFFER_SIZE 1024

void log_message(char *message) {
    int fd;
    fd = open(LOG_FILE, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    write(fd, message, strlen(message));
    close(fd);
}

int main(int argc, char **argv) {
    char buffer[BUFFER_SIZE];
    gets(buffer);
    log_message(buffer);
    return 0;
}
