#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void log_message(char *message) {
    FILE *log_file = fopen("log.txt", "a");
    if (log_file == NULL) {
        fprintf(stderr, "Failed to open log file.\n");
        return;
    }

    fputs(message, log_file);
    fputs("\n", log_file);
    fclose(log_file);
}

int main(int argc, char *argv[]) {
    char *message;
    int len;

    if (argc < 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    len = strlen(argv[1]) + 1;
    message = malloc(BUFFER_SIZE * sizeof(char));

    if (!message) {
        fprintf(stderr, "Failed to allocate memory.\n");
        return 1;
    }

    memcpy(message, argv[1], len);

    for (int i = len; i < BUFFER_SIZE - 1; ++i) {
        message[i] = '\0';
        log_message(message);
        memset(message, '\0', BUFFER_SIZE * sizeof(char));
    }

    free(message);
    return 0;
}
