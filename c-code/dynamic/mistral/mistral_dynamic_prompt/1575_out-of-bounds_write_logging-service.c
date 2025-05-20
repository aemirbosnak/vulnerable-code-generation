#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 100
#define LOG_FILE "/tmp/log.txt"

void log_message(char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) return;

    size_t len = strlen(message);
    char log_buffer[BUFFER_SIZE];

    strcpy(log_buffer, message);
    strcat(log_buffer, "\n");

    // Out of bounds write vulnerability here
    if (len + 1 > BUFFER_SIZE) {
        fprintf(file, "Error: Buffer overflow!\n");
    } else {
        fwrite(log_buffer, sizeof(char), len + 1, file);
        fclose(file);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <message to log>\n", argv[0]);
        return 1;
    }

    log_message(argv[1]);
    printf("Message logged: %s\n", argv[1]);
    return 0;
}
