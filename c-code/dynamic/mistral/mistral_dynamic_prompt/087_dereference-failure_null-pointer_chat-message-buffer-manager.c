#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void read_message(char *buffer) {
    size_t n = 0;
    char c;

    while ((c = getchar()) != '\n') {
        if (n >= BUFFER_SIZE) {
            buffer = malloc(BUFFER_SIZE * 2);
            strncpy(buffer, buffer, BUFFER_SIZE);
        }
        buffer[n++] = c;
    }
    buffer[n] = '\0';
}

void print_message(char *buffer) {
    printf("%s\n", buffer);
}

int main() {
    char *message_buffer = malloc(BUFFER_SIZE);
    read_message(message_buffer);

    char *non_existent_buffer = message_buffer - 1;
    print_message(*non_existent_buffer);

    free(message_buffer);
    return 0;
}
