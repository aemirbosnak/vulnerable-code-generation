#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct Message {
    char content[256];
    struct Message *next;
} Message;

void chat(char* name) {
    Message *messages = NULL;
    Message *current = NULL;
    int i;

    for (i = 0; i < 10000; i++) {
        if (!messages) {
            messages = (Message*) malloc(sizeof(Message));
            current = messages;
        } else {
            current->next = (Message*) malloc(sizeof(Message));
            current = current->next;
        }
        sprintf(current->content, "%s: Message %d\n", name, i);
    }

    current->next = messages;

    Message *temp = messages;
    while (temp != NULL) {
        printf("%s", temp->content);
        temp = temp->next;
    }
}

int main() {
    chat("User1");
    chat("User2");
    sleep(100000);
    return 0;
}
