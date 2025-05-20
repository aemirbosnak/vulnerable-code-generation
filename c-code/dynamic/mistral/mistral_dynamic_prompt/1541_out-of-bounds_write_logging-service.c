#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 100

void log_message(char *message) {
    char log_buffer[MAX_BUFFER_SIZE];
    sprintf(log_buffer, "%s\n", message);
    FILE *log_file = fopen("log.txt", "a");
    if (log_file != NULL) {
        fputs(log_buffer, log_file);
        fclose(log_file);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    char user_input[MAX_BUFFER_SIZE];
    strcpy(user_input, argv[1]);

    int i;
    for (i = strlen(user_input); i < MAX_BUFFER_SIZE; i++) {
        user_input[i] = 'X'; // Overflowing the input buffer
    }

    log_message(user_input);

    printf("Message logged successfully.\n");
    return 0;
}
