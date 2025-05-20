#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *message;
    struct chat_t *next;
} chat_t;

chat_t *head = NULL;

void add_message(char *msg) {
    chat_t *new_msg = (chat_t *) malloc(sizeof(chat_t));
    new_msg->message = msg;
    new_msg->next = head;
    head = new_msg;
}

int main() {
    char input[10];
    printf("Enter a message (10 characters or less): ");
    scanf("%s", input);

    add_message(input);

    char *dummy = NULL;
    dummy = head->message;
    printf("Last message: %s\n", dummy);

    return 0;
}
