#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

void log_message(char *message) {
    FILE *log_file = fopen("application.log", "a");
    if (log_file) {
        fprintf(log_file, "%s\n", message);
        fclose(log_file);
    } else {
        printf("Unable to open application.log for writing.\n");
    }
}

void process_log_entries(char *buffer) {
    int entries;
    sscanf(buffer, "%d ", &entries);
    for (int i = 0; i < entries; i++) {
        char level[10];
        char msg[BUFFER_SIZE];
        sscanf(buffer, "%s %s", level, msg);

        printf("Level: %s\nMessage: %s\n", level, msg);

        log_message(msg);
    }
}

int main(int argc, char *argv[]) {
    char input[BUFFER_SIZE];

    if (argc > 1) {
        strcpy(input, argv[1]);
        process_log_entries(input);
    } else {
        printf("Usage: %s <log_entries>\n", argv[0]);
    }

    return 0;
}
