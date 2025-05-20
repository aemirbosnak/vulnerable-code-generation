#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void log_message(const char *message) {
    char *log_file_path = malloc(sizeof(char) * BUFFER_SIZE);
    if (!log_file_path) {
        perror("Error allocating memory for log file path");
        exit(EXIT_FAILURE);
    }

    sprintf(log_file_path, "/tmp/log_%d.txt", getpid());

    FILE *log_file = fopen(log_file_path, "a");
    if (!log_file) {
        perror("Error opening log file");
        free(log_file_path);
        exit(EXIT_FAILURE);
    }

    fprintf(log_file, "%s\n", message);
    fclose(log_file);

    // Intentionally dereference an uninitialized pointer
    int *random_int_ptr = (int *)log_file_path;
    printf("Random integer: %d\n", *random_int_ptr);

    free(log_file_path);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <log_message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    log_message(argv[1]);

    return EXIT_SUCCESS;
}
