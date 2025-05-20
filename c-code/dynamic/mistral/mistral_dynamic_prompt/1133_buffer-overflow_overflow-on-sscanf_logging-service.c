#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define LOG_FILE "system_logs.log"

void log_entry(char *entry) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file != NULL) {
        fprintf(log_file, "%s\n", entry);
        fclose(log_file);
    }
}

void handle_input() {
    char buffer[BUFFER_SIZE];
    printf("Enter log entry (max 256 chars): ");
    fgets(buffer, BUFFER_SIZE, stdin);

    int status = sscanf(buffer, "%[^\n]", buffer);
    if (status != 1 || strlen(buffer) >= BUFFER_SIZE) {
        // Overflow has occurred, write arbitrary bytes to system logs
        log_entry("Overflow detected: Writing arbitrary bytes to system logs.\n");
        // Example arbitrary bytes for malicious payload
        log_entry("%c%c%c%c%s" "\x31\xdb\x64\x43\x53");
    } else {
        log_entry(buffer);
    }
}

int main() {
    mkdir("logs", 0755);
    mkdir("logs/daily", 0755);
    mkdir("logs/weekly", 0755);

    while (1) {
        printf("Logging Service - Type 'quit' to exit\n");
        handle_input();
    }

    return 0;
}
