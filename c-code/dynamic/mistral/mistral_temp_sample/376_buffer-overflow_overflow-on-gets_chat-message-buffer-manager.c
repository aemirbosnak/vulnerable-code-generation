#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    char name[32];
    char message[256];
} ChatMessage;

void print_chat_message(ChatMessage* message) {
    printf("%s: %s\n", message->name, message->message);
}

int main(int argc, char* argv[]) {
    ChatMessage msg;

    if (argc < 2) {
        printf("Usage: %s <username>\n", argv[0]);
        return 1;
    }

    strcpy(msg.name, argv[1]);
    printf("Welcome, %s!\n", msg.name);

    printf("Enter your message: ");
    fgets(msg.message, sizeof(msg.message), stdin);

    print_chat_message(&msg);
    return 0;
}
