#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void process_message(char *buffer) {
    char name[20], message[BUFFER_SIZE];
    int age;

    sscanf(buffer, "%s %s %d", name, message, &age);

    printf("Name: %s\nMessage: %s\nAge: %d\n", name, message, age);
}

int main() {
    char chat_buffer[1024];

    while (1) {
        printf("Enter a chat message (in the format: Name Message Age): ");
        fgets(chat_buffer, sizeof(chat_buffer), stdin);

        process_message(chat_buffer);
    }

    return 0;
}
