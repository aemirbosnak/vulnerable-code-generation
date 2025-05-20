#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define LOG_FILE "app.log"

void log_message(const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        fprintf(stderr, "Failed to open log file\n");
        return;
    }
    fprintf(file, "%s\n", message);
    fclose(file);
}

int main() {
    char buffer[10];
    printf("Enter your log message: ");
    scanf("%s", buffer); // Vulnerability here
    log_message(buffer);
    printf("Log message saved to %s\n", LOG_FILE);
    return 0;
}
