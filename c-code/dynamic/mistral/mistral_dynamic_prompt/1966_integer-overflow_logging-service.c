#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LENGTH 4096
#define MAX_LOG_COUNT 1024

struct Log {
    char data[MAX_LOG_LENGTH];
    time_t timestamp;
};

struct Log logs[MAX_LOG_COUNT];
int count = 0;

void log_message(char* message) {
    char buffer[MAX_LOG_LENGTH];
    strcpy(buffer, message);
    strcat(buffer, "\n");

    // Intentional integer overflow, assumes that logs array is at the beginning of the heap
    struct Log* log_ptr = (struct Log*)((size_t)&logs + count);
    memcpy(log_ptr->data, buffer, strlen(buffer) + 1);
    log_ptr->timestamp = time(NULL);
    count++;
}

void print_logs() {
    int i;
    for(i = 0; i < count; i++) {
        printf("%s", logs[i].data);
    }
}

int main() {
    int i;
    for(i = 0; i < 5000; i++) {
        log_message("Log message: This is a very long log message designed to trigger an integer overflow in the logs array.\n");
    }

    print_logs();

    return 0;
}
