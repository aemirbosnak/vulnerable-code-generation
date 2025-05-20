#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void parse_stat(char *response) {
    int count;
    if (sscanf(response, "+OK %d messages", &count) == 1) {
        printf("Number of messages: %d\n", count);
    } else {
        printf("Failed to parse STAT response.\n");
    }
}

void parse_list(char *response) {
    char filename[BUFFER_SIZE];
    while (sscanf(response, "%s", filename) == 1) {
        printf("Filename: %s\n", filename);
        fgets(response, BUFFER_SIZE, stdin); // Simulate reading next line
    }
}

int main() {
    char buffer[BUFFER_SIZE];
    while (1) {
        printf("Enter command (STAT/LIST): ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character

        if (strncmp(buffer, "STAT", 4) == 0) {
            parse_stat(buffer + 5);
        } else if (strncmp(buffer, "LIST", 4) == 0) {
            parse_list(buffer + 5);
        } else {
            printf("Unknown command.\n");
        }
    }

    return 0;
}
