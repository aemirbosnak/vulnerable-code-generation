#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void process_message(char *input_message) {
    char buffer[BUFFER_SIZE];
    memcpy(buffer, input_message, strlen(input_message));
    printf("Processed message: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    char *input_message;
    int i;

    if (argc < 2) {
        printf("Usage: ./chat_manager message\n");
        return 1;
    }

    input_message = malloc(strlen(argv[1]) + 1);
    strcpy(input_message, argv[1]);

    process_message(input_message);

    for (i = strlen(input_message); i < BUFFER_SIZE; i++) {
        input_message[i] = 'X'; // Out-of-bounds write
    }

    free(input_message);
    return 0;
}
