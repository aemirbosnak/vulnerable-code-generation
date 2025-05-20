#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 256
#define LOG_FILE "logs.txt"

void log_message(const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file != NULL) {
        fprintf(file, "%s\n", message);
        fclose(file);
    }
}

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    printf("Log Service - Enter log message (max 256 characters):\n");

    // Intentionally use a large input to trigger the buffer overflow
    if (argc > 1) {
        strcpy(buffer, argv[1]);
    } else {
        scanf("%s", buffer);
    }

    log_message(buffer);

    // Simulate some logging service action, exploiting the buffer overflow
    // could potentially corrupt the program's stack and overwrite return address
    system(buffer);

    return 0;
}
