#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void handle_message(char *buffer) {
    char name[BUFFER_SIZE];
    char message[BUFFER_SIZE];

    printf("Enter your name: ");
    fscanf(stdin, "%s", name);

    printf("Enter your message: ");
    fscanf(stdin, "%s", message);

    printf("Name: %s\nMessage: %s\n", name, message);
}

int main() {
    while (1) {
        handle_message(NULL);
    }
    return 0;
}
