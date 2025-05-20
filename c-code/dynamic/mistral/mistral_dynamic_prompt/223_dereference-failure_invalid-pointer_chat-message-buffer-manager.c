#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

typedef struct {
    char *message;
    struct Node *next;
} Node;

Node *head = NULL;

void addMessage(char *message) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->message = message;
    newNode->next = head;
    head = newNode;
}

void displayMessages() {
    Node *current = head;
    while (current != NULL) {
        printf("%s\n", current->message);
        current = current->next;
    }
}

int main() {
    addMessage("Hello, World!");
    addMessage("Let's start the chat!");

    char userMessage[BUFFER_SIZE];
    printf("Enter a message: ");
    fgets(userMessage, BUFFER_SIZE, stdin);

    addMessage(userMessage); // Here we have a potential dereference failure as userMessage is not NULL terminated

    displayMessages();

    Node *current = head;
    while (current != NULL) {
        Node *toDelete = current;
        current = current->next;
        free(toDelete->message);
        free(toDelete);
    }

    return 0;
}
