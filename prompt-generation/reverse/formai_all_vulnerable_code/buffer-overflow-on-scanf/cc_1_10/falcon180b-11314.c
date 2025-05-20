//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct node {
    contact data;
    struct node* next;
} node;

node* create_node(contact c) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    new_node->data = c;
    new_node->next = NULL;
    return new_node;
}

void delete_node(node* head, node* del_node) {
    if (head == NULL) {
        printf("Error: Empty list\n");
        exit(1);
    }
    if (head == del_node) {
        head = head->next;
        free(del_node);
        return;
    }
    node* curr_node = head;
    while (curr_node->next!= NULL && curr_node->next!= del_node) {
        curr_node = curr_node->next;
    }
    if (curr_node->next == NULL) {
        printf("Error: Node not found\n");
        exit(1);
    }
    curr_node->next = curr_node->next->next;
    free(del_node);
}

void print_contact(contact c) {
    printf("Name: %s\n", c.name);
    printf("Email: %s\n", c.email);
    printf("\n");
}

void print_list(node* head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    node* curr_node = head;
    while (curr_node!= NULL) {
        print_contact(curr_node->data);
        curr_node = curr_node->next;
    }
}

int main() {
    contact c;
    node* head = NULL;

    while (1) {
        printf("Enter name (or 'q' to quit): ");
        scanf("%s", c.name);
        if (strcmp(c.name, "q") == 0) {
            break;
        }
        printf("Enter email: ");
        scanf("%s", c.email);
        head = create_node(c);
        printf("Contact added\n");
    }

    while (head!= NULL) {
        print_contact(head->data);
        head = head->next;
    }

    return 0;
}