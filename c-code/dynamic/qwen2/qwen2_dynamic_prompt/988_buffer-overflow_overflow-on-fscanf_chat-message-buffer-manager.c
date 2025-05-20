#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void process_message(char *buffer) {
    char message[BUFFER_SIZE];
    printf("Enter your message: ");
    if (fscanf(stdin, "%s", message) != 1) {
        fprintf(stderr, "Failed to read input\n");
        return;
    }
    // Vulnerability: No bounds checking on fscanf
    strcpy(buffer, message);
}

int main() {
    char buffer[BUFFER_SIZE];
    while (1) {
        process_message(buffer);
        printf("Buffer content: %s\n", buffer);
    }
    return 0;
}
