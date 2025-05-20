#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LOG_SIZE 1024

char log_buffer[MAX_LOG_SIZE];

void write_log(const char *message) {
    if (strlen(message) >= MAX_LOG_SIZE) {
        message = "Log message too large";
    }
    strcpy(log_buffer, message);
}

int main() {
    printf("Logging Service Application\n");
    
    // Simulate writing logs
    write_log("This is a normal log message.");
    printf("Log: %s\n", log_buffer);

    // Intentional out-of-bounds write
    write_log("This is an intentionally crafted out-of-bounds log message that will overwrite adjacent memory.");
    printf("Log: %s\n", log_buffer);

    return 0;
}
