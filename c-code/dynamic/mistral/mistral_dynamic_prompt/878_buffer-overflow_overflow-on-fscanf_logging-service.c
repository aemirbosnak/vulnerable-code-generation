#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void log_message(char *message) {
    FILE *log_file = fopen("log.txt", "a");
    if (log_file != NULL) {
        fputs(message, log_file);
        fclose(log_file);
    }
}

int main() {
    char buffer[BUFFER_SIZE];
    printf("Enter the log message: ");
    fgets(buffer, BUFFER_SIZE, stdin);

    log_message(buffer);

    return 0;
}
