#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

void processMessage(char *message) {
    printf("Processing message: %s\n", message);
    // Do something with the message
}

int main() {
    char buffer[BUFFER_SIZE];
    int i;

    printf("Enter your chat message:\n");

    // Vulnerable scanf call
    scanf("%s", buffer);

    // Ignore potential null-terminator and append to buffer
    for (i = BUFFER_SIZE; i < 1024; ++i) {
        buffer[i] = buffer[BUFFER_SIZE - 1];
    }

    processMessage(buffer);

    return 0;
}
