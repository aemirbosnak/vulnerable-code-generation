#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LOG_SIZE 1024

void log_message(const char *message) {
    char buffer[MAX_LOG_SIZE];
    if (sscanf(message, "%s", buffer) != 1) {
        fprintf(stderr, "Error parsing message\n");
        return;
    }
    printf("Logged: %s\n", buffer);
}

int main() {
    char input[2048];
    printf("Enter log message: ");
    fgets(input, sizeof(input), stdin);
    log_message(input);
    return 0;
}
