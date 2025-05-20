//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

struct node {
    char name[SIZE];
    int age;
    struct node *next;
};

struct node *head = NULL;

void addNode(char name[], int age) {
    struct node *node = (struct node*)malloc(sizeof(struct node));
    strcpy(node->name, name);
    node->age = age;
    node->next = NULL;
    if (head == NULL) {
        head = node;
    }
    else {
        struct node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

struct node* search(char name[]) {
    struct node *temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void printList() {
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%s %d\n", temp->name, temp->age);
        temp = temp->next;
    }
}

int main() {
    addNode("John", 25);
    addNode("Jane", 30);
    addNode("Bob", 20);
    addNode("Alice", 28);
    printList();
    struct node *result = search("Jane");
    if (result!= NULL) {
        printf("Found %s with age %d\n", result->name, result->age);
    }
    else {
        printf("Not found\n");
    }
    return 0;
}