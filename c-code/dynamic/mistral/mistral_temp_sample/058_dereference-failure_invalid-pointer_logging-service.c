#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void log_message(const char *message) {
    char *log_file = malloc(strlen("/var/log/app.log") + strlen(message) + 2);
    strcpy(log_file, "/var/log/app.log");
    strcat(log_file, message);
    FILE *log_fp = fopen(log_file, "a");
    if (log_fp == NULL) {
        perror("Failed to open log file");
        return;
    }

    fprintf(log_fp, "%s\n", message);
    fclose(log_fp);
    free(log_file);
}

int main() {
    char *args = getenv("LOG_MESSAGE");
    if (args == NULL) {
        printf("No log message provided.\n");
        return 1;
    }

    log_message(args);

    char *log_file = malloc(strlen("/var/log/app.log"));
    strcpy(log_file, "/var/log/app.log");
    FILE *log_fp = fopen(log_file, "r");

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, log_fp)) {
        printf("%s", buffer);
    }

    fclose(log_fp);
    free(log_file);
    return 0;
}
