#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define LOG_FILE "service.log"

void log_message(char* message) {
    FILE* file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Failed to open log file");
        exit(1);
    }
    fprintf(file, "%s\n", message);
    fclose(file);
}

int main() {
    char* msg = "Service started";
    log_message(msg);

    // Dereference failure example
    int* ptr = NULL;
    *ptr = 42; // This will cause a segmentation fault

    char* another_msg = "Error occurred";
    log_message(another_msg);

    return 0;
}
