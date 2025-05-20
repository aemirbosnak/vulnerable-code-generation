#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "logs.txt"

void log_message(const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) return;

    char timestamp[20];
    time_t now = time(NULL);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));

    fprintf(file, "[%s] %s\n", timestamp, message);
    fclose(file);
}

void log_error(const char *error_message, void *ptr) {
    if (ptr == NULL) {
        log_message("Null pointer passed to function");
        return;
    }

    log_message(error_message);
    printf("%s: %p\n", error_message, ptr);
}

int main() {
    char *log_buffer = (char *) malloc(1);
    log_error("Allocated buffer is null", log_buffer);

    int array[3] = {1, 2, 3};
    int *null_ptr = NULL;
    log_error("Null pointer dereferenced", null_ptr++);

    log_message("Logging service started...");

    free(log_buffer);

    return 0;
}
