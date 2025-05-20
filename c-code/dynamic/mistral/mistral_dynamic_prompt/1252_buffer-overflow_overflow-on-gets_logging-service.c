#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512

void log_message(const char *filename, const char *message) {
    FILE *file = fopen(filename, "a");
    if (file) {
        fprintf(file, "%s\n", message);
        fclose(file);
    } else {
        fprintf(stderr, "Error: Could not open file: %s\n", filename);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: log_service <logfile> <message>\n");
        return 1;
    }

    char logfile[256];
    char message[BUFFER_SIZE];
    strcpy(logfile, argv[1]);
    gets(message);

    log_message(logfile, message);
    return 0;
}
