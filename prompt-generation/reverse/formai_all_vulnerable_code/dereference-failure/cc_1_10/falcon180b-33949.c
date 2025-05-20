//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct node {
    char data[MAX];
    struct node *next;
} Node;

Node *head = NULL;

void add_node(char *str) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    Node *temp = head;
    strcpy(new_node->data, str);
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_list() {
    Node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        while (temp!= NULL) {
            printf("%s -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void delete_node(char *str) {
    Node *temp = head;
    Node *prev = NULL;
    while (temp!= NULL && strcmp(temp->data, str)!= 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found.\n");
    } else if (temp == head) {
        head = temp->next;
        free(temp);
    } else {
        prev->next = temp->next;
        free(temp);
    }
}

void search_node(char *str) {
    Node *temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->data, str) == 0) {
            printf("%s found at position %d.\n", str, temp->data - head->data);
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found.\n");
    }
}

void reverse_list() {
    Node *prev = NULL;
    Node *next = NULL;
    Node *temp = head;
    while (temp!= NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
}

int main() {
    add_node("apple");
    add_node("banana");
    add_node("cherry");
    add_node("durian");
    print_list();
    delete_node("banana");
    print_list();
    search_node("cherry");
    reverse_list();
    print_list();
    return 0;
}