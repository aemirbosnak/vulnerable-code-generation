#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

void send_message(char *username, char *message) {
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "|%s|%s|", username, message);
}

void receive_message(char *buffer) {
    char username[32];
    char message[128];
    sscanf(buffer, "|%s|%s|", username, message);
    printf("User: %s\n", username);
    printf("Message: %s\n", message);
}

void main() {
    char input[1024];
    printf("Chat Manager\n");
    printf("Enter message format: |username|message|\n");

    while (1) {
        fgets(input, sizeof(input), stdin);
        send_message("Attacker", input);
        receive_message(input);
    }
}
