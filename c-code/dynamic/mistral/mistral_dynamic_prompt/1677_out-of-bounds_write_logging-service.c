#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void unsafe_log(char *message, int size) {
    char log_buffer[10];
    if (strlen(message) < 10) {
        strcpy(log_buffer, message);
        printf("Logged message: %s\n", log_buffer);
    } else {
        printf("Error: Message too long to log.\n");
    }
}

int main() {
    char input[256];
    printf("Enter a log message (up to 10 characters): ");
    fgets(input, 256, stdin);
    unsafe_log(input, 10);
    return 0;
}
