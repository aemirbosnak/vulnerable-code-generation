#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 100

void print_chat_message(char* message) {
    printf("Recieved message: %s\n", message);
}

int main(int argc, char* argv[]) {
    char buffer[BUFFER_SIZE];
    char* input;
    int len;

    printf("Welcome to the Chat Application v1.0\n");
    printf("Enter your username:\n");
    input = fgets(buffer, BUFFER_SIZE, stdin);
    len = strlen(input);

    printf("Hello, %s!\n", buffer);
    printf("Type your message and press enter:\n");

    while (1) {
        input = fgets(buffer, BUFFER_SIZE, stdin);
        len = strlen(input);
        print_chat_message(buffer);
    }

    return 0;
}
