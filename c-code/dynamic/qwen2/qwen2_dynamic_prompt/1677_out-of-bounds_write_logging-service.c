#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_FILE "app.log"

void log_message(const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) {
        fprintf(stderr, "Failed to open log file\n");
        return;
    }

    // Deliberate out-of-bounds write vulnerability
    char buffer[10];
    strcpy(buffer, message); // This will overwrite adjacent memory

    fclose(file);
}

int main() {
    const char *malicious_message = "This is a malicious log message";
    log_message(malicious_message);

    printf("Log written successfully.\n");

    return 0;
}
