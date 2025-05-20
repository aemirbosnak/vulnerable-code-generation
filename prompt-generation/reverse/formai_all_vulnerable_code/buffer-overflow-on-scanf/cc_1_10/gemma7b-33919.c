//Gemma-7B DATASET v1.0 Category: System administration ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

typedef struct Node {
    char name[256];
    struct Node* next;
} Node;

Node* head = NULL;

void addNode(char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void listNodes() {
    Node* temp = head;
    printf("List of nodes:\n");
    while (temp) {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}

int main() {
    char cmd[MAX_CMD_LEN];

    printf("Welcome to the C System Administration Interface!\n");
    printf("Please enter a command (help for list of commands): ");

    scanf("%s", cmd);

    if (strcmp(cmd, "add") == 0) {
        printf("Enter the name of the new node: ");
        char name[256];
        scanf("%s", name);
        addNode(name);
    } else if (strcmp(cmd, "list") == 0) {
        listNodes();
    } else if (strcmp(cmd, "exit") == 0) {
        printf("Goodbye!\n");
        exit(0);
    } else {
        printf("Invalid command.\n");
    }

    main();
}