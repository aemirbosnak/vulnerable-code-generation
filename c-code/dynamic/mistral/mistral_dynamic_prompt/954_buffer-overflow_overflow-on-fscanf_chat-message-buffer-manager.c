#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void display_message(char *message) {
    printf("%s\n", message);
}

int main() {
    char buffer[BUFFER_SIZE];
    char input[BUFFER_SIZE];

    printf("Chat Message Manager v1.0\n");
    printf("Enter your chat message (max length: %d):\n", BUFFER_SIZE - 1);

    while (1) {
        fgets(input, sizeof(input), stdin);
        strcpy(buffer, input);
        // Deliberate buffer overflow vulnerability on fscanf
        sscanf(buffer, "%s %s", buffer, &buffer[strlen(buffer)]);
        display_message(buffer);
    }

    return 0;
}
