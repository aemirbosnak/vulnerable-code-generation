//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define LOG_FILE "access.log"

typedef struct {
    char client_ip[20];
    char request[50];
    char status[10];
    char size[15];
    char date_time[30];
} log_entry;

void process_log(int line_number, char *line) {
    log_entry entry;
    sscanf(line, "%s %s %s %s %s", entry.client_ip, entry.request, entry.status, entry.size, entry.date_time);

    int http_status = atoi(entry.status);

    if (http_status >= 300 && http_status <= 399) {
        printf("Warning: Redirect detected at line %d: %s\n", line_number, line);
    } else if (http_status >= 400 && http_status <= 499) {
        printf("Error: Client error at line %d: %s\n", line_number, line);
    } else if (http_status >= 500 && http_status <= 599) {
        printf("Error: Server error at line %d: %s\n", line_number, line);
    } else {
        printf("Info: Request processed successfully at line %d: %s\n", line_number, line);
    }
}

int main() {
    int fd, line_number = 0;
    char line[MAX_LINE_LENGTH];

    fd = open(LOG_FILE, O_RDONLY);

    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fd) != NULL) {
        line_number++;
        process_log(line_number, line);
    }

    close(fd);
    return 0;
}