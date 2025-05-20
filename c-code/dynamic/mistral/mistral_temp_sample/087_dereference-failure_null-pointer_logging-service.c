#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1024

void log_message(char *log_file, char *message) {
    FILE *file = fopen(log_file, "a");
    if (file == NULL) {
        printf("Error: Unable to open log file.\n");
        return;
    }

    char log_entry[MAX_LOG_SIZE];
    snprintf(log_entry, sizeof(log_entry), "%s\n", message);
    fputs(log_entry, file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <log_file> <message>\n", argv[0]);
        return 1;
    }

    char *log_file = argv[1];
    char *message = argv[2];

    log_message(log_file, message);

    char *null_ptr = NULL;
    printf("Logged message: %s\n", null_ptr[0]); // Dereference null pointer

    return 0;
}
