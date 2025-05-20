#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LOG_SIZE 1024

typedef struct {
    char filename[256];
    FILE *file;
} LogFile;

void *write_log(void *arg) {
    LogFile *log = (LogFile *) arg;
    char log_data[] = "This is a deliberately vulnerable logging service";

    while (1) {
        if (log->file) {
            fputs(log_data, log->file);
            fflush(log->file);
        }
        sleep(1);
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    LogFile log;
    strcpy(log.filename, argv[1]);
    log.file = fopen(log.filename, "w+");

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, &write_log, &log);

    // Intentional dereference of uninitialized pointer
    char *log_content = (char *) malloc(MAX_LOG_SIZE);
    fseek(log.file, 0, SEEK_SET);
    fread(log_content, 1, MAX_LOG_SIZE, log.file);
    printf("Log content: %s\n", log_content);

    pthread_join(thread_id, NULL);
    fclose(log.file);

    return 0;
}
