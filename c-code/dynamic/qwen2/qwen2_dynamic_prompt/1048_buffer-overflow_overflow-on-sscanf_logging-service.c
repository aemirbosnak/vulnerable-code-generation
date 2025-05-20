#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LOG_SIZE 1024

void log_message(const char *message) {
    char log_buffer[MAX_LOG_SIZE];
    snprintf(log_buffer, sizeof(log_buffer), "LOG: %s", message);
    printf("%s\n", log_buffer);
}

int main() {
    char input[256];
    printf("Enter a log message: ");
    fgets(input, sizeof(input), stdin);

    // Vulnerability: No bounds checking on sscanf
    int id;
    float value;
    if (sscanf(input, "%d %f", &id, &value) == 2) {
        log_message("Received data");
    } else {
        log_message("Invalid input");
    }

    return 0;
}
