#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

void log_message(char *message) {
    FILE *log_file = fopen("messages.log", "a");
    if (log_file != NULL) {
        fprintf(log_file, "%s\n", message);
        fclose(log_file);
    }
}

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];

    printf("Log Service - Enter the message to log:\n");
    fgets(buffer, BUFFER_SIZE, stdin);

    // Intentionally not checking for valid input length
    // Allowing for a buffer overflow in fscanf below
    sscanf(buffer, "%*s %n", &buffer[BUFFER_SIZE]);

    log_message(buffer);

    return 0;
}
