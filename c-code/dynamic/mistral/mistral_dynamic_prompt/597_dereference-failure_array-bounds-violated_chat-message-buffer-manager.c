#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[10];
    char msg[256];
    struct node *next;
} node;

node *head = NULL;

void add_message(char* name, char* msg) {
    node *new_node = (node *) malloc(sizeof(node));
    strcpy(new_node->name, name);
    strcpy(new_node->msg, msg);
    new_node->next = head;
    head = new_node;
}

void display_messages() {
    node *temp = head;
    while (temp != NULL) {
        printf("%s: %s\n", temp->name, temp->msg);
        temp = temp->next;
    }
}

int main(int argC, char* argV[]) {
    if (argC < 3) {
        printf("Usage: %s <name> <message>\n", argV[0]);
        return 0;
    }

    add_message(argV[1], argV[2]);
    display_messages();

    char* attacker_input = (char *) malloc(sizeof(char) * 10000);
    strcpy(attacker_input, "\0");

    for (int i = 0; i < 5000; i++) {
        sprintf(attacker_input + i * 256, "A" /* Large chat message */);
    }

    add_message("Attacker", attacker_input);
    display_messages();

    return 0;
}
