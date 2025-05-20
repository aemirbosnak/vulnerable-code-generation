#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define MAX_MESSAGES 10
#define MESSAGE_LENGTH 256

typedef struct {
    char message[MESSAGE_LENGTH];
    char username[32];
} ChatMessage;

ChatMessage messages[MAX_MESSAGES];
int num_messages = 0;

void add_message(const char *username, const char *message) {
    if (num_messages >= MAX_MESSAGES) {
        printf("Error: Maximum number of messages reached.\n");
        return;
    }

    strcpy(messages[num_messages].message, message);
    strcpy(messages[num_messages].username, username);
    num_messages++;
}

void print_messages() {
    for (int i = 0; i < num_messages; i++) {
        printf("%s (%s): %s\n", messages[i].username, messages[i].message);
    }
}

int main() {
    char input_username[32];
    char input_message[MESSAGE_LENGTH];

    while (1) {
        printf("\nEnter your username: ");
        fgets(input_username, sizeof(input_username), stdin);

        printf("Enter your message: ");
        fgets(input_message, sizeof(input_message), stdin);

        add_message(input_username, input_message);

        printf("\nMessages:\n");
        print_messages();
    }

    return 0;
}
