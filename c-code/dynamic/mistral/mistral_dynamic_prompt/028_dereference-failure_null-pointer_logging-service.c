#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void log_message(char* log_file, const char* message) {
    FILE* log_fp = fopen(log_file, "a");
    if (log_fp == NULL) {
        fprintf(stderr, "Error: Unable to open log file.\n");
        return;
    }

    fprintf(log_fp, "[%s]: %s\n", __DATE__, message);
    fclose(log_fp);
}

void process_logs() {
    char* logs[5];
    logs[0] = malloc(256 * sizeof(char));
    strcpy(logs[0], "Server started successfully");

    logs[1] = malloc(256 * sizeof(char));
    sprintf(logs[1], "Received request from IP: %s", "192.168.1.1");

    logs[2] = malloc(256 * sizeof(char));
    strcpy(logs[2], "Error: Connection refused");

    logs[3] = NULL; // Let's assume this is a real log that's not initialized yet
    logs[4] = malloc(256 * sizeof(char));
    strcpy(logs[4], "Successfully processed request #123");

    for (int i = 0; logs[i] != NULL; i++) {
        log_message("logs.log", logs[i]);
        free(logs[i]);
    }
}

int main() {
    process_logs();
    return 0;
}
