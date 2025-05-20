#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define LOG_FILE "logs.log"

void log_message(const char *message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        printf("Error: Could not open logs.log for appending.\n");
        return;
    }

    size_t len = strlen(message);
    char buffer[BUFFER_SIZE];
    strcpy(buffer, message);
    if (len > BUFFER_SIZE - 1) {
        printf("Warning: Message too long for buffer. Using truncated version.\n");
        buffer[BUFFER_SIZE - 1] = '\0'; // OOB read here, overwrites memory past the end of the buffer
    }

    fputs(buffer, log_file);
    fclose(log_file);
}

int main() {
    char user_input[256];
    printf("Enter a message to log (max 256 characters): ");
    fgets(user_input, sizeof(user_input), stdin);

    log_message(user_input);

    printf("Message logged.\n");
    return 0;
}
