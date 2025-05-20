#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

void process_message(char *message) {
    char buffer[BUFFER_SIZE];
    int id;
    float value;

    if (sscanf(message, "%d %f", &id, &value) != 2) {
        printf("Invalid input format\n");
        return;
    }

    snprintf(buffer, sizeof(buffer), "ID: %d, Value: %.2f", id, value);
    printf("%s\n", buffer);
}

int main() {
    char input[100];

    while (1) {
        printf("Enter a message (format: ID value): ");
        fgets(input, sizeof(input), stdin);

        // Remove newline character
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        process_message(input);
    }

    return 0;
}
