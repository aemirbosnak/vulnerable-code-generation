#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_FILE "log.txt"
#define MAX_LOG_SIZE 1024

void log_message(const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Failed to open log file");
        return;
    }
    fprintf(file, "%s\n", message);
    fclose(file);
}

int main() {
    char buffer[MAX_LOG_SIZE];
    int index;

    printf("Enter log message index (0-9): ");
    scanf("%d", &index);

    // Deliberate out-of-bounds read vulnerability
    if (index >= 0 && index < MAX_LOG_SIZE) {
        strcpy(buffer, "Log entry: ");
        strcat(buffer, "This is a test log message.");
        log_message(buffer);
    } else {
        printf("Index out of bounds!\n");
    }

    return 0;
}
