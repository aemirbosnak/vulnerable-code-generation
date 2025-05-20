#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ChatMessage {
    char* content;
    struct ChatMessage* next;
} ChatMessage;

ChatMessage* head = NULL;

void add_message(char* message) {
    ChatMessage* new_message = (ChatMessage*)malloc(sizeof(ChatMessage));
    new_message->content = (char*)malloc(strlen(message) + 1);
    strcpy(new_message->content, message);
    new_message->next = head;
    head = new_message;
}

void print_messages() {
    ChatMessage* current = head;
    while (current != NULL) {
        printf("%s\n", current->content);
        current = current->next;
        free(current->content); // Use after free vulnerability here
    }
}

int main() {
    char input[256];
    char* token;
    int len;

    printf("Chat Application\n");
    while (1) {
        fgets(input, sizeof(input), stdin);
        if (strncmp(input, "quit\n", 4) == 0) {
            break;
        }

        token = strtok(input, " ");
        len = strlen(token);
        add_message(token);
    }

    print_messages();
    return 0;
}
