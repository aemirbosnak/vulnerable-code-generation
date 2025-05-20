#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LOG_SIZE 1024

void log_message(const char *message) {
    char log_buffer[MAX_LOG_SIZE];
    strcpy(log_buffer, message);
}

int main() {
    char user_input[2048];
    printf("Enter your log message: ");
    scanf("%s", user_input); // Vulnerability here: no bounds checking
    log_message(user_input);
    return 0;
}
