#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void process_message(char *message) {
    char chat_buffer[BUFFER_SIZE];
    printf("Processing message: %s\n", message);
    strncpy(chat_buffer, message, BUFFER_SIZE);
    printf("After copying: %s\n", chat_buffer);
}

int main(int argc, char *argv[]) {
    int i;
    if (argc != 2) {
        printf("Usage: ./chat_buffer <message>\n");
        return 1;
    }

    process_message(argv[1]);

    printf("Let's add more data to the buffer\n");
    for (i = 0; i < BUFFER_SIZE * 3; ++i) {
        process_message(argv[1]);
    }

    return 0;
}
