//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define BUF_SIZE 1024
#define MAX_THREADS 10
#define THREAD_STACK_SIZE 1024

pthread_t threads[MAX_THREADS];
int thread_count = 0;

struct log_entry {
    time_t timestamp;
    char ip[16];
    char method[8];
    char uri[256];
    int status_code;
};

void log_write(struct log_entry *entry) {
    FILE *log_file = fopen("access.log", "a");
    if (log_file == NULL) {
        printf("Error opening log file\n");
        return;
    }

    fprintf(log_file, "%s - - [%s] \"%s %s HTTP/%d.%d\" %d -\n",
            ctime(&entry->timestamp), entry->ip, entry->method, entry->uri,
            entry->status_code / 100, entry->status_code % 100, entry->status_code);

    fclose(log_file);
}

void *process_request(void *arg) {
    char buf[BUF_SIZE];
    struct log_entry entry;

    while (fgets(buf, BUF_SIZE, stdin)!= NULL) {
        sscanf(buf, "%s %s %s %d", entry.ip, entry.method, entry.uri, &entry.status_code);
        entry.timestamp = time(NULL);
        log_write(&entry);
    }

    return NULL;
}

int main() {
    int fd = open("access.log", O_RDONLY);
    if (fd == -1) {
        printf("Error opening log file\n");
        return 1;
    }

    struct stat sb;
    fstat(fd, &sb);
    off_t file_size = sb.st_size;

    close(fd);

    printf("Log file size: %ld bytes\n", file_size);

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, process_request, NULL);
        thread_count++;
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}