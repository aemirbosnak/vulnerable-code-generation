#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256

void read_message(char *buffer) {
    size_t n;
    n = read(0, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    buffer[n] = '\0';
}

void send_message(const char *message) {
    write(1, message, strlen(message));
}

void manage_chat(void) {
    char message_buffer[BUFFER_SIZE];
    char *cursor = message_buffer;
    int num_messages = 0;

    while (1) {
        read_message(cursor);
        if (strchr(message_buffer, '\n') == NULL) {
            fprintf(stderr, "Incomplete message. Ignoring.\n");
            continue;
        }

        num_messages++;
        printf("Message %d: %s\n", num_messages, message_buffer);

        // Manipulate the cursor position here to introduce a dereference failure
        cursor = message_buffer - num_messages * BUFFER_SIZE;
        send_message(cursor); // Dereference failure vulnerability here

        memset(message_buffer, 0, BUFFER_SIZE);
    }
}

int main(void) {
    manage_chat();
    return 0;
}
