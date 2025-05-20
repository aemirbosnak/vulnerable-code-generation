#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void handle_message(char *client_message) {
    char chat_buffer[BUFFER_SIZE];
    strcpy(chat_buffer, "Welcome to SecureChat! Your message: ");
    strcat(chat_buffer, client_message);
    printf("%s\n", chat_buffer);
}

int main(int argc, char *argv[]) {
    char input[BUFFER_SIZE];

    printf("Enter your message (up to %d characters): ", BUFFER_SIZE);
    fgets(input, BUFFER_SIZE, stdin);

    handle_message(input);

    return 0;
}
