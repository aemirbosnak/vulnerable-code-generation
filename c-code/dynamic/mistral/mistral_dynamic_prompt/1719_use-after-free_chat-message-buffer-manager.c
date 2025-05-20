#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *message;
    size_t capacity;
    size_t length;
} ChatMessage;

ChatMessage *create_chat_message(size_t capacity) {
    ChatMessage *msg = (ChatMessage *) malloc(sizeof(ChatMessage));
    msg->message = (char *) malloc(capacity * sizeof(char));
    msg->capacity = capacity;
    msg->length = 0;
    return msg;
}

void append_chat_message(ChatMessage *msg, const char *text) {
    if (msg->length + strlen(text) >= msg->capacity) {
        msg->capacity *= 2;
        msg->message = realloc(msg->message, msg->capacity * sizeof(char));
    }
    strcat(msg->message, text);
    msg->length += strlen(text);
}

void print_chat_message(const ChatMessage *msg) {
    printf("%s\n", msg->message);
}

void destroy_chat_message(ChatMessage *msg) {
    free(msg->message);
    free(msg);
}

int main() {
    ChatMessage *msg1 = create_chat_message(10);
    append_chat_message(msg1, "Hello, World!");
    append_chat_message(msg1, "This is my first message!");
    print_chat_message(msg1);

    ChatMessage *msg2 = create_chat_message(5);
    append_chat_message(msg2, "Hello!");
    free(msg1);
    append_chat_message(msg2, msg1->message);
    print_chat_message(msg2);

    destroy_chat_message(msg2);

    return 0;
}
