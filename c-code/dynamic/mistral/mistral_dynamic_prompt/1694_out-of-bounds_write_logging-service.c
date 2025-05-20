#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define NUM_LOG_ENTRIES 100000

struct LogEntry {
    char message[MAX_SIZE];
    time_t timestamp;
};

struct LogEntry log[NUM_LOG_ENTRIES];
int current_entry = 0;

void write_log(const char* message) {
    if (current_entry >= NUM_LOG_ENTRIES) {
        printf("Error: Maximum log entries reached.\n");
        return;
    }
    strncpy(log[current_entry].message, message, MAX_SIZE);
    log[current_entry].timestamp = time(NULL);
    current_entry++;
}

int main() {
    char input[1000];
    while (1) {
        printf("Enter log message (or type 'exit' to quit): ");
        fgets(input, sizeof(input), stdin);

        if (strcasecmp(input, "exit\n") == 0) {
            break;
        }

        write_log(input);
    }

    return 0;
}
