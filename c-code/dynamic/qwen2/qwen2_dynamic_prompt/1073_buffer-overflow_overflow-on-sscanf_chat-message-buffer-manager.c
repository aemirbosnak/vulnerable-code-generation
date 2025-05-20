#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

char buffer[BUFFER_SIZE];

void receive_message(const char* message) {
    if (strlen(message) >= BUFFER_SIZE) {
        printf("Message too long!\n");
        return;
    }
    strcpy(buffer, message);
}

int main() {
    char input[256];
    while (1) {
        printf("Enter a message: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        receive_message(input);
        printf("Buffer content: %s\n", buffer);
    }
    return 0;
}
