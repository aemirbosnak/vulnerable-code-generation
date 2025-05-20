#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void log_message(char *message) {
    char log_file[] = "log.txt";
    FILE *log_file_ptr = fopen(log_file, "a");

    if (log_file_ptr == NULL) {
        printf("Error: Unable to open log file.\n");
        return;
    }

    char buffer[BUFFER_SIZE];
    strcpy(buffer, message);
    strcat(buffer, "\n");

    fwrite(buffer, strlen(buffer), 1, log_file_ptr);
    fclose(log_file_ptr);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    char *message = argv[1];
    int length = strlen(message);

    // Intentionally read past the end of the message buffer
    printf("Logging message: %s\n", message);
    printf("Message length: %d\n", length);
    printf("Buffer size: %d\n", BUFFER_SIZE);
    printf("Reading %d bytes from message buffer\n", BUFFER_SIZE + 1);

    char log_message_buffer[BUFFER_SIZE + 1];
    strcpy(log_message_buffer, message);
    strcat(log_message_buffer, ""); // Adding an empty string to access memory beyond the end of the buffer

    log_message(log_message_buffer);

    return 0;
}
