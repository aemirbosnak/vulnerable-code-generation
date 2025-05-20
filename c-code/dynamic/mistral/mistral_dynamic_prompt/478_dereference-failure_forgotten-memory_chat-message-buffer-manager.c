#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LENGTH 1024

typedef struct ChatMsg {
    char message[MAX_MSG_LENGTH];
    struct ChatMsg *next;
} ChatMsg;

ChatMsg* create_chat_msg(char* msg) {
    ChatMsg* new_msg = (ChatMsg*) malloc(sizeof(ChatMsg));
    strcpy(new_msg->message, msg);
    new_msg->next = NULL;
    return new_msg;
}

void print_chat_msgs(ChatMsg* head) {
    ChatMsg* current = head;
    while (current != NULL) {
        printf("%s\n", current->message);
        current = current->next;
    }
}

int main() {
    ChatMsg* chat_msgs = NULL;
    char input[MAX_MSG_LENGTH];

    while (1) {
        printf("Enter a chat message (or type 'exit' to quit): ");
        fgets(input, MAX_MSG_LENGTH, stdin);

        if (strncmp(input, "exit\n", 5) == 0) {
            break;
        }

        chat_msgs = create_chat_msg(input);
    }

    print_chat_msgs(chat_msgs);

    ChatMsg* current = chat_msgs;
    while (current != NULL) {
        ChatMsg* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
