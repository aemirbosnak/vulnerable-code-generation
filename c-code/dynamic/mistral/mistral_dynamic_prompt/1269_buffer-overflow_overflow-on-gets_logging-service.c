#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_BUFFER 256
#define LOG_FILE "security_log.txt"

void log_message(char *message) {
    int fd;
    fd = open(LOG_FILE, O_RDWR | O_CREAT | O_APPEND, 0644);
    write(fd, message, strlen(message));
    close(fd);
}

int main(int argc, char *argv[]) {
    char buffer[MAX_BUFFER];

    printf("Log Service v1.0\n");
    printf("Enter a message to log: ");
    fgets(buffer, sizeof(buffer), stdin);

    log_message(buffer);
    log_message("Buffer overflow intentionally created to demonstrate vulnerability");

    return 0;
}
