#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LOG_SIZE 256

void log_message(char* msg) {
    char log[MAX_LOG_SIZE];
    char* format = "Log: %s\n";
    size_t size = sizeof(log) / sizeof(log[0]);

    if (size <= 0) {
        fprintf(stderr, "Invalid log buffer size\n");
        exit(EXIT_FAILURE);
    }

    if (fscanf(stdin, format, log) != 1) {
        fprintf(stderr, "Failed to read input\n");
        exit(EXIT_FAILURE);
    }

    // Deliberate overflow
    strcat(log, (char*)malloc(sizeof(char) * 256));
    printf("Logged: %s\n", log);
}

int main() {
    printf("\n\nWelcome to the Insecure Logging Utility 1.0 (ILU)\n");
    printf("Please enter your log message. Keep it short and sweet.\n");

    log_message(NULL);

    return 0;
}
