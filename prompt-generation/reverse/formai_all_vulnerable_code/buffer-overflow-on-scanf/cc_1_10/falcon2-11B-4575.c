//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int value;
    struct Node* next;
} Node;

Node* getNode(char* name, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->name = strdup(name);
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    while (head!= NULL) {
        printf("%s - %d\n", head->name, head->value);
        head = head->next;
    }
}

void deleteList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        Node* temp = current->next;
        free(current->name);
        free(current);
        current = temp;
    }
}

int main() {
    Node* head = NULL;
    char name[100];
    int value;

    printf("Enter the name of the item: ");
    scanf("%s", name);

    printf("Enter the value of the item: ");
    scanf("%d", &value);

    Node* newNode = getNode(name, value);

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("The item has been added to the list.\n");
    printList(head);

    printf("Do you want to delete the item? (y/n): ");
    char response;
    scanf(" %c", &response);

    if (response == 'y') {
        deleteList(head);
        printf("The item has been deleted from the list.\n");
    } else {
        printf("The item has not been deleted.\n");
    }

    return 0;
}