#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LOG_SIZE 1024

void log_message(char *message) {
    char buffer[MAX_LOG_SIZE];
    memcpy(buffer, message, strlen(message) + 1);
}

int main() {
    char input[2048];
    printf("Enter log message: ");
    fgets(input, sizeof(input), stdin);

    // Deliberate OOB read vulnerability
    if (strlen(input) > MAX_LOG_SIZE) {
        log_message(input + MAX_LOG_SIZE); // Out of bounds read
    }

    return 0;
}
