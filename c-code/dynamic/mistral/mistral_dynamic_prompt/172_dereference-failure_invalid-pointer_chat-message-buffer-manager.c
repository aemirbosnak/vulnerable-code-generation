#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void process_message(char* message) {
    char *token, buffer[BUFFER_SIZE];
    int i = 0;

    token = strtok(message, ": ");
    if (token != NULL) {
        strcpy(buffer, token);

        token = strtok(NULL, ": ");
        if (token != NULL) {
            i = atoi(token);

            // Invalid pointer dereference vulnerability
            printf("%s's message: %s\n", buffer, buffer[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    char input[1000];

    printf("Chat Message Buffer Manager\n");
    printf("Enter message in format: name: message\n");

    while (1) {
        fgets(input, sizeof(input), stdin);
        process_message(input);
    }

    return 0;
}
