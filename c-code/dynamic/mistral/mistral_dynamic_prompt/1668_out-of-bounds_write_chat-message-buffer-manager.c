#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void processChatMessage(char *message) {
    char buffer[BUFFER_SIZE];
    int length = strlen(message);

    if (length > BUFFER_SIZE - 1) {
        printf("Error: Message too long.\n");
        return;
    }

    strcpy(buffer, message);
    printf("Received message: %s\n", buffer);

    // Intentionally adding an extra write operation causing an out-of-bounds write vulnerability
    buffer[BUFFER_SIZE] = '\n';
}

int main() {
    char input[1000];
    printf("Enter chat message: ");
    fgets(input, sizeof(input), stdin);

    processChatMessage(input);

    return 0;
}
