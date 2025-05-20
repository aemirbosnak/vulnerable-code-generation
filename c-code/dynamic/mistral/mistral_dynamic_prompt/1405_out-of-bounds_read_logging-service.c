#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void log_message(char *message) {
    FILE *log_file = fopen("log.txt", "a");
    if (log_file == NULL) {
        perror("Error opening log file");
        return;
    }

    char log_buffer[BUFFER_SIZE];
    strcpy(log_buffer, message);

    // Deliberate OOB read vulnerability
    printf("Message: %s\n", log_buffer + BUFFER_SIZE);

    fprintf(log_file, "%s\n", log_buffer);
    fclose(log_file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    log_message(argv[1]);
    return 0;
}
