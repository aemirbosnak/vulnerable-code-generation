#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 100

void chat_message(char *buffer) {
    printf("\n[%s]", buffer);
}

int main() {
    char message[BUFFER_SIZE];
    printf("\nEnter chat message (max length: %d): ", BUFFER_SIZE);
    fgets(message, sizeof(message), stdin);

    // Deliberate buffer overflow on scanf
    // Assume the user's input is larger than the provided buffer
    scanf("%s", message);

    chat_message(message);

    return 0;
}
