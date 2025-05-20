#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 256
#define LOG_FILE "log.txt"

void log_message(char *message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Error opening log file");
        return;
    }

    size_t len = strlen(message) + 1; // Including null terminator
    char *log_buffer = malloc(BUFFER_SIZE);
    if (log_buffer == NULL) {
        perror("Error allocating memory");
        fclose(log_file);
        return;
    }

    // Vulnerable section
    strcpy(log_buffer, message);
    if (strlen(message) > BUFFER_SIZE - 1) {
        strcpy(log_buffer + BUFFER_SIZE - 1, "\n"); // Overwrite the null terminator
    }
    fprintf(log_file, "%s\n", log_buffer);
    free(log_buffer);
    fclose(log_file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: log_service <message>\n");
        return 1;
    }

    log_message(argv[1]);
    printf("Message logged: %s\n", argv[1]);
    return 0;
}
