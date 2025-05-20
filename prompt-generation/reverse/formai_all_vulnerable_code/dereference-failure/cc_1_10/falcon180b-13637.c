//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    char name[MAX_SIZE];
    int age;
    struct node* next;
};

struct node* createNode(char name[], int age) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->next = NULL;
    return newNode;
}

struct node* insertNode(struct node* head, char name[], int age) {
    struct node* newNode = createNode(name, age);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    struct node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct node* searchNode(struct node* head, char name[]) {
    struct node* temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void deleteNode(struct node* head, char name[]) {
    struct node* temp = head;
    struct node* prev = NULL;
    while (temp!= NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (prev == NULL) {
                head = temp->next;
                free(temp);
                return;
            }
            prev->next = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void printList(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%s %d\n", temp->name, temp->age);
        temp = temp->next;
    }
}

int main() {
    struct node* head = NULL;
    head = insertNode(head, "John", 25);
    head = insertNode(head, "Jane", 30);
    head = insertNode(head, "Bob", 20);
    head = insertNode(head, "Alice", 28);

    printf("Original list:\n");
    printList(head);

    struct node* foundNode = searchNode(head, "Bob");
    if (foundNode!= NULL) {
        printf("Found node: %s %d\n", foundNode->name, foundNode->age);
    } else {
        printf("Node not found.\n");
    }

    deleteNode(head, "Bob");

    printf("List after deleting Bob:\n");
    printList(head);

    return 0;
}