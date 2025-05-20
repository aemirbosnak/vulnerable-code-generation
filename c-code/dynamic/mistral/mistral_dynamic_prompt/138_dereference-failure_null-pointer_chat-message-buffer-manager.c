#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGES 10
#define BUFFER_SIZE 256

typedef struct Message {
    char message[BUFFER_SIZE];
} Message;

Message chat_messages[MAX_MESSAGES];
int messages_count = 0;

void print_messages() {
    if (messages_count == 0) {
        printf("No messages yet.\n");
        return;
    }

    for (int i = 0; i < messages_count; ++i) {
        printf("Message %d: %s\n", i + 1, chat_messages[i].message);
    }
}

void add_message(const char* message) {
    if (messages_count >= MAX_MESSAGES) {
        printf("Buffer full. Cannot add message.\n");
        return;
    }

    strcpy(chat_messages[messages_count].message, message);
    ++messages_count;
}

void process_new_message(const char* sender, const char* message) {
    if (sender == NULL || message == NULL) {
        printf("Error: invalid sender or message.\n");
        return;
    }

    char temp_message[BUFFER_SIZE];
    snprintf(temp_message, BUFFER_SIZE, "%s: %s\n", sender, message);
    add_message(temp_message);
}

int main() {
    process_new_message(NULL, "Hello, World!"); // Intentionally dereferencing NULL pointer in process_new_message function
    print_messages();

    return 0;
}
