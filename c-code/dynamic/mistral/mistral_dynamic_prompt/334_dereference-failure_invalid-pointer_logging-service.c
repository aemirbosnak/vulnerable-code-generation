#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void log_message(const char *message) {
    char log_file[] = "/tmp/log.txt";
    FILE *file = fopen(log_file, "a+");
    if (file) {
        fprintf(file, "%s\n", message);
        fclose(file);
    } else {
        perror("Failed to open log file");
    }
}

void process_log_event(const char *event) {
    char *event_type = strtok(event, " ");
    char *event_data = strtok(NULL, " ");

    // Dereference invalid pointer
    int data_length = atoi(event_data);
    char data[data_length];
    strcpy(data, event_data);

    // Log the event
    log_message(event);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <event_string>\n", argv[0]);
        return 1;
    }

    process_log_event(argv[1]);
    return 0;
}
