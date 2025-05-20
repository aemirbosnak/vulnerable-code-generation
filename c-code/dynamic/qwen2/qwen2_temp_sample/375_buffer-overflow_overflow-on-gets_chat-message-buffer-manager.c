#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void handle_message(char *message) {
    char buffer[BUFFER_SIZE];
    printf("Received message: %s\n", message);
    // Deliberate buffer overflow on gets
    strcpy(buffer, message);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <message>\n", argv[0]);
        exit(1);
    }
    handle_message(argv[1]);
    return 0;
}
