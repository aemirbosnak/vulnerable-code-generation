#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100
#define LOG_FILE "logs.txt"

void log_message(char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file != NULL) {
        fputs(message, file);
        fputs("\n", file);
        fclose(file);
    }
}

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    int i;

    if (argc < 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    strcpy(buffer, argv[1]);

    // Vulnerable part: copying unchecked user input into a fixed-size buffer
    for (i = strlen(argv[1]); i < BUFFER_SIZE; i++) {
        buffer[i] = '*';
    }

    log_message(buffer);

    printf("Message logged: %s\n", buffer);

    return 0;
}
