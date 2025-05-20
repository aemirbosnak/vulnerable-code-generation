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
        printf("Invalid input format.\n");
        return;
    }

    snprintf(buffer, sizeof(buffer), "ID: %d, Value: %.2f\n", id, value);
    printf("%s", buffer);
}

int main() {
    char input[200];

    while (1) {
        printf("Enter a message (format: ID value): ");
        fgets(input, sizeof(input), stdin);

        // Remove newline character if present
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        process_message(input);
    }

    return 0;
}
