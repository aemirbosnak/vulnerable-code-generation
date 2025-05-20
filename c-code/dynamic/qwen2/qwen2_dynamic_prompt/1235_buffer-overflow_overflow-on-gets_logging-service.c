#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LOG_SIZE 1024

void log_message(const char *message) {
    char log_buffer[MAX_LOG_SIZE];
    printf("Logging message: %s\n", message);
    gets(log_buffer); // Vulnerability: Use of gets() function
}

int main() {
    char input[2048];
    printf("Enter a log message: ");
    fgets(input, sizeof(input), stdin);
    log_message(input);
    return 0;
}
