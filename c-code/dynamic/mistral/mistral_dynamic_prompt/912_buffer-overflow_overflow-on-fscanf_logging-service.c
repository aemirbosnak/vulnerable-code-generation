#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512

void log_message(const char *message) {
    FILE *log_file = fopen("logs.txt", "a");
    if (log_file == NULL) {
        fprintf(stderr, "Error opening logs.txt for writing.\n");
        return;
    }

    fprintf(log_file, "%s\n", message);
    fclose(log_file);
}

int main() {
    char buffer[BUFFER_SIZE];
    printf("Enter log message (up to 512 characters):\n");
    fgets(buffer, BUFFER_SIZE, stdin);
    log_message(buffer);

    int i;
    for (i = 0; i < BUFFER_SIZE - 1; ++i) {
        buffer[i] = 'A';
    }
    buffer[BUFFER_SIZE - 1] = '\0';
    log_message(buffer);

    printf("Now entering a really long log message.\n");
    fgets(buffer, BUFFER_SIZE, stdin);
    log_message(buffer);

    return 0;
}
