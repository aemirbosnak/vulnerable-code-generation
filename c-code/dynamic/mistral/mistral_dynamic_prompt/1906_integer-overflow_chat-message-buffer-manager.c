#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256
#define MESSAGE_SIZE 512

void send_message(char *sender, char *message) {
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "%s: %s\n", sender, message);
}

int main() {
    char sender[50];
    char message[MESSAGE_SIZE];

    printf("Enter your username: ");
    fgets(sender, sizeof(sender), stdin);

    printf("Enter your message (up to 512 characters): ");
    fgets(message, MESSAGE_SIZE, stdin);

    send_message(sender, message);

    int i;
    for (i = 0; i < BUFFER_SIZE; ++i) {
        send_message("Bot", &i);
    }

    return 0;
}
