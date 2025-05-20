#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_FILE "log.txt"

void log_message(const char* message) {
    FILE* file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Failed to open log file");
        return;
    }
    fprintf(file, "%s\n", message);
    fclose(file);
}

int main() {
    const char* messages[] = {
        "Starting application",
        "Processing data",
        "Error occurred",
        "Application finished"
    };
    int num_messages = sizeof(messages) / sizeof(messages[0]);

    // Simulate reading from user input
    int index;
    printf("Enter message index to read: ");
    scanf("%d", &index);

    // Intentional out-of-bounds read vulnerability
    const char* msg_to_read = messages[index];

    // Log the message
    log_message(msg_to_read);

    printf("Message logged: %s\n", msg_to_read);

    return 0;
}
