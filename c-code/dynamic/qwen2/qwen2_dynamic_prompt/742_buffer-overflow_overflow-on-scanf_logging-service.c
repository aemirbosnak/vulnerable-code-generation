#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define LOG_FILE "log.txt"

void log_message(const char* message) {
    FILE* file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        printf("Failed to open log file.\n");
        return;
    }
    fprintf(file, "%s\n", message);
    fclose(file);
}

int main() {
    char buffer[10];
    printf("Enter a log message: ");
    scanf("%s", buffer); // Vulnerable to buffer overflow

    log_message(buffer);

    printf("Log message saved to %s\n", LOG_FILE);
    return 0;
}
