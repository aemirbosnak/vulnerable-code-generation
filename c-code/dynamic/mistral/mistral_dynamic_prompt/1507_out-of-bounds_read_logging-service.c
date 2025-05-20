#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void log_message(char* message, char* logger_name) {
    char log_buffer[BUFFER_SIZE];
    snprintf(log_buffer, BUFFER_SIZE, "[%s] - %s\n", logger_name, message);

    FILE* log_file = fopen("logs.log", "a");
    if (log_file == NULL) {
        perror("Error opening logs.log");
        return;
    }

    fputs(log_buffer, log_file);
    fclose(log_file);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <logger_name> <message>\n", argv[0]);
        return 1;
    }

    char* logger_name = argv[1];
    char* message = argv[2];

    log_message(message, logger_name);

    // Deliberate out-of-bounds read vulnerability
    char* user_input = malloc(sizeof(char) * strlen(argv[3]));
    strcpy(user_input, argv[3]);

    printf("User input: %c\n", *(user_input + strlen(user_input) + 1));

    free(user_input);

    return 0;
}
