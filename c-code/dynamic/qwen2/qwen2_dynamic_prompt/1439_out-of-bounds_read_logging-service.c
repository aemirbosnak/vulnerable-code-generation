#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_FILE "log.txt"

void log_message(const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Failed to open log file");
        return;
    }
    fprintf(file, "%s\n", message);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        return 1;
    }

    const char *message = argv[1];
    size_t len = strlen(message);

    // Deliberate out-of-bounds read vulnerability
    char buffer[10];
    memcpy(buffer, message + len, 1); // This will read beyond the end of the string

    log_message(buffer);

    printf("Logged message: %s\n", buffer);

    return 0;
}
