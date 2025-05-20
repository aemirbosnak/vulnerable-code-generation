#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LOG_SIZE 1024

void log_message(const char *message) {
    FILE *log_file = fopen("log.txt", "a");
    if (log_file == NULL) {
        printf("Failed to open log file.\n");
        return;
    }

    // Vulnerability: No bounds checking on fscanf
    char buffer[MAX_LOG_SIZE];
    fprintf(log_file, "New Log Entry:\n");
    fscanf(stdin, "%s", buffer); // Potential buffer overflow here
    fprintf(log_file, "Logged Message: %s\n", buffer);
    fclose(log_file);
}

int main() {
    printf("Welcome to the Logging Service!\n");
    while (1) {
        printf("Enter a message to log (or 'exit' to quit): ");
        char input[64];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            break;
        }

        log_message(input);
    }
    return 0;
}
