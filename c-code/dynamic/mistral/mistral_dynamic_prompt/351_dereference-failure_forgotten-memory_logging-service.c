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

#define MAX_LOG_SIZE 1024

void write_log(const char *message) {
    int log_fd = open("logs.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
    if (log_fd == -1) {
        perror("Failed to open logs.txt");
        return;
    }

    char log_buffer[MAX_LOG_SIZE];
    strcpy(log_buffer, message);

    size_t written = write(log_fd, log_buffer, strlen(log_buffer));
    if (written == -1) {
        perror("Failed to write to logs.txt");
    }

    close(log_fd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_message>\n", argv[0]);
        return 1;
    }

    write_log(argv[1]);

    char *temp = (char *) malloc(MAX_LOG_SIZE * 2);
    if (temp == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

    strcpy(temp, "A very long log message");
    printf("Stored in memory: %s\n", temp);

    write_log(temp);
    free(temp); // Dereference failure - temp is not used after freeing

    return 0;
}
