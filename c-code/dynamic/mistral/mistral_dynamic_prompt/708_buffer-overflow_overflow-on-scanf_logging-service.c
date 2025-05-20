#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LOG_SIZE 1000

void log_message(char *message) {
    static char log_buffer[MAX_LOG_SIZE];
    strcpy(log_buffer, message);
    printf("Logged: %s\n", log_buffer);
}

int main(int argc, char *argv[]) {
    char input[10];

    printf("Enter log message (up to 10 characters): ");
    scanf("%s", input);

    log_message(input);

    return 0;
}
