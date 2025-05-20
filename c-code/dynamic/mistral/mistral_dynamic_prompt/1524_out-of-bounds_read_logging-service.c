#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100
#define LOG_FILE "log.txt"

void log_message(const char *message, int line_num) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, BUFFER_SIZE, "%d: %s\n", line_num, message);
    FILE *file = fopen(LOG_FILE, "a");
    if (file) {
        fputs(buffer, file);
        fclose(file);
    }
}

void main() {
    char input[10];
    printf("Enter a message (up to 9 characters): ");
    scanf("%s", input);
    log_message(input, __LINE__);

    int log_size = 0;
    FILE *file = fopen(LOG_FILE, "r");
    char log[BUFFER_SIZE];
    if (file) {
        while (fgets(log, BUFFER_SIZE, file)) {
            printf("%s", log);
            log_size++;
        }
        fclose(file);
        printf("Read %d lines.\n", log_size);
    }

    char *long_message = "This is a very long message, longer than 100 characters, intended to cause an out-of-bounds write when it gets logged.";
    log_message(long_message, __LINE__);
}
