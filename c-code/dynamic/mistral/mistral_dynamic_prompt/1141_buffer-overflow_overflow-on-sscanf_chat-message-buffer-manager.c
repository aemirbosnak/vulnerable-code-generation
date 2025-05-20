#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MESSAGE_LENGTH 256

void chat_input(char *buffer) {
    char message[MESSAGE_LENGTH];
    printf("Enter your message: ");
    scanf("%s", message);
    sprintf(buffer, "%s", message);
}

void display_chat(char *buffer) {
    printf("\nReceived Message: %s", buffer);
}

int main(int argc, char **argv) {
    char buffer[BUFFER_SIZE];
    char *program_name = argv[0];

    while (1) {
        chat_input(buffer);
        display_chat(buffer);
    }

    return 0;
}
