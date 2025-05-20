//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define LOG_FILE "c_log.txt"

typedef struct {
    char ip[16];
    char request[128];
    char status[8];
    char size[16];
    char time[20];
} log_entry;

void extract_log_entry(char *line, log_entry *entry) {
    sscanf(line, "%s %s %s %s %s",
           entry->time, entry->ip, entry->request, entry->status, entry->size);
}

int main() {
    int fd, lines = 0;
    log_entry entry;

    fd = open(LOG_FILE, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open log file");
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fd) != NULL) {
        lines++;
        extract_log_entry(buffer, &entry);

        printf("Line %d:\n", lines);
        printf("Time: %s\n", entry.time);
        printf("IP: %s\n", entry.ip);
        printf("Request: %s\n", entry.request);
        printf("Status: %s\n", entry.status);
        printf("Size: %s bytes\n", entry.size);

        if (strcmp(entry.status, "200 OK") == 0) {
            printf("Mad scientist: Hooray! Another successful request!\n");
            int request_size = atoi(entry.size);
            printf("Request size: %d bytes\n", request_size);

            // Perform some mad science magic with the request size
            int mad_science_result = 0;
            if (request_size > 1000) {
                mad_science_result = request_size / 2;
            } else {
                mad_science_result = request_size * 3;
            }
            printf("Mad science result: %d\n\n", mad_science_result);
        }
    }

    close(fd);
    return 0;
}