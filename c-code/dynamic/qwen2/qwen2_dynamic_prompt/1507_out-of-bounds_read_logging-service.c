#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_FILE "app.log"

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
        fprintf(stderr, "Usage: %s <log_level>\n", argv[0]);
        return 1;
    }

    int log_level = atoi(argv[1]);

    // Simulate reading from an array with out-of-bounds access
    const char *messages[] = {"INFO: Application started",
                               "WARNING: Low disk space",
                               "ERROR: Database connection failed"};
    if (log_level >= 0 && log_level < 3) {
        printf("%s\n", messages[log_level]);
    } else {
        // Out-of-bounds read
        printf("%s\n", messages[log_level + 1]); // This will cause undefined behavior
    }

    return 0;
}
