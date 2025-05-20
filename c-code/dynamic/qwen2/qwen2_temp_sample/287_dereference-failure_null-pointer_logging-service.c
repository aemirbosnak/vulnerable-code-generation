#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define LOG_FILE "log.txt"

void log_message(const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        printf("Failed to open log file.\n");
        return;
    }
    
    fprintf(file, "%s\n", message);
    fclose(file);
}

void critical_error() {
    int *ptr = NULL;
    int value = *ptr; // Dereference null pointer
}

int main() {
    log_message("Application started.");
    
    critical_error();
    
    log_message("Critical error occurred.");
    return 1;
}
